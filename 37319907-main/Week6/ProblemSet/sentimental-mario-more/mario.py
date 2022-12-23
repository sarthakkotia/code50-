# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for i in range(height):
    # print spaces for the the first half pyramid
    for spaces in range(1, height-i):
        print(" ", end="")
    # print hashes for the first half of pyramid
    for hashes in range(i+1):
        print("#", end="")
    # print the gap between the two pyramids
    print("  ", end="")
    # print hashes for the second pyramid
    for hashes2 in range(i+1):
        print("#", end="")
    print()

