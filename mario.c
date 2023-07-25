#include <stdio.h>

int main(void)
{
    //for loop
    //starting from 0 until 3, add1
    for (int i = 0; i < 3; i++)
    {
        //nested loop, a loop inside of a loop
        //starting from 0 until 3 add 1
        for (int j = 0; j < 3; j++)
        {
            //print a grid
            printf("#");
        }
        //print a new line
        printf("\n");
    }
}