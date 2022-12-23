// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
// a linked list node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

node *createnode(char *str)
{
    node *llnode;
    llnode = malloc(sizeof(node));
    if (llnode == NULL)
    {
        return NULL;
    }
    strcpy(llnode->word, str);
    llnode->next = NULL;
    return llnode;
}

node *insertatbeg(char *str, int index)
{
    node *llnode = createnode(str);
    if (llnode == NULL)
    {
        return NULL;
    }
    llnode->next = table[index];
    return llnode;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *temp = table[index];
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        while (temp != NULL)
        {
            if (strcasecmp(temp->word, word) == 0)
            {
                return true;
            }
            temp = temp->next;
        }
    }
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int index;
    char buffer[100];
    FILE *test;
    test = fopen(dictionary, "r");
    if (test == NULL)
    {
        return false;
    }
    //read string from file
    while (fscanf(test, "%s", buffer) != EOF)
    {
        index = hash(buffer);
        table[index] = insertatbeg(buffer, index);
        if (table[index] == NULL)
        {
            return false;
        }
    }
    fclose(test);
    return true;


    /*
    while(fread(buffer,6,1,test))
    {
        index = hash(buffer);
        if(table[index]==NULL)
        {
            table[index] = createnode(buffer);
        }
        else
        {
            table[index] = insertatbeg(buffer,index);
        }
    }
    */
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    node *temp;
    for (int i = 0; i < N; i++)
    {
        temp = table[i];
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
    }
    if (count != 0)
    {
        return count;
    }
    else
    {
        return 0;
    }
    // TODO
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *temp;
    node *cursor;
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }
    return true;
    // TODO
}
