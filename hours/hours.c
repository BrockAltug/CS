#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Function to calculate either the total hours or the average hours per week
float calc_hours(int hours[], int weeks, char output)
{
    // Calculate the total hours
    if (output == 'T')
    {
        int total_hours = 0;
        for (int i = 0; i < weeks; i++)
        {
            total_hours += hours[i];
        }
        return (float)total_hours;
    }
    // Calculate the average hours per week
    else if (output == 'A')
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
