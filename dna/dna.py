import csv
import sys


def longest_match(sequence, subsequence):
    """returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # initialize count of consecutive runs
        count = 0

        # check for a subsequence match in a "substring" (a subset of characters) within sequence
        # if a match, move substring to next potential match in sequence
        # continue moving substring and checking for matches until out of consecutive matches
        while True:
            # adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # if there is a match in the substring
            if sequence[start:end].lower() == subsequence.lower():
                count += 1

            # if there is no match in the substring
            else:
                break

        # update most consecutive matches found
        longest_run = max(longest_run, count)

    # after checking for runs at each character in sequence, return longest run found
    return longest_run


def main():
    # check for command-line usage
    if len(sys.argv) != 3:
        print("usage: python dna.py data.csv sequence.txt")
        return

    # read csv file
    csv_filename = sys.argv[1]
    individuals = []
    with open(csv_filename, newline="") as csv_file:
        csv_reader = csv.DictReader(csv_file)
        for row in csv_reader:
            individuals.append(row)

    # read dna sequence
    dna_filename = sys.argv[2]
    with open(dna_filename, "r") as dna_file:
        dna_sequence = dna_file.read()

    # iterate through individuals and compare str counts
    for individual in individuals:
        name = individual["name"]
        str_counts = {
            key: int(value) for key, value in individual.items() if key != "name"
        }
        match = True
        for str_name, str_count in str_counts.items():
            if longest_match(dna_sequence, str_name) != str_count:
                match = False
                break
        if match:
            print(name)
            return

    print("no match")


if __name__ == "__main__":
    main()
