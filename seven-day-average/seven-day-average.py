import csv
import requests


# Define the main function
def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each state
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        # Get user input for state selection
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {}
    for row in reader:
        state = row["state"]
        cases = int(row["cases"])
        if state not in new_cases:
            new_cases[state] = []
        if len(new_cases[state]) >= 14:
            new_cases[state].pop(0)  # Remove the oldest day's data
        if len(new_cases[state]) > 0:
            previous_cases = new_cases[state][-1]
            new_cases[state].append(cases - previous_cases)
        else:
            new_cases[state].append(cases)
    return new_cases


# Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        cases = new_cases[state]
        current_week = sum(cases[-7:]) / 7
        previous_week = sum(cases[-14:-7]) / 7 if len(cases) >= 14 else 0

        try:
            percent_change = ((current_week - previous_week) / previous_week) * 100
        except ZeroDivisionError:
            percent_change = 0

        print(
            f"{state} had a 7-day average of {int(current_week)} and a change of {int(percent_change)}%."
        )


# Call the main function to start the program
main()
