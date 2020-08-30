#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 5381; /*3581;*/
//tb funciona se: const unsigned int N = 3581;

node *table[N];
int wordCounter = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char tempoString[LENGTH + 1];
    int len = strlen(word);

    for (int ch = 0; ch < len; ch++)
    {
        tempoString[ch] = tolower(word[ch]);
    }
    tempoString[len] = '\0';

    int valueToLookFor = hash(tempoString);
    node *cursor = table[valueToLookFor];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, tempoString) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number -  //from http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;

    //tb funciona se: unsigned long hash = 3581;
    int c = 0;
    while (c == *word++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    //tb funciona se return hash % N;
    return hash / N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        //fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }
    char word[LENGTH + 1]; //+1 para abrigar o '\0'
    while (fscanf(inptr, "%s", word) != EOF)
    {
        // printf("%s\n", word);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }
        else
        {
            strcpy(n->word, word);
            //int ind = hash(word); //isto da-me o hashing index
            int ind = hash(n->word); //isto da-me o hashing index
            if (table[ind] == NULL)
            {
                table[ind] = n;
                n->next = NULL;
                wordCounter++;
            }
            else
            {
                n->next = table[ind];
                table[ind] = n;
                wordCounter++;
            }
        }
    }
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCounter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++) // percorrer a table até ao fim dos baldes
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor; //temp serve para cursor poder avançar sem perder a ligaçao com o resto das LL à medida q se liberta a memoria
            cursor = cursor->next;
            free(temp); //libertar temp
        }

        free(cursor); // libertar o cursor
    }

    return true;
}
