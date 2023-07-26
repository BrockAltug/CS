#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

//main method
int main(void)
{
    int i = get_negative_int();
    printf("%i\n", i);
}

// method to get negative integer from user
int get_negative_int(void)
{
    //new int variable to store user input
    int userInput;
    //do while loop
    do
    {
        //prompts for user input
        userInput = get_int("Negative Integer: ");
    }
    //while
    
    while (userInput >= 0);
    return userInput;
}