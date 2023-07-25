#include <cs50.h>
#include <stdio.h>

//method to get height from user input
int get_height(void) {
    //new integer variable for height
    int height;
    //do while loop
    do {
        //get user input for height
        height = get_int("Height: ");
        //while height is less than 1 or greater than 8, keep prompting the user
    } while (height < 1 || height > 8);
    //return the value of height to the method
    return height;
}

//method to draw the pyramid platform shape
//using int for height
void draw_pyramid(int height) {
    //starting from 1 until user input for height, add 1
    for (int i = 1; i <= height; i++) {
        // draw left pyramid spaces
        //nested loop starting from 0 until the height - 1, add 1
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        // Draw left pyramid hashes
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Draw gap between pyramids
        printf("  ");

        // Draw right pyramid hashes
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("\n");   // Move to the next line after drawing each pyramid level
    }
}

int main(void) {
    int height = get_positive_integer();   // Get the height from the user
    draw_pyramid(height);   // Draw the pyramid with the provided height
    return 0;   // Indicate successful program execution
}
