# menu of entrees with their prices
menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

# method to calculate the total cost of the order
def calculate_total(order):
    total = sum(menu[item] for item in order)
    return total

# Main method to place an order
def main():
    print("Welcome to Felipe's Taqueria!")
    print("Please enter your order, one item per line.")
    print("Press Ctrl-D (Ctrl-Z on Windows) to finish your order.\n")

    order = []  # list to store the user's order

    try:
        while True:
            # prompt the user to input an item
            item = input("Item: ").title()  # Convert the input to title case
            if item in menu:
                order.append(item)
                total = calculate_total(order)
                print(f"Total: ${total:.2f}\n")
            else:
                print("Invalid item. Please choose from the menu.\n")
    except EOFError:
        # handle the Ctrl-D (or Ctrl-Z on Windows) input to end the order
        total = calculate_total(order)
        print(f"Final Total: ${total:.2f}")
        print("Thank you for your order!")

if __name__ == "__main__":
    main()
