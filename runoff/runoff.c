#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// methods
// boolean for vote using voter, rank, and name
bool vote(int voter, int rank, string name);
// void tabulate
void tabulate(void);
// boolean to for print_winner
bool print_winner(void);
// int variable to find the min
int find_min(void);
// boolean to check tie
bool is_tie(int min);
// void to eliminate
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Check if the candidate name is valid
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Update the voter's preference for the candidate
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Clear votes for all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }

    // Count the top preferences for each voter
    for (int i = 0; i < voter_count; i++)
    {
        int top_preference = 0;
        while (candidates[preferences[i][top_preference]].eliminated)
        {
            top_preference++;
        }
        candidates[preferences[i][top_preference]].votes++;
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // majority is the count divided by 2 + 1
    int majority = (voter_count / 2) + 1;
    // starting from 0 until the count check the next one
    for (int i = 0; i < candidate_count; i++)
    {
        // if the candidate has more votes than the majority
        if (candidates[i].votes >= majority)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // set to max value initially
    int min_votes = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        // if the candidate is not eliminated and the votes are less than min
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            // assign the new minimum to the candidate
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // starting from 0 until the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        // if they are not eliminated and vote count is not minimum for either
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            // return false
            return false;
        }
    }
    // else return true
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // starting from 0 until the candidate count, check the next
    for (int i = 0; i < candidate_count; i++)
    {
        // if the candidates index vote is the min
        if (candidates[i].votes == min)
        {
            // candidate is eliminated
            candidates[i].eliminated = true;
        }
    }
}
