# TODO
from cs50 import get_int


def main():
    n = get_int("Number: ")
    # to get the first two digits of the number
    digits = finddigits(n)
   # print(f"{digit}")
    n2 = n
   # print(f"{n}")
    sum1 = 0
    sum2 = 0
    count = 0
    # do the following so that at the end we can count the the number of digits and also perform the checksum
    while True:
        digit = int(n2 % 10)
        n2 = int(n2 / 10)
        count += 1
        # if the the digit position is even
        if(count % 2 == 0):
            digit = digit * 2
            # see if number is 2 digit then convert it to the the sum of the digits
            if(digit >= 10):
                digit = (digit % 10) + 1
            sum2 = sum2 + digit
        else:
            sum1 = sum1 + digit
        # conditional statement to break out the loop as this loop is working like a do while loop
        if(n2 <= 0):
            break
    # perform the checksum
    checksum = sum1 + sum2
   # print(f"{checksum}")
   # print(f"{digits//10}")
    if(checksum % 10 == 0):
        if(count == 15):
            if(digits == 34 or digits == 37):
                print("AMEX")
            else:
                print("INVALID")
        elif(count == 16):
            if(digits == 51 or digits == 52 or digits == 53 or digits == 54 or digits == 55):
                print("MASTERCARD")
            elif(digits // 10 == 4):
                print("VISA")
            else:
                print("INVALID")
        elif(count == 13):
            if(digits // 10 == 4):
                print("VISA")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")


def finddigits(n):
    # to find the first two digit of the number given we can convert the given number to string and use slicing techniques
    digit = int(str(n)[0:2])
    return digit


main()