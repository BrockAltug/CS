def main():
    height = get_height()
    print_pyramids(height)

def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                return height
            else:
                print("Height must be between 1 and 8, inclusive.")
        except ValueError:
            print("Invalid input. Please enter a positive integer.")

def print_pyramids(height):
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        hashes = "#" * i
        print(f"{spaces}{hashes}  {hashes}")

if __name__ == "__main__":
    main()
