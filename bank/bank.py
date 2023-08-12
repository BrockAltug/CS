# Main method
def main():
    # prompt the user for a greeting and remove leading/trailing whitespace,
    # then convert it to lowercase
    greeting = input("Enter a greeting: ").strip().lower()

    # check if the greeting starts with "hello" and output $0 if true
    if greeting.startswith("hello"):
        print("$0")
    # check if the greeting starts with "h" (but not "hello") and output $20 if true
    elif greeting.startswith("h"):
        print("$20")
    # if neither of the above conditions is met, output $100
    else:
        print("$100")


# check if the script is being run as the main program
if __name__ == "__main__":
    # call the main function
    main()
