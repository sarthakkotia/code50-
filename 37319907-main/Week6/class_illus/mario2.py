
def main():
    n = get_height()
    for i in range(n):
        print("#")


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an Integar!")
main()
