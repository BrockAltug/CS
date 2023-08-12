# import the get_string function from the cs50 library
from cs50 import get_string


# Main method
def main():
    # prompt the user for a credit card number
    card_number = get_string("Number: ")

    # check if the card number is valid and identify the card type
    if is_valid(card_number):
        card_type = identify_card(card_number)
        print(card_type)
    else:
        print("INVALID")


# method to check if the card number is valid using the Luhn's algorithm
def is_valid(card_number):
    if not card_number.isdigit():
        return False

    return luhn_algorithm(card_number)


# method to implement the Luhn's algorithm for card number validation
def luhn_algorithm(card_number):
    total = 0
    for i in range(len(card_number) - 2, -1, -2):
        digit = int(card_number[i]) * 2
        total += digit // 10 + digit % 10

    for i in range(len(card_number) - 1, -1, -2):
        total += int(card_number[i])

    return total % 10 == 0


# method to identify the type of the credit card
def identify_card(card_number):
    if card_number.startswith("34") or card_number.startswith("37"):
        return "AMEX"
    elif (
        card_number.startswith("51")
        or card_number.startswith("52")
        or card_number.startswith("53")
        or card_number.startswith("54")
        or card_number.startswith("55")
    ):
        return "MASTERCARD"
    elif card_number.startswith("4"):
        return "VISA"
    else:
        return "INVALID"


# check if the script is being run as the main program
if __name__ == "__main__":
    # call the main method to start the program
    main()
