#include <cs50.h>
#include <stdio.h>

// main function that accepts command-line arguments
int main(int argc, string argv[])
{
    // check if there are exactly two command-line arguments (the program name and the argument)
    if (argc != 2)
    {
        // print an error message if the argument count is not 2
        printf("Missing command-line argument\n");
        // return 1 to indicate an error occurred
        return 1;
    }

    // if there are two command-line arguments, print a greeting with the provided argument
    printf("hello, %s\n", argv[1]);
    // return 0 to indicate successful execution
    return 0;
}
