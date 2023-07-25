#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    //make a new int variable calling to get_size method to get user input for size of the grid
    int n = get_size();
    //call to the print_grid method using the newly created int variable that got its value from user input
    print_grid(n);
}

//method to get user input for size of the grid
int get_size(void)
{
    //new int for n
    int n;
    //do while loop
    do
    //do -
    {
        //get user input for size of n variable as an integer
        n = get_int("Size: ");
    }
    //do this while n is less than 1
    while (n < 1);
    //return the value of n to the method
    return n;
}

//void method named print_grid using an integer value
void print_grid(int size)
{
    //starting from 0. until the value of size (user input), add 1
    for (int i = 0; i < size; i++)
    {
        //nested loop to print rows and colums
        for (int j = 0; j < size; j++)
        {
            //print the grid based on user input
            printf("#");
        }
        //make a new line at the end
        printf("\n");
    }
}