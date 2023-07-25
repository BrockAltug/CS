#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Initialize variables
    long long card_number;
    int digit_count = 0;
    int sum = 0;

    // Get the credit card number from the user
    card_number = get_long_long("Number: ");
    long long temp_card_number = card_number; // Store the original card number

    // Calculate the sum of the digits as per Luhn's algorithm
    while (temp_card_number > 0)
    {
        // Get the rightmost digit
        int digit = temp_card_number % 10;
        digit_count++;

        if (digit_count % 2 == 0)
        {
            // For every other digit from the right, double and add the digits of the product
            int product = digit * 2;
            sum += (product / 10) + (product % 10);
        }
        else
        {
            // For the remaining digits, simply add them to the sum
            sum += digit;
        }

        // Remove the rightmost digit for the next iteration
        temp_card_number /= 10;
    }

    // Determine the card type and validity
    if (sum % 10 == 0)
    {
        // Check the card type and print the result
        long long first_two_digits = card_number / 10000000000000;
        long long first_digit = card_number / 1000000000000000;

        if ((digit_count == 13 || digit_count == 16) && (first_digit == 4))
        {
            printf("VISA\n");
        }
        else if (digit_count == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if (digit_count == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
