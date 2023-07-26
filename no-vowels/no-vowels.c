#include <cs50.h>
#include <stdio.h>
#include <string.h>

// method to replace all vowels in a word with numbers
string replace(string input);

// Main method
int main(int argc, string argv[])
{
    // check for the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: %s word\n", argv[0]);
        return 1; // return 1 to signify an error
    }

    // call the replace function to convert the word and print the result
    string converted_word = replace(argv[1]);
    printf("%s\n", converted_word);
}

// method to replace vowels with numbers
string replace(string input)
{
    // new string to store the converted word
    string converted_word = input;

    // loop through each character in the input string
    for (int i = 0, length = strlen(input); i < length; i++)
    {
        char ch = input[i];

        // use a switch statement to replace vowels with numbers
        switch (ch)
        {
            //incase if a
            case 'a':
            //convert to 6
                converted_word[i] = '6';
                break;
                //in case if e
            case 'e':
            //convert to 3
                converted_word[i] = '3';
                break;
                //in case if i
            case 'i':
            //convert to 1
                converted_word[i] = '1';
                break;
                //in case if o
            case 'o':
            //convert to 0
                converted_word[i] = '0';
                break;
            // For 'u', we don't change anything, so no need to include a case for it.
        }
    }
    //return the word after vowel conversion
    return converted_word;
}
