#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Give 2 values for x and y\n");
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Perform addition
    //for user input return 1 int value %i after adding x + y values
    printf("x + y = %i\n", x + y);
}