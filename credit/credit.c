#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_number;
    int digit_count = 0;
    int sum = 0;

    // Get the credit card number from the user
    card_number = get_long("Number: ");
    long temp_card_number = card_number; // Store the original card number

    // Calculate the sum of the digits as per Luhn's algorithm
    while (temp_card_number > 0)
    {
        int digit = temp_card_number % 10;
        digit_count++;

        if (digit_count % 2 == 0)
        {
            int product = digit * 2;
            sum += (product / 10) + (product % 10);
        }
        else
        {
            sum += digit;
        }

        temp_card_number /= 10;
    }

    // Determine the card type and validity
    if (sum % 10 == 0)
    {
        if ((digit_count == 13 || digit_count == 16) && (card_number / 1000000000000 == 4))
        {
            printf("VISA\n");
        }
        else if (digit_count == 16 && (card_number / 100000000000000 >= 51 && card_number / 100000000000000 <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if (digit_count == 15 && (card_number / 10000000000000 == 34 || card_number / 10000000000000 == 37))
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
