#include <stdio.h>
// main method
int main(void)
{
    // new integer variables start_size and end_size to store values
    int start_size, end_size;

    // prompt for start size
    // do while loop
    do
    {
        // prompt the user for starting size
        printf("Start size: ");
        scanf("%d", &start_size);
    }
    // while the starting size is less than 9, keep prompting
    while (start_size < 9);

    // prompt for end size
    // do while loop
    do
    {
        // prompt user for end size
        printf("End size: ");
        scanf("%d", &end_size);
    }
    // while the end size is smaller than the starting size
    while (end_size < start_size);

    // new integer for years (count) starting at 0
    int years = 0;

    // calculate number of years until we reach desired population size
    // while the start size is less than the end size
    while (start_size < end_size)
    {
        // new integer for llamas being born, = start size / 3
        int new_llamas = start_size / 3;
        // new integer for llamas dying, = start size / 4
        int passed_away = start_size / 4;
        // calculate the size by adding the start size with the born and dying llamas
        start_size = start_size + new_llamas - passed_away;
        // add 1 year to the count until the population number is reached
        years++;
    }
    // print number of years at the very end when the population number has been reached and the loops finish
    printf("Years: %d\n", years);
}
