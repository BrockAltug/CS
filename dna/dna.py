import csv
import sys

def main():
    # Check for correct command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # Read database file into a variable
    database_filename = sys.argv[1]
    individuals = read_database(database_filename)

    # Read DNA sequence file into a variable
    sequence_filename = sys.argv[2]
    dna_sequence = read_dna_sequence(sequence_filename)

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for str_sequence in individuals[0][1:]:
        str_counts[str_sequence] = longest_match(dna_sequence, str_sequence)

    # Check database for matching profiles
    match_name = find_match(individuals, str_counts)
    if match_name:
        print(match_name)
    else:
        print("No match")

def read_database(filename):
    individuals = []
    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            individuals.append(row)
    return individuals

def read_dna_sequence(filename):
    with open(filename, "r") as dnafile:
        return dnafile.read()

def find_match(individuals, str_counts):
    for individual in individuals[1:]:
        name = individual[0]
        counts = [int(count) for count in individual[1:]]
        if counts == [str_counts[str_sequence] for str_sequence in individuals[0][1:]]:
            return name
    return None

def longest_match(sequence, subsequence):
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0

        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run

if __name__ == "__main__":
    main()
