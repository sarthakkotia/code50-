from sys import exit

numbers = [1, 2, 3, 4, 5, 6, 0]

if 0 in numbers:
    print("Found")
    exit(0)

print("Not Found")
exit(1)