#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

// main method
int main(void)
{
    // call to get_negative_int method to return user input for negative number
    int i = get_negative_int();
    // print out user negative integer value
    printf("%i\n", i);
}

// method to get negative integer from user
int get_negative_int(void)
{
    // new int variable to store user input
    int userInput;
    // do while loop
    do
    {
        // prompts for user input
        userInput = get_int("Negative Integer: ");
    }
    // while user input is greater than or equal to 0, prompt user for negative integer
    while (userInput >= 0);
    // return user input
    return userInput;
}