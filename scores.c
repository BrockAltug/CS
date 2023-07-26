// Include the cs50 library for get_int() function
#include <cs50.h>
// Include the standard input/output library
#include <stdio.h>

// Different methods to calculate the average of 3 scores

// Method 1: Using individual variables
//int main(void)
//{
    // Method 1: Using individual variables
    // Scores
    //int score1 = 72;
    //int score2 = 73;
    //int score3 = 33;

    // Print average
    //printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
    //---------------------------------------------------------------------------

    // Method 2: Using an array
    // Scores
    //int scores[3];
    //scores[0] = 72;
    //scores[1] = 73;
    //scores[2] = 33;

    // Print average
    //printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
    //---------------------------------------------------------------------------

    // Method 3: Using a loop to get scores from the user
    // Get scores
    //int scores[3];
    //for (int i = 0; i < 3; i++)
    //{
    //    scores[i] = get_int("Score: ");
    //}

    // Print average
    //printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
//}
//---------------------------------------------------------------------------

// Method 4: Using a separate function to calculate the average
// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}

// Function to calculate the average of an array of integers
float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
