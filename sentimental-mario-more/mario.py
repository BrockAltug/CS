# Main method
def main():
    # get the desired height of the half-pyramids from the user
    height = get_height()

    # generate and print the half-pyramids with the provided height
    print_pyramids(height)


# method to get a valid height input from the user
def get_height():
    while True:
        try:
            # prompt the user for input and convert it to an integer
            height = int(input("Height: "))

            # check if the input is within the valid range (1 to 8)
            if 1 <= height <= 8:
                return height
            else:
                print("Height must be between 1 and 8, inclusive.")
        except ValueError:
            print("Invalid input. Please enter a positive integer.")


# method to print the half-pyramids based on the provided height
def print_pyramids(height):
    for i in range(1, height + 1):
        # calculate the number of spaces and hashes for each row
        spaces = " " * (height - i)
        hashes = "#" * i

        # print the current row with appropriate formatting
        print(f"{spaces}{hashes}  {hashes}")


# check if the script is being run as the main program
if __name__ == "__main__":
    # call the main method to start the program
    main()
