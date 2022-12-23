from cs50 import get_string

people = {
    "Carter": "1111",
    "David": "9999"
}

name = get_string("Name: ")

if name in people:
    print(f"Number: {people[name]}")
