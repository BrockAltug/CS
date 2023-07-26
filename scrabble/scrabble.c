#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// method for the score
int compute_score(string word);

int main(void)
{
    // get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // score both players words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // display the winner
    //if player 1 word has a higher score than player 2
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    //else if player 2 word has a higher score than player 1
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    //else the scores are tied
    else
    {
        printf("Tie!\n");
    }
}

// method to compute the score for a given word
int compute_score(string word)
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert the letter to uppercase
        char c = toupper(word[i]);
        // Check if the character is a letter
        if (isalpha(c))
        {
            // Use the character value to get the index in the point array
            score += POINTS[c - 'A'];
        }
    }
    //return the score
    return score;
}
