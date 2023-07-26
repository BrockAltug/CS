#include <cs50.h>
#include <stdio.h>
#include <string.h>

// The maximum number of candidates
#define MAX 9

// Define a candidate struct
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates in the election
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for correct number of command-line arguments
    if (argc < 2)
    {
        printf("Usage: %s candidate1 candidate2 ...", argv[0]);
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Get number of voters
    int voter_count = get_int("Number of voters: ");

    // Process votes
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner(s) of the election
    print_winner();
    return 0;
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Search for the candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    // If candidate not found, return false
    return false;
}

// Print the winner(s) of the election
void print_winner(void)
{
    int max_votes = 0;

    // Find the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print the candidate(s) with maximum votes (potential winners)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
