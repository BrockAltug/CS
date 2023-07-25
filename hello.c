// in terminal $ code hello.c creates a new file named hello in C
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // printf is how to print (print-f is for function)
    // anytime using String text must be quoted ""
    // all code ends in ;
    // \n makes a new line
    printf("hello world\n");
    // the get_string function is used to get a string from the user
    // then, the variable answer is passed to the printf function
    // %s tells the printf function to prepare itself to receive a string
    string answer = get_string("What's your name? ");
    // answer is a special holding place we call a variable
    // answer is of type string and can hold any string within it
    // there are many data types, such as int, bool, char, and many others
    printf("hello, %s\n", answer);
    //run make hello again in the terminal
    //then run the updated program
}
// in terminal to compile from source code in C to machine code (binary 0s and 1s)
// $ make hello
// $ ./(file name) to run the file