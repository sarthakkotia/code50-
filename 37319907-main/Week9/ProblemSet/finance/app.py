import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    cash = db.execute("SELECT cash FROM users WHERE id=?", session["user_id"])[0]
    history = db.execute("SELECT * FROM history WHERE user_id=?", session["user_id"])
    t = 0
    for entry in history:
        t = t+(float(entry["Quantity"]) * float(entry["Price"]))
    t = t + float(cash["cash"])
    portfolio = db.execute("SELECT * FROM portfolio WHERE user_id=?", session["user_id"])
    return render_template("index.html", cash=cash, history=history, total=t, portfolio=portfolio)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    if request.method == "GET":
        return render_template("buy.html", text=session["user_id"])
    else:
        symbol = request.form.get("symbol")
        inf = lookup(symbol)
        if inf == None:
            return apology("Invalid Symbol", 400)
        shares = str(request.form.get("shares"))
        if "." in shares:
            return apology("Shares must be an integar", 400)
        if shares.isalpha() == True:
            return apology("Shares must be an integar", 400)
        shares = int(request.form.get("shares"))
        if shares <= 0:
            return apology("Shares must be a positive number", 400)
        price = float(lookup(symbol)["price"])
        # return render_template("test.html",text=lookup(symbol))
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = float(cash[0]["cash"])
        if price > cash:
            return apology("Payment Declined-Not enough amount", 401)
        else:
            cash = cash-price*shares
            db.execute("UPDATE users SET cash = ? WHERE id = ? ", cash, session["user_id"])
            # update the history table in database
            db.execute("INSERT INTO history(user_id,Symbol,Description,Price,Quantity) VALUES(?,?,?,?,?)",
                       session["user_id"], lookup(symbol)["symbol"], lookup(symbol)["name"], lookup(symbol)["price"], shares)
            db.execute("INSERT INTO portfolio(user_id,symbol,description,price,quantity) VALUES(?,?,?,?,?)",
                       session["user_id"], lookup(symbol)["symbol"], lookup(symbol)["name"], lookup(symbol)["price"], shares)

            return redirect("/")

    """Buy shares of stock"""


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT * FROM history WHERE user_id =? ORDER BY Time DESC", session["user_id"])
    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")
        inf = lookup(symbol)
        if inf == None:
            return apology("Invalid Symbol", 400)

        return render_template("quoted.html", text=inf)
    """Get stock quote."""
    return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        # that means it's coming for the first time
        return render_template("register.html")
    else:
        # this means that the user has come after submitting a username and password
        username = request.form.get("username")
        a = {"username": username}
        users = db.execute("SELECT username FROM users")
        if a in users:
            # already registeread / username already taken
            return apology("Username already exists!", 400)
        if not request.form.get("username"):
            return apology("must provide username", 400)
            # user didn't put anything in the username

        password = str(request.form.get("password"))
        confirmpassword = str(request.form.get("confirmation"))
        if not request.form.get("password"):
            return apology("must provide password", 400)
        elif password != confirmpassword:
            return apology("Passwords do not match!", 400)

        hash = generate_password_hash(password, method='pbkdf2:sha256', salt_length=8)
        db.execute("INSERT INTO users (username,hash) VALUES(?, ?)", username, hash)
        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        options = db.execute("SELECT Symbol FROM portfolio WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", options=options)
    else:
        symbol = request.form.get("symbol")
        sharenum = int(request.form.get("shares"))
        shares = int(db.execute("SELECT Quantity FROM history WHERE user_id = ? AND Symbol = ?",
                                session["user_id"], symbol)[0]["Quantity"])
        if sharenum > shares:
            return apology("Not Enough Shares", 400)
        # left shares by user
        # return render_template("test.html",balance=shares)
        shares = shares - sharenum
        cash = float(db.execute("SELECT cash FROM users WHERE id=?", session["user_id"])[0]["cash"])
        price = float(lookup(symbol)["price"])
        cash = cash + (sharenum*price)
        # update the users cash
        db.execute("UPDATE users SET cash=? WHERE id=?", cash, session["user_id"])
        # update history so that the suer may see that the share has been sold that is negative quantity
        db.execute("INSERT INTO history(user_id,Symbol,Description,Price,Quantity) VALUES(?,?,?,?,?)",
                   session["user_id"], lookup(symbol)["symbol"], lookup(symbol)["name"], lookup(symbol)["price"], -sharenum)
        db.execute("UPDATE portfolio SET quantity=? WHERE user_id=? AND Symbol=?",
                   shares, session["user_id"], lookup(symbol)["symbol"])
        dataremove = int(db.execute("SELECT quantity FROM portfolio WHERE user_id=?", session["user_id"])[0]["quantity"])
        # if quantity is zero that row which contains data must be deleted
        if dataremove == 0:
            db.execute("DELETE FROM portfolio WHERE user_id=? AND quantity=0", session["user_id"])

    return redirect("/")
