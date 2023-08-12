# Define the Jar class
class Jar:
    # Initialize the Jar object with an optional capacity
    def __init__(self, capacity=12):
        # Check if the capacity is a non-negative integer
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity must be a non-negative integer")

        # Set the capacity and initialize the number of cookies to 0
        self._capacity = capacity
        self._cookies = 0

    # Return a string representation of the cookie jar using 🍪
    def __str__(self):
        return "🍪" * self._cookies

    # Deposit n cookies into the jar
    def deposit(self, n):
        # Check if depositing n cookies would exceed the capacity
        if self._cookies + n > self._capacity:
            raise ValueError("Exceeds jar capacity")

        # Update the number of cookies
        self._cookies += n

    # Withdraw n cookies from the jar
    def withdraw(self, n):
        # Check if withdrawing n cookies is possible
        if self._cookies < n:
            raise ValueError("Not enough cookies in the jar")

        # Update the number of cookies
        self._cookies -= n

    # Return the capacity of the jar
    @property
    def capacity(self):
        return self._capacity

    # Return the number of cookies in the jar
    @property
    def size(self):
        return self._cookies

# Define the main function
def main():
    # Create a new instance of Jar with default capacity
    jar = Jar()
    # Print the capacity of the jar
    print("Capacity:", jar.capacity)

    # Deposit 2 cookies and print the jar's contents
    jar.deposit(2)
    print(str(jar))

    # Withdraw 1 cookie and print the jar's contents
    jar.withdraw(1)
    print(str(jar))

# Check if the script is being run as the main program
if __name__ == "__main__":
    # Call the main function
    main()
