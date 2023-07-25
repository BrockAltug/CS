#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get credit card number from the user
    long long card_number;
    do
    {
        card_number = get_long("Number: "); // Prompt the user to input the credit card number
    } while (card_number <= 0);

    // Variables to keep track of calculations
    int sum = 0; // Initialize a variable to store the sum of the digits
    int count = 0; // Initialize a counter to keep track of the number of digits

    // Loop through the credit card number digits
    while (card_number > 0)
    {
        int digit = card_number % 10; // Extract the last digit from the credit card number
        card_number /= 10; // Remove the last digit from the credit card number

        if (count % 2 == 1)
        {
            // Multiply every other digit by 2
            digit *= 2;

            // Add the individual digits of the product to the sum
            sum += digit / 10 + digit % 10;
        }
        else
        {
            // Add non-multiplied digits to the sum
            sum += digit;
        }

        count++; // Increment the digit counter
    }

    // Check if the card number is valid based on Luhn's algorithm
    if (sum % 10 == 0)
    {
        // Determine the type of credit card (AMEX, MASTERCARD, VISA, or INVALID)
        int first_two_digits = card_number;
        while (first_two_digits > 100)
        {
            first_two_digits /= 10;
        }

        if ((count == 15 && (first_two_digits == 34 || first_two_digits == 37)))
        {
            printf("AMEX\n"); // If the card has 15 digits and starts with 34 or 37, it is AMEX
        }
        else if (count == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            printf("MASTERCARD\n"); // If the card has 16 digits and starts with 51 to 55, it is MASTERCARD
        }
        else if ((count == 13 || count == 16) && first_two_digits / 10 == 4)
        {
            printf("VISA\n"); // If the card has 13 or 16 digits and starts with 4, it is VISA
        }
        else
        {
            printf("INVALID\n"); // If the card does not match any known format, it is INVALID
        }
    }
    else
    {
        printf("INVALID\n"); // If the card fails Luhn's algorithm check, it is INVALID
    }

    return 0; // Indicate successful program execution
}
