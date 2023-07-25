#include <cs50.h>
#include <stdio.h>

// method to get height from user input
int get_height(void)
{
    // new integer variable for height
    int height;
    // do while loop
    do
    {
        // get user input for height
        height = get_int("Height: ");
        // while height is less than 1 or greater than 8, keep prompting the user
    }
    while (height < 1 || height > 8);
    // return the value of height to the method
    return height;
}

// method to draw the pyramid platform shape
// using int for height
void draw_pyramid(int height)
{
    // starting from 1 until user input for height, add 1
    // it is responsible for drawing each level (row) of the pyramid.
    for (int i = 1; i <= height; i++)
    {
        // draw left pyramid spaces
        // nested loop starting from 0 until the height - 1, add 1
        // the number of spaces to draw in each row decreases as the row number increases.
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        // draw left pyramid hashes
        // used to draw the # symbols on the left side of the pyramid.
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // draw gap between pyramids
        printf("  ");

        // draw right pyramid hashes
        // used to draw the # symbols on the right side of the pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // move to the next line after drawing each pyramid level
        printf("\n");
    }
}

int main(void)
{
    // new integer for height calling to the get_height() method to get the height of the level
    int height = get_height();
    // call to the draw_pyramid() method to draw the level using height from the get_height() method
    draw_pyramid(height);
}
