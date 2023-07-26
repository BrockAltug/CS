#include <cs50.h>
#include <stdio.h>

//Method 1
//int main(void)
//{
//    string name = get_string("What's your name? ");
//    printf("hello, %s\n", name);
//}
//-----------------------------------------------------
//Method 2
//int main(int argc, string argv[])
//{
//    if (argc == 2)
//    {
//        printf("hello, %s\n", argv[1]);
//    }
//    else
//    {
//        printf("hello, world\n");
//    }
//}
//-------------------------------------------------------
//Method 3
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}
//-------------------------------------------------------

