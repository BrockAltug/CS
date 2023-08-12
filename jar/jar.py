class Jar:
    # initialize the Jar object with an optional capacity
    def __init__(self, capacity=12):
        # check if the capacity is a non-negative integer
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity must be a non-negative integer")

        # set the capacity and initialize the number of cookies to 0
        self._capacity = capacity
        self._cookies = 0

    # return a string representation of the cookie jar using 🍪
    def __str__(self):
        return "cookie" * self._cookies

    # deposit n cookies into the jar
    def deposit(self, n):
        # check if depositing n cookies would exceed the capacity
        if self._cookies + n > self._capacity:
            raise ValueError("Exceeds jar capacity")

        # update the number of cookies
        self._cookies += n

    # withdraw n cookies from the jar
    def withdraw(self, n):
        # check if withdrawing n cookies is possible
        if self._cookies < n:
            raise ValueError("Not enough cookies in the jar")

        # update the number of cookies
        self._cookies -= n

    # return the capacity of the jar
    @property
    def capacity(self):
        return self._capacity

    # return the number of cookies in the jar
    @property
    def size(self):
        return self._cookies


# define the main function
def main():
    # create a new instance of Jar with default capacity
    jar = Jar()
    # print the capacity of the jar
    print("Capacity:", jar.capacity)

    # deposit 2 cookies and print the jar's contents
    jar.deposit(2)
    print(str(jar))

    # withdraw 1 cookie and print the jar's contents
    jar.withdraw(1)
    print(str(jar))


# check if the script is being run as the main program
if __name__ == "__main__":
    # call the main function
    main()
