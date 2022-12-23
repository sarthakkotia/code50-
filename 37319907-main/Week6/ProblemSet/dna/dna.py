import csv
import sys


def main():

    # TODO: Check for command-line usage
    if(len(sys.argv) != 3):
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    fields = []
    suspectsdata = []
    with open(f"{sys.argv[1]}", "r") as f:
        reader = csv.reader(f)
        # during reeading store the first line in a sepearte list called fields
        fields = next(reader)
        # the following loop will store 1 row data in a list and that list will be a part of another list called suspectsdata so it's like [["aklic" , "23" , "7"],["Luna",'67','9']]
        for row in reader:
            suspectsdata.append(row)

    # TODO: Read DNA sequence file into a variable
    # the following will store the the DNA string into the variable dna which will be helped further ie loading sequence into memory
    with open(f"{sys.argv[2]}", "r") as f2:
        dna = f2.read()

    # dictionary to hold the values of the logest sequence of the STR individually like {'AATG' : 5, 'TFH' : 7}
    d = {}
    # TODO: Find longest match of each STR in DNA sequence
    # loop to store the longest str in the dict
    for i in range(1, len(fields)):
        d[fields[i]] = longest_match(dna, fields[i])

    # TODO: Check database for matching profiles
    # run the loop for the number of the suspectsdata saved
    for i in range(len(suspectsdata)):
        # variable to help find the final result
        count = 0
        # another loop which will run for all the STR's mentioned in the csv
        for j in range(1, len(fields)):
            # if the followiung match exacly ie dictionary's 'AAGT' key value and the suspectsdata which is list in a list corresponding value matched then varibale++ here suspectsdata[i][j] means go to suspectsdata[i] index list and then in that [i]th list go to [j] the index which stores the 'AAGT' number for that suspect
            if(int(d[fields[j]]) == int(suspectsdata[i][j])):
                count = count + 1
            # if it doesn't match it's good to break no need to check further
            else:
                break
        # if all the STR's match it's a match
        if(count == len(fields)-1):
            # the suspectsdata[i] th list [0] index will always have the name of the person
            print(suspectsdata[i][0])
            # no need to check further exit as only person will have same DNA
            sys.exit(0)
    # if whole loop worked and still no exit till now so match doesn't exist
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
