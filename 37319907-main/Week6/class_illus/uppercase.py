from cs50 import get_string

string = get_string("Input: ")

#string = string.upper()
#print(f"{string}")

print("After: ",end="")

for c in string:
    print(c.upper(), end="")
print()