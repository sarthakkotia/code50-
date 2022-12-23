#include <cs50.h>
#include <stdio.h>
#include<string.h>

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
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
// vote fnction takes an integar called voter representing which number voter is currently voting rank representing which rank its going to give 0=1st pref
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    int preferences2[100][9];
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
    // the loop to check if name is valid
    for (int i = 0; i < candidate_count; i++)
    {
        //strcmp return 0 if name == candidates[i].name
        if (!(strcmp(name, candidates[i].name)))
        {
            //the candidates's number is i
            // upodate the global preferences arrayto indicate that the voter voter has that candidate as their rank preference (where 0 is the first preference, 1 is the second preference, etc.).
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //The function should update the number of votes each candidate has at this stage in the runoff.
    // a rank integar declared will be used later this integar will be used when the voter's forst choice has been eliminated and then we need that same voter's second choice to get to that second choice we would use the rank variable
    int rank = 0;
    //the code here starts we go by a per candidate basis ie to calculate total number of votes per candidate instead of iterating through the preferences table we look for the candidate code number like alice for 0.... in the first preference of the voters if the first preference is eliminated then we will explain it later
    for (int i = 0; i < candidate_count; i++)
    {
        //loop to iterate over voters and check for their first preference is the candidate selected
        for (int j = 0; j < voter_count; j++)
        {
            // here rank is redefined ifso it has been manipulated by the do while later
            rank = 0;
            // if voter's j 1st preference is the candidate code which is being mentioned in the for loop then
            if (preferences[j][0] == i)
            {
                //also check if the caandidate is eliminated or not
                if (candidates[i].eliminated == false)
                {
                    //if the candidate is not eliminated then increase the candidate's votes
                    candidates[i].votes++;
                }
                else
                {
                    //if the candidate is eliminated then
                    // this check variable is to escape the do while loop
                    int check;
                    do
                    {
                        //here we use the rank variable declared earlier ancd increase it value by one to move to the next preference
                        rank++;
                        // we use this loop to identify the next preference candidate
                        for (int k = 0; k < candidate_count; k++)
                        {
                            // if the next preferred candidate is found and not eliminated
                            if (preferences[j][rank] == k && candidates[k].eliminated == false)
                            {
                                //increase it votes note this is independent of the loop for individual candidate loop at starting here this loop is just for this paritcualer voter whose first preference has been eliminated
                                candidates[k].votes++;
                                //update check so that we can escape the loop as now the while condition will be incorrect
                                check = k;
                            }
                        }
                    }
                    // do this loop until the correct match is not found
                    while (preferences[j][rank] != check);
                }
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO// if any candidate has more than half of the vote then winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
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
    // TODO
    // return the minimum number of votes of anyone still in the election
    int min = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // returns true is the election is tied between ll the remaining candidates otherwise false
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min && candidates[i].eliminated == false)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // eliminate the candidate who is in the last place in the elecion such that the election can run again
    // eliminate the person who has the min number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}