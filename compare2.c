#include <cs50.h>
#include <stdio.h>

// int main(void)
// {
// this will always display as "different
// Get two strings
// char *s = get_string("s: ");
// char *t = get_string("t: ");

// // Compare strings' addresses
// if (s == t)
// {
//     printf("Same\n");
// }
// else
// {
//     printf("Different\n");
// }
// }
//--------------------------------------------------
//will display the text 2 times
// int main(void)
// {
//     // Get two strings
//     char *s = get_string("s: ");
//     char *t = get_string("t: ");

//     // Print strings
//     printf("%s\n", s);
//     printf("%s\n", t);
// }
//----------------------------------------------------
//will display the data values
int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // Print strings' addresses
    printf("%p\n", s);
    printf("%p\n", t);
}
