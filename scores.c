#include <cs50.h>
#include <stdio.h>

int main(void)
{
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
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}