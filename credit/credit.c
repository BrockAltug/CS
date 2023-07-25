#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //new long variable for card number
    long card_number;
    //new variable for digit count of the number
    int digit_count = 0;
    //new variable for the sum of digits
    int sum = 0;

    // prompt user for credit card number as a long variable
    card_number = get_long("Number: ");
    //new variable to store the original card number
    long temp_card_number = card_number;

    // calculate the sum of the digits as per Luhn's algorithm
    //while temp car is greater than 0
    while (temp_card_number > 0)
    {
        // Get the rightmost digit by using modulus
        int digit = temp_card_number % 10;
        //increase the digits count by 1
        digit_count++;
        //if the digit count divided by 2 equals 0 (even)
        if (digit_count % 2 == 0)
        {
            // for every other digit from the right, double and add the digits of the product
            int product = digit * 2;
            //sum = sum + product / 10 + product mod 10
            sum += (product / 10) + (product % 10);
        }
        //else
        else
        {
            // add the remaining digits to the sum
            sum += digit;
        }

        // remove the rightmost digit for the next iteration
        temp_card_number /= 10;
    }

    // determine the card type and validity
    //if sum after diving by 10 = 0
    if (sum % 10 == 0)
    {
        // check the card type and print the result
        long first_two_digits = card_number / 10000000000000;
        long first_digit = card_number / 1000000000000000;
        //if digit count equals 13 or 16 and the first digit is 4
        if ((digit_count == 13 || digit_count == 16) && (first_digit == 4))
        {
            //the card is visa
            printf("VISA\n");
        }
        //else if the digit count is 16 and the first 2 digits are greater than or equal to 51 and the first 2 digits are less than or equal to 55
        else if (digit_count == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            //the card is mastercard
            printf("MASTERCARD\n");
        }
        //else if the digit count is 15 and the first 2 digits equal 34 or 37
        else if (digit_count == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            //the card is amex
            printf("AMEX\n");
        }
        //else
        else
        {
            //the card does not match criteria and is invalid
            printf("INVALID\n");
        }
    }
    //else
    else
    //invalid card
    {
        printf("INVALID\n");
    }
}
