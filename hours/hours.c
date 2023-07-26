// cs50 library for get_int() and get_char() functions
#include <cs50.h>
// ctype library for toupper() function
#include <ctype.h>
#include <stdio.h>

// for calculating either the total hours or the average hours per week
float calc_hours(int hours[], int weeks, char output);

// main method
int main(void)
{
    // number of weeks taking CS50 from the user
    int weeks = get_int("Number of weeks taking CS50: ");

    // array to store hours for each week
    int hours[weeks];

    // hours for each week from the user
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // prompt the user for their choice: T for total hours or A for average hours per week
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // call the calc_hours method to calculate and print the result
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// method to calculate either the total hours or the average hours per week
float calc_hours(int hours[], int weeks, char output)
{
    // calculate the total hours
    //if user input is T or t
    if (output == 'T' || output == 't')
    {
        //new int for calculating total hours starting from 0
        int total_hours = 0;
        //for loop starting from the first element until the number of weeks, check the next element
        for (int i = 0; i < weeks; i++)
        {
            //add the element value to the total hours value and repeat the loop until all weeks are added
            total_hours += hours[i];
        }
        //return the value of the total numbers
        return (float)total_hours;
    }
    // calculate the average hours per week
    //else if the user input is A or a
    else if (output == 'A' || output == 'a')
    {
        int total_hours = 0;
        for (int i = 0; i < weeks; i++)
        {
            total_hours += hours[i];
        }
        return (float)total_hours / weeks;
    }

    // If the provided 'output' parameter is not 'T' or 'A', return -1 as an error indicator
    return -1;
}