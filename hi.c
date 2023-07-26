// Include the cs50 library for string data type and get_string() function
#include <cs50.h>
// Include the standard input/output library
#include <stdio.h>

int main(void)
{
    // Method 1: Using individual characters
    // char c1 = 'H';
    // char c2 = 'I';
    // char c3 = '!';

    // printf("%i %i %i\n", c1, c2, c3);
    //-------------------------------------------

    // Method 2: Using a string
    // string s = "HI!";
    // printf("%i %i %i\n", s[0], s[1], s[2]);
    //-------------------------------------------

    // Method 3: Using multiple strings
    // string s = "HI!";
    // string t = "BYE!";

    // printf("%s\n", s);
    // printf("%s\n", t);
    //-------------------------------------------

    // Method 4: Using an array of strings
    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);
}
