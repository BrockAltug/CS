// Include the necessary header file for character manipulation functions
#include <ctype.h>
// Include the necessary header file for using CS50 functions
#include <cs50.h>
// Include the necessary header file for standard input/output functions
#include <stdio.h>
// Include the necessary header file for string manipulation functions
#include <string.h>

// Function prototypes
// Function to validate the key provided by the user
bool is_valid_key(string key);
// Function to encrypt the plaintext using the key
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        // Print usage message and return 1 to signify an error
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Validate the key provided by the user
    string key = argv[1];
    if (!is_valid_key(key))
    {
        // Print error message and return 1 to signify an error
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Get plaintext input from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the key
    string ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    // Return 0 to indicate successful execution
    return 0;
}

// Function to validate the key
bool is_valid_key(string key)
{
    // Get the length of the key
    int key_length = strlen(key);
    // Check if the key length is not 26 characters
    if (key_length != 26)
    {
        return false;
    }

    // Initialize an array to keep track of characters in the key
    bool characters[26] = {false};

    // Iterate over each character in the key
    for (int i = 0; i < key_length; i++)
    {
        // Convert the key character to uppercase
        char c = toupper(key[i]);
        // Check if the character is not an alphabet
        if (!isalpha(c))
        {
            return false;
        }

        // Calculate the index of the character in the alphabet
        int index = c - 'A';
        // Check if the character has already been used in the key
        if (characters[index])
        {
            return false;
        }
        // Mark the character as used in the key
        characters[index] = true;
    }

    // Return true if the key is valid
    return true;
}

// Function to encrypt the plaintext using the key
string encrypt(string plaintext, string key)
{
    // Initialize ciphertext with plaintext
    string ciphertext = plaintext;
    // Get the length of the plaintext
    int length = strlen(plaintext);

    // Iterate over each character in the plaintext
    for (int i = 0; i < length; i++)
    {
        // Get each character in the plaintext
        char c = plaintext[i];
        // Check if the character is an alphabet
        if (isalpha(c))
        {
            // Calculate the index of the character in the alphabet
            int index = toupper(c) - 'A';
            // Check if the character is lowercase
            if (islower(c))
            {
                // Encrypt the character as lowercase
                ciphertext[i] = tolower(key[index]);
            }
            else
            {
                // Encrypt the character as uppercase
                ciphertext[i] = toupper(key[index]);
            }
        }
    }

    // Return the encrypted ciphertext
    return ciphertext;
}
