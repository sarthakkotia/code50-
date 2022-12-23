#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
// typedef is a keyword which lets to create own data type
// struct tells the compiler that it isn't simple it has some dimensions
{
    //so the data type has two dimensions a name and no. of votes

    string name;
    int votes;
}
// datatype name
candidate;

// Array of candidates
candidate candidates[MAX];
// candidates is the name of array and having the datatype of candidate which have the Maximum value of 9

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        // ie only one person available to vote which is not possible
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        // it is mentioned that maximum no of candidates is MAX=9
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int length = strlen(name);
    for(int i=0;i<candidate_count;i++)
    {
        if(name[0]==candidates[i].name[0])
        {
            for(int k=0;k<length;k++)
            {
                if(name[k]!=candidates[i].name[k])
                {
                    return false;
                }
            }
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int votes[candidate_count];
    int highestvote=0;
    for (int i=0;i<candidate_count;i++)
    {
        votes[i] = candidates[i].votes;
    }
    int votesduplicate[candidate_count];
    for (int i=0;i<candidate_count;i++)
    {
        votesduplicate[i] = candidates[i].votes;
    }

    for(int i=0;i<candidate_count-1;i++)
    {
        if(votes[i]>highestvote)
        {
            highestvote = votes[i];
        }
    }

    for(int j=0;j<candidate_count;j++)
    {
        if(candidates[j].votes==highestvote)
        {
            printf("%s\n",candidates[j].name);
        }
    }
}