#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//gets user input for string and copies it twice to the console
// int main(void)
// {
//     // Get a string
//     string s = get_string("s: ");

//     // Copy string's address
//     string t = s;

//     // Capitalize first letter in string
//     t[0] = toupper(t[0]);

//     // Print string twice
//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }
//-------------------------------------------------------------
//gets user input for string and copies it twice to the console AND capitalizes the first letter
// int main(void)
// {
//     // Get a string
//     string s = get_string("s: ");

//     // Copy string's address
//     string t = s;

//     // Capitalize first letter in string
//     if (strlen(t) > 0)
//     {
//         t[0] = toupper(t[0]);
//     }

//     // Print string twice
//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }
//------------------------------------------------------------------
//this returns an error malloc(strlen(s) + 1)
// int main(void)
// {
//     // Get a string
//     char *s = get_string("s: ");

//     // Allocate memory for another string
//     char *t = malloc(strlen(s) + 1);

//     // Copy string into memory, including '\0'
//     for (int i = 0; i <= strlen(s); i++)
//     {
//         t[i] = s[i];
//     }

//     // Capitalize copy
//     t[0] = toupper(t[0]);

//     // Print strings
//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }
//-----------------------------------------------------------------------
int main(void)
{
    // Get a string
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    // Copy string into memory
    strcpy(t, s);

    // Capitalize copy
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free memory
    free(t);
    return 0;
}