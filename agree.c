#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to agree with new char value c
    char c = get_char("Do you agree? Y/N");

    // Check whether agreed
    //if user answer is caps Y || (or) lowercase y
    if (c == 'Y' || c == 'y')
    {
        //display agreed and a \n new line
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}