#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get user inputs as new integer values for x and y
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");
    //checks the values from the user if x is less than y
    if (x < y)
    {
        //display that x is les than y and \n new line
        printf("x is less than y\n");
    }
    //else if x is greater than y
    else if (x > y)
    {
        //display that x is greater than y and \n new line
        printf("x is greater than y\n");
    }
    //else comes at the end, when if and all else ifs dont check
    else
    {
        //else print x is equal to y and \n new line
        printf("x is equal to y\n");
    }
}