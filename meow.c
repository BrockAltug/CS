#include <stdio.h>

int main(void)
{
    //prints the text on a new line
    printf("meow\n");
    //print the same thing 2 more times
    printf("meow\n");
    printf("meow\n");
    //new integer value for i (count)
    int i = 0;
    //while loop until the count is 3
    while (i < 3)
    {
        //print the text on a new line
        printf("meow\n");
        //increase the count
        i++;
    }
    //new int variable
    int j = 3;
    while (i > 0)
    {
        printf("meow\n");
        j--;
    }
}