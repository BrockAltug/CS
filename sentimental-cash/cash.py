# import the get_float function from the cs50 library
from cs50 import get_float


# Main method
def main():
    # get the amount of change owed from the user
    change_owed = get_positive_float("Change owed: ")
    cents = int(change_owed * 100)
    coins = calculate_coins(cents)
    print(coins)


# method to get a positive float input from the user
def get_positive_float(prompt):
    while True:
        value = get_float(prompt)
        if value >= 0:
            return value


# method to calculate the minimum number of coins needed to make change
def calculate_coins(cents):
    coins = 0

    coins += cents // 25
    cents %= 25

    coins += cents // 10
    cents %= 10

    coins += cents // 5
    cents %= 5

    coins += cents

    return coins


# check if the script is being run as the main program
if __name__ == "__main__":
    # call the main method to start the program
    main()
