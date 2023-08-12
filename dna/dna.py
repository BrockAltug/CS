import csv
import sys

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
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

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    csv_filename = sys.argv[1]
    individuals = []
    with open(csv_filename, newline='') as csv_file:
        csv_reader = csv.DictReader(csv_file)
        for row in csv_reader:
            individuals.append(row)

    dna_filename = sys.argv[2]
    with open(dna_filename, 'r') as dna_file:
        dna_sequence = dna_file.read()

    for individual in individuals:
        name = individual['name']
        str_counts = {key: int(value) for key, value in individual.items() if key != 'name'}
        match = True
        for str_name, str_count in str_counts.items():
            if longest_match(dna_sequence, str_name) != str_count:
                match = False
                break
        if match:
            print(name)
            return

    print("No match")

if __name__ == "__main__":
    main()
