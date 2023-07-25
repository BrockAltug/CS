#include <cs50.h>
#include <stdio.h>

//new method to get
int get_height(void) {
    int n;
    do {
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    return n;
}
//method to print out the pyramid level pattern
void draw_pyramid(int height) {
    //for loop, starting from 1 until the user input height, add 1
    for (int i = 1; i <= height; i++) {
        //draw left pyramid
        //nested loop
        //starting from 0 until height minus i add 1
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Draw gap
        printf("  ");

        // Draw right pyramid
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        printf("\n");
    }
}
//main method
int main(void) {
    int height = get_height();
    draw_pyramid(height);
}
