// Include necessary header files
#include <cs50.h>
#include <ctype.h>

// Function prototype
bool valid(string password);

// Main function
int main(void)
{
    // Get password input from the user
    string password = get_string("Enter your password: ");

    // Check if the password is valid using the valid function
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number, and symbol\n");
    }
}

// Function to check if the password meets the required criteria
bool valid(string password)
{
    // Boolean variables to track whether we found a lowercase letter, uppercase letter, number, and symbol
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_symbol = false;

    // Iterate through each character in the password
    for (int i = 0; password[i] != '\0'; i++)
    {
        char c = password[i];

        // Check if the character is a lowercase letter
        if (islower(c))
        {
            has_lower = true;
        }
        // Check if the character is an uppercase letter
        else if (isupper(c))
        {
            has_upper = true;
        }
        // Check if the character is a digit (number)
        else if (isdigit(c))
        {
            has_digit = true;
        }
        // Check if the character is a symbol (non-alphanumeric)
        else if (ispunct(c))
        {
            has_symbol = true;
        }
    }

    // Check if all criteria are met (has at least one lowercase letter, one uppercase letter, one number, and one symbol)
    if (has_lower && has_upper && has_digit && has_symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}
