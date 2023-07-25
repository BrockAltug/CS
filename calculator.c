#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Give 2 values for x and y\n");
    //use get_long to store higher value numbers
    // Prompt user for x
    int x = get_long("x: ");

    // Prompt user for y
    int y = get_long("y: ");

    // Perform addition
    //for user input return 1 int value %i after adding x + y values
    printf("x + y = %i\n", x + y);
}