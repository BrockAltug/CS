#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    // initialize the average temperature data for each city
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    // sort cities by temperature in descending order
    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    // print the sorted cities and their temperatures
    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// Bubble Sort algorithm to sort cities by temperature in descending order
void sort_cities(void)
{
    // outer loop to iterate through all elements in the array
    for (int i = 0; i < NUM_CITIES - 1; i++)
    {
        // inner loop to compare adjacent elements and swap them if needed
        for (int j = 0; j < NUM_CITIES - i - 1; j++)
        {
            // compare the temperatures and swap the cities if the current temperature is less than the next temperature
            if (temps[j].temp < temps[j + 1].temp)
            {
                // swap the cities' temperatures
                int temp_temp = temps[j].temp;
                temps[j].temp = temps[j + 1].temp;
                temps[j + 1].temp = temp_temp;

                // swap the cities' names
                string temp_city = temps[j].city;
                temps[j].city = temps[j + 1].city;
                temps[j + 1].city = temp_city;
            }
        }
    }
}
