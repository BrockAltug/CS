# Import necessary modules
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

    # Collect user input for selected states
    while True:
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
    new_cases = {}  # Dictionary to store new cases for each state

    # Iterate through the CSV data
    for row in reader:
        state = row['state']
        cases = int(row['cases'])
        # If the state is not in the dictionary, initialize a list with the current cases
        if state not in new_cases:
            new_cases[state] = [cases]
        else:
            # Calculate and append new daily cases (current cases - previous day's cases)
            previous_cases = new_cases[state][-1]
            new_daily_cases = cases - previous_cases
            new_cases[state].append(new_daily_cases)

        # If the list for a state exceeds 14 days, remove the oldest entry
        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)

    return new_cases

# Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        # Calculate the 7-day average for this week
        this_week_avg = sum(new_cases[state][-7:]) / 7

        # Calculate the 7-day average for the previous week
        last_week_avg = sum(new_cases[state][-14:-7]) / 7

        # Calculate the percent increase or decrease
        try:
            percent_change = ((this_week_avg - last_week_avg) / last_week_avg) * 100
        except ZeroDivisionError:
            percent_change = 0

        # Print the results
        print(f"{state} had a 7-day average of {int(this_week_avg)} and "
              f"{'an increase' if percent_change > 0 else 'a decrease'} of {abs(int(percent_change))}%.")

# Call the main function if this script is run directly
if __name__ == "__main__":
    main()
