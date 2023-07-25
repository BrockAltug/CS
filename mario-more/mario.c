#include <cs50.h>
#include <stdio.h>

int get_positive_integer(void) {
    int n;
    do {
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    return n;
}

void draw_pyramid(int height) {
    for (int i = 1; i <= height; i++) {
        // Draw left pyramid
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

int main(void) {
    int height = get_positive_integer();
    draw_pyramid(height);
    return 0;
}
