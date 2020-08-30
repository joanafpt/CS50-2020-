#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

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
        printf("Usage: plurality [candidate ...]\n");
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
    // for (int q = 0; q < MAX; q++) //TRY THIS - prob aqui
    for (int q = 0; q < candidate_count; q++)
    {
        if (strcmp(name, candidates[q].name) == 0)
        {
            //update ao count de votos:
            candidates[q].votes = candidates[q].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    string mostVoted[candidate_count];

    int max = 0;

    for (int counter = 0; counter < candidate_count; counter++)
    {
        //se a quantudade de votos de um candidato for
        //maior do q o maximo,
        //o maximo passa a ser esse numero de votos (atualiza maximo)
        if (candidates[counter].votes > max)
        {
            max = candidates[counter].votes;
        }
    }

    for (int l = 0; l < candidate_count; l++)
    {   //se a qtidd de votos de um candidato é a quantidd max,
        //entao ele e um dos / o mais votado
        if (candidates[l].votes == max)
        {
            mostVoted[l] = candidates[l].name;
            printf("%s\n", mostVoted[l]);
        }
    }

    //  printf("\n");
}
