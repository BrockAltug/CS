#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Base case: if the input string is empty, return 0
    if (strlen(input) == 0)
    {
        return 0;
    }

    // Get the last character and convert it to an integer
    char last_char = input[strlen(input) - 1];
    int last_digit = last_char - '0';

    // Shorten the string, removing the last character
    input[strlen(input) - 1] = '\0';

    // Recursively call convert using the shortened string as input
    int remaining_value = convert(input);

    // Calculate the integer value using the recursive result and the last digit
    int result = remaining_value * 10 + last_digit;

    return result;
}
