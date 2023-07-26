#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Method 1: Searching for an integer in an array of integers
// int main(void)
// {
//     // An array of integers
//     int numbers[] = {20, 500, 10, 5, 100, 1, 50};

//     // Get input number from the user
//     int n = get_int("Number: ");

//     // Search for the number in the array
//     for (int i = 0; i < 7; i++)
//     {
//         if (numbers[i] == n)
//         {
//             printf("Found\n");
//             return 0;
//         }
//     }
//     printf("Not found\n");
//     return 1;
// }
// ---------------------------------------------------------------------
//  Method 2: Searching for a string in an array of strings
// int main(void)
// {
//     // An array of strings
//     string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

//     // Get input string from the user
//     string s = get_string("String: ");

//     // Search for the string in the array
//     for (int i = 0; i < 6; i++)
//     {
//         if (strcmp(strings[i], s) == 0)
//         {
//             printf("Found\n");
//             return 0;
//         }
//     }
//     printf("Not found\n");
//     return 1;
// }
//---------------------------------------------------------------------
// Method 3: Searching for a name and corresponding number in arrays of strings
 int main(void)
{
 Arrays of strings
    string names[] = {"Carter", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

 Get input name from the user
    string name = get_string("Name: ");

 Search for the name and corresponding number in the array
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

