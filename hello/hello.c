#include <stdio.h>
// include to get_string
#include <cs50.h>
// main method
int main(void)
{
    // prompt the user for their name
    // new string for name = get user input
    string name = get_string("What's your name? ");
    // prints hello, and %s for the users name input
    printf("hello, %s\n", name);
}