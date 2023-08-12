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