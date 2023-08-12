# Prints a column of 3 bricks with a loop

for i in range(3):
    print("#")
#-----------------------------------------------
# Prints a column of bricks, using a helper function to get input
#using cs50 import
from cs50 import get_int


def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0:
            return n


main()
#--------------------------------------------------
# Prints a column of bricks, catching exceptions
#without cs50 import
def main():
    height = get_height()
    for i in range(height):
        print("#")


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")


main()
#-----------------------------------------------------
# Prints a row of 4 question marks with a loop

for i in range(4):
    print("?", end="")
print()
#-----------------------------------------------------
#simplified
# Prints a row of 4 question marks without a loop

print("?" * 4)
#--------------------------------------------------------
#3x3 grid
# Prints a 3-by-3 grid of bricks with loops

for i in range(3):
    for j in range(3):
        print("#", end="")
    print()