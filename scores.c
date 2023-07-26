#include <cs50.h>
#include <stdio.h>

//int main(void)
//{
    // Scores
    //int score1 = 72;
    //int score2 = 73;
    //int score3 = 33;

    // Print average
    //printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
    //-------------------------------------------------------------------
    // Scores
    //int scores[3];
    //scores[0] = 72;
    //scores[1] = 73;
    //scores[2] = 33;

    // Print average
    //printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
    //--------------------------------------------------------------------
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
