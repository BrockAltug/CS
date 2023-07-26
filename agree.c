#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user to agree with new char value c
    char c = get_char("Do you agree? Y/N");

    // check whether agreed
    // if user answer is caps Y || (or) lowercase y
    // single Char are in single quotes ' '
    if (c == 'Y' || c == 'y')
    {
        // display agreed and a \n new line
        // double quotes for String " "
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}