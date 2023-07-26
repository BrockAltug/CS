#include <cs50.h>
#include <stdio.h>

// method to find the max value in an array
int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        // Get the number of elements from the user
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    // get elements from the user and store them in the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    // find and print the max value in the array
    printf("The max value is %i.\n", max(arr, n));
}

// method to find the max value in an array
int max(int array[], int n)
{
    // initialize max value as the first element in the array
    int max_value = array[0];

    // go through the array to find the max value
    for (int i = 1; i < n; i++)
    {
        // update max_value if a larger element is found
        if (array[i] > max_value)
        {
            max_value = array[i];
        }
    }

    // return the max value
    return max_value;
}
