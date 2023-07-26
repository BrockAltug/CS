// include the cs50 library for get_string() function
#include <cs50.h>
// include the ctype library for character handling functions
#include <ctype.h>
// include the standard input/output library
#include <stdio.h>
// include the string library for string manipulation functions
#include <string.h>

int main(void)
{
    // Method 1: Counting characters in a string using a loop
    // Prompt for user's name
    // string name = get_string("Name: ");

    // Count number of characters up until '\0' (aka NUL)
    // int n = 0;
    // while (name[n] != '\0')
    // {
    //    n++;
    // }
    // printf("%i\n", n);
    //--------------------------------------------------------

    // Method 2: Counting characters in a string using strlen()
    // Prompt for user's name
    // string name = get_string("Name: ");
    // int length = strlen(name);
    // printf("%i\n", length);
    //---------------------------------------------------------

    // Method 3: Converting lowercase characters to uppercase
    // string s = get_string("Before: ");
    // printf("After:  ");
    // for (int i = 0, n = strlen(s); i < n; i++)
    // {
    //    if (s[i] >= 'a' && s[i] <= 'z')
    //    {
    //        printf("%c", s[i] - 32);
    //    }
    //    else
    //    {
    //        printf("%c", s[i]);
    //    }
    // }
    // printf("\n");
    //-----------------------------------------------------------

    // Method 4: Using islower() and toupper() functions
    // string s = get_string("Before: ");
    // printf("After:  ");
    // for (int i = 0, n = strlen(s); i < n; i++)
    // {
    //    if (islower(s[i]))
    //    {
    //        printf("%c", toupper(s[i]));
    //    }
    //    else
    //    {
    //        printf("%c", s[i]);
    //    }
    // }
    // printf("\n");
    //----------------------------------------------------------

    // Method 5: Converting all characters to uppercase
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}