#include <stdio.h>

int main(void)
{
    // prints the text on a new line
    printf("meow\n");
    // print the same thing 2 more times
    printf("meow\n");
    printf("meow\n");
    // new integer value for i (count)
    int i = 0;
    // while loop until the count is 3
    while (i < 3)
    {
        // print the text on a new line
        printf("meow\n");
        // increase the count
        i++;
    }
    // new int variable for j (count) starting a 3
    int j = 3;
    // while the count is greater than 0
    while (j > 0)
    {
        // print the text on a new line
        printf("meow\n");
        // decrease the count
        j--;
    }
    // method to print meow 3 times using a for loop
    // starting from 0 until 3 times, add 1
    for (int k = 0; k < 3; k++)
    {
        // will print out meow each time
        printf("meow\n");
    }
    // this will print out the text infinitely
    // ctrl + C to break from infinite
    // while (true)
    // {
    //     printf("meow\n");
    // }
}