import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        date = request.form.get("date")
        date = str(date)
        day = date[8::]
        month = date[5:7]

        db.execute("INSERT INTO birthdays (name,day,month) VALUES(? ,? ,?)", name, day, month)
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        '''
        When the / route is requested via GET, your web application should display, in a table, all of the people in your database along with their birthdays.
First, in app.py, add logic in your GET request handling to query the birthdays.db database for all birthdays. Pass all of that data to your index.html template.
Then, in index.html, add logic to render each birthday as a row in the table. Each row should have two columns: one column for the person’s name and another column for the person’s birthday.
        '''

        birthdays = db.execute("SELECT * FROM birthdays")

        return render_template("index.html", birthdays = birthdays)


@app.route("/delete/<number>", methods=["POST"])
def delete(number):
    db.execute("DELETE FROM birthdays WHERE id = ?", number)
    return redirect("/")