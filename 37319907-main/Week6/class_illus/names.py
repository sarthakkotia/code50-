import sys

names = ["Bill", "Charlie", "George", "Fred", "Ron", "Percy"]

if "Ron" in names:
    print("Found")
    sys.exit(0)

print("NOt Found")
sys.exit(1)