# TODO
from cs50 import get_float


def main():
    # calculate the change owned
    cents = get_cents()
    # calculate quarters
    quarters = get_quarters(cents)
    # chsange cents to it's new value
    cents = cents - quarters * 25
    # calculate dimes
    dimes = get_dimes(cents)
    # chsange cents to it's new value
    cents = cents - dimes * 10
    # calculate nickels
    nickels = get_nickels(cents)
    # chsange cents to it's new value
    cents = cents - nickels * 5
    # the rest cents will be always in pennies ie always less than 5 therefore after subtraction pennies will be the value of cents
    pennies = cents

    coins = quarters + dimes + nickels + pennies
    print(f"{int(coins)}")


def get_cents():
    while True:
        doll = get_float("Change Owed: ")
        if doll > 0:
            break
    return (doll * 100)


def get_quarters(cents):
    return int(cents / 25)


def get_dimes(cents):
    return int(cents / 10)


def get_nickels(cents):
    return int(cents / 5)


main()