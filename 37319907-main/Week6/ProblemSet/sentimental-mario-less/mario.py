# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for i in range(height):
    # print spaces the number of spaces printed will be 1 to height - current row number
    for spaces in range(1, height-i):
        print(" ", end="")
    # print hashes the number of hashes printe will be 0 to current row number +1
    for hashes in range(i+1):
        print("#", end="")
    print()