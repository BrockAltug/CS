#include <ctype.h> // Include the necessary header file for character manipulation functions
#include <cs50.h> // Include the necessary header file for using CS50 functions
#include <stdio.h> // Include the necessary header file for standard input/output functions
#include <string.h> // Include the necessary header file for string manipulation functions

// Function prototypes
bool is_valid_key(string key); // Function to validate the key provided by the user
string encrypt(string plaintext, string key); // Function to encrypt the plaintext using the key

int main(int argc, string argv[])
{
    // Check for the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1; // Return 1 to signify an error
    }

    // Validate the key provided by the user
    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1; // Return 1 to signify an error
    }

    // Get plaintext input from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the key
    string ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0; // Return 0 to indicate successful execution
}

// Function to validate the key
bool is_valid_key(string key)
{
    int key_length = strlen(key);
    if (key_length != 26)
    {
        return false;
    }

    // Initialize an array to keep track of characters in the key
    bool characters[26] = {false};

    for (int i = 0; i < key_length; i++)
    {
        char c = toupper(key[i]); // Convert the key character to uppercase
        if (!isalpha(c)) // Check if the character is not an alphabet
        {
            return false;
        }

        int index = c - 'A'; // Calculate the index of the character in the alphabet
        if (characters[index]) // Check if the character has already been used in the key
        {
            return false;
        }
        characters[index] = true; // Mark the character as used in the key
    }

    return true; // Return true if the key is valid
}

// Function to encrypt the plaintext using the key
string encrypt(string plaintext, string key)
{
    string ciphertext = plaintext; // Initialize ciphertext with plaintext
    int length = strlen(plaintext);

    for (int i = 0; i < length; i++)
    {
        char c = plaintext[i]; // Get each character in the plaintext
        if (isalpha(c)) // Check if the character is an alphabet
        {
            int index = toupper(c) - 'A'; // Calculate the index of the character in the alphabet
            if (islower(c)) // Check if the character is lowercase
            {
                ciphertext[i] = tolower(key[index]); // Encrypt the character as lowercase
            }
            else
            {
                ciphertext[i] = toupper(key[index]); // Encrypt the character as uppercase
            }
        }
    }

    return ciphertext; // Return the encrypted ciphertext
}
