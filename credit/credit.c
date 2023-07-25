#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_number;
    int digit_count = 0;
    int sum = 0;

    // Get the credit card number from the user
    card_number = get_long("Number: ");

    // Calculate the sum of the digits as per Luhn's algorithm
    while (card_number > 0)
    {
        int digit = card_number % 10;
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

        card_number /= 10;
    }

    // Determine the card type and validity
    if (sum % 10 == 0)
    {
        if (digit_count == 15 && (card_number / 10 == 34 || card_number / 10 == 37))
        {
            printf("AMEX\n");
        }
        else if (digit_count == 16 && (card_number / 100 >= 51 && card_number / 100 <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((digit_count == 13 || digit_count == 16) && card_number / 1000 == 4)
        {
            printf("VISA\n");
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
