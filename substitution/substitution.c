#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// method to validate the key provided by the user
bool is_valid_key(string key);
// method to encrypt the plaintext using the key
string encrypt(string plaintext, string key);

// Main method
int main(int argc, string argv[])
{
    // check for the correct number of command-line arguments
    if (argc != 2)
    {
        // print usage message and return 1 to signify an error
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // validate the key provided by the user
    string key = argv[1];
    //if is not valid key
    if (!is_valid_key(key))
    {
        // print error message and return 1 to signify an error
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // get plaintext input from the user
    string plaintext = get_string("plaintext: ");

    // encrypt the plaintext using the key
    string ciphertext = encrypt(plaintext, key);

    // print the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    // return 0 to indicate successful execution
    return 0;
}

// function to validate the key
bool is_valid_key(string key)
{
    // get the length of the key
    int key_length = strlen(key);
    // check if the key length is not 26 characters
    if (key_length != 26)
    {
        return false;
    }

    // initialize an array to keep track of characters in the key
    bool characters[26] = {false};

    // iterate over each character in the key
    for (int i = 0; i < key_length; i++)
    {
        // convert the key character to uppercase
        char c = toupper(key[i]);
        // check if the character is not an alphabet
        if (!isalpha(c))
        {
            return false;
        }

        // calculate the index of the character in the alphabet
        int index = c - 'A';
        // check if the character has already been used in the key
        if (characters[index])
        {
            return false;
        }
        // mark the character as used in the key
        characters[index] = true;
    }

    // return true if the key is valid
    return true;
}

// method to encrypt the plaintext using the key
string encrypt(string plaintext, string key)
{
    // initialize ciphertext with plaintext
    string ciphertext = plaintext;
    // get the length of the plaintext
    int length = strlen(plaintext);

    // go over each character in the plaintext
    for (int i = 0; i < length; i++)
    {
        // get each character in the plaintext
        char c = plaintext[i];
        // check if the character is an alphabet
        if (isalpha(c))
        {
            // calculate the index of the character in the alphabet
            int index = toupper(c) - 'A';
            // check if the character is lowercase
            if (islower(c))
            {
                // encrypt the character as lowercase
                ciphertext[i] = tolower(key[index]);
            }
            else
            {
                // encrypt the character as uppercase
                ciphertext[i] = toupper(key[index]);
            }
        }
    }

    // return the encrypted ciphertext
    return ciphertext;
}
