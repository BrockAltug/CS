#Code written in C
#// Conditionals, Boolean expressions, relational operators
#
#include <cs50.h>
#include <stdio.h>
#
#int main(void)
#{
#    // Prompt user for integers
#    int x = get_int("What's x? ");
#    int y = get_int("What's y? ");
#
#    // Compare integers
#    if (x < y)
#    {
#        printf("x is less than y\n");
#    }
#    else if (x > y)
#    {
#        printf("x is greater than y\n");
#    }
#    else
#    {
#        printf("x is equal to y\n");
#    }
#}
#How the same thing is written in Python
# Conditionals, Boolean expressions, relational operators

from cs50 import get_int

# Prompt user for integers
x = get_int("What's x? ")
y = get_int("What's y? ")

# Compare integers
if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")

#Code written in C
#// Logical operators
#
#include <cs50.h>
#include <stdio.h>
#
#int main(void)
#{
#    // Prompt user to agree
#    char c = get_char("Do you agree? ");
#
#    // Check whether agreed
#    if (c == 'Y' || c == 'y')
#    {
#        printf("Agreed.\n");
#    }
#    else if (c == 'N' || c == 'n')
#    {
#        printf("Not agreed.\n");
#    }
#}
#Same thing written in Python
# Logical operators
#
#from cs50 import get_string
#
# Prompt user to agree
#s = get_string("Do you agree? ")
#
# Check whether agreed
#if s == "Y" or s == "y":
#    print("Agreed.")
#elif s == "N" or s == "n":
#    print("Not agreed.")
# Logical operators, using lists

from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")