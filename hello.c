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
    
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
// in terminal to compile from source code in C to machine code (binary 0s and 1s)
// $ make hello
// $ ./(file name) to run the file