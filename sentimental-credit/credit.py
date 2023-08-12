from cs50 import get_string

def main():
    card_number = get_string("Number: ")

    if is_valid(card_number):
        card_type = identify_card(card_number)
        print(card_type)
    else:
        print("INVALID")

def is_valid(card_number):
    if not card_number.isdigit():
        return False

    return luhn_algorithm(card_number)

def luhn_algorithm(card_number):
    total = 0
    for i in range(len(card_number) - 2, -1, -2):
        digit = int(card_number[i]) * 2
        total += digit // 10 + digit % 10

    for i in range(len(card_number) - 1, -1, -2):
        total += int(card_number[i])

    return total % 10 == 0

def identify_card(card_number):
    if card_number.startswith("34") or card_number.startswith("37"):
        return "AMEX"
    elif card_number.startswith("51") or card_number.startswith("52") or card_number.startswith("53") or card_number.startswith("54") or card_number.startswith("55"):
        return "MASTERCARD"
    elif card_number.startswith("4"):
        return "VISA"
    else:
        return "INVALID"

if __name__ == "__main__":
    main()
