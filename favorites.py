# Prints all favorites in CSV using csv.reader

#import csv

# Open CSV file
#with open("favorites.csv", "r") as file:
#
    # Create reader
#    reader = csv.reader(file)
#
    # Skip header row
#    next(reader)
#
    # Iterate over CSV file, printing each favorite
#    for row in reader:
#        print(row[1])
#----------------------------------------------------------
# Stores favorite in a variable

#import csv
#
# Open CSV file
#with open("favorites.csv", "r") as file:
#
    # Create reader
#    reader = csv.reader(file)
#
    # Skip header row
#    next(reader)
#
    # Iterate over CSV file, printing each favorite
#    for row in reader:
#        favorite = row[1]
#        print(favorite)
#---------------------------------------------------------------
# Prints all favorites in CSV using csv.DictReader

#import csv

# Open CSV file
#with open("favorites.csv", "r") as file:
#
    # Create DictReader
#    reader = csv.DictReader(file)
#
    # Iterate over CSV file, printing each favorite
#    for row in reader:
#        print(row["language"])
#--------------------------------------------------------------
# Counts favorites using variables

#import csv

# Open CSV file
#with open("favorites.csv", "r") as file:

    # Create DictReader
#    reader = csv.DictReader(file)

    # Counts
#    scratch, c, python = 0, 0, 0

    # Iterate over CSV file, counting favorites
#    for row in reader:
#        favorite = row["language"]
#        if favorite == "Scratch":
#            scratch += 1
#        elif favorite == "C":
#            c += 1
#        elif favorite == "Python":
#            python += 1

# Print counts
#print(f"Scratch: {scratch}")
#print(f"C: {c}")
#print(f"Python: {python}")
#---------------------------------------------------------------
# Counts favorites using dictionary

import csv

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Counts
    counts = {}

    # Iterate over CSV file, counting favorites
    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

# Print counts
for favorite in counts:
    print(f"{favorite}: {counts[favorite]}")