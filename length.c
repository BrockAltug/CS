#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    //Method 1
    // Prompt for user's name
    //string name = get_string("Name: ");

    // Count number of characters up until '\0' (aka NUL)
    //int n = 0;
    //while (name[n] != '\0')
    //{
    //    n++;
    //}
    //printf("%i\n", n);
    //--------------------------------------------------------
    //Method 2
    // Prompt for user's name
    //string name = get_string("Name: ");
    //int length = strlen(name);
    //printf("%i\n", length);
    //---------------------------------------------------------
    //Method 3
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}