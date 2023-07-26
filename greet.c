#include <cs50.h>
#include <stdio.h>

// Method 1: A simple program to greet the user by name
// int main(void)
// {
//     // Prompt the user to input their name
//     string name = get_string("What's your name? ");
//     // Print a greeting message with the provided name
//     printf("hello, %s\n", name);
// }
//-----------------------------------------------------

// Method 2: A program that prints a greeting with a command-line argument or "hello, world" if none is provided
int main(int argc, string argv[])
{
    // check if there is exactly one command-line argument (program name is argc[0])
    if (argc == 2)
    {
        // print a greeting message with the provided command-line argument
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        // print a generic greeting message as no command-line argument was provided
        printf("hello, world\n");
    }
}
