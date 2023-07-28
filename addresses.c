#include <cs50.h>
#include <stdio.h>

// Main method
// int main(void)
// {
//     // declare an integer variable 'n' and set its value to 50
//     int n = 50;

//     // declare an integer pointer 'p' and point it to the memory address of 'n'
//     int *p = &n;

//     // print the value that 'p' points to, which is the value of 'n'
//     printf("%i\n", *p);
// }

// // -----------------------------

// // Main method
// int main(void)
// {
//     // declare a string variable 's' and initialize it with the value "HI!"
//     string s = "HI!";

//     // print the memory address of the 's' variable.
//     printf("%p\n", s);

//     // print the memory address of the first character of the 's' string
//     printf("%p\n", &s[0]);

//     // print the memory address of the second character of the 's' string
//     printf("%p\n", &s[1]);

//     // print the memory address of the third character of the 's' string
//     printf("%p\n", &s[2]);

//     // print the memory address of the fourth character of the 's' string
//     printf("%p\n", &s[3]);
// }

// // -------------------------------

// // Main method
// int main(void)
// {
//     // declare a character pointer 's' and point it to the memory address where the string "HI!" is stored
//     char *s = "HI!";

//     // print the first character of the string 's'
//     printf("%c\n", s[0]);

//     // print the second character of the string 's'
//     printf("%c\n", s[1]);

//     // print the third character of the string 's'
//     printf("%c\n", s[2]);
// }

// -----------------------------

// Main method
int main(void)
{
    // declare a character pointer 's' and point it to the memory address where the string "HI!" is stored
    char *s = "HI!";

    // print the entire string 's'
    printf("%s\n", s);
}
