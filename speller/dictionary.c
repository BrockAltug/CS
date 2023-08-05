#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// number of buckets in hash table
const unsigned int N = 65536;

// hash table
node *table[N];

// converts a word to lowercase
void toLowercase(char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        word[i] = tolower(word[i]);
    }
}

// returns true if word is in dictionary, else false
bool check(const char *word)
{
    char lowercase_word[LENGTH + 1];
    strcpy(lowercase_word, word);
    toLowercase(lowercase_word);

    // hash word to get index
    unsigned int index = hash(lowercase_word);

    // search for word in the linked list at the index
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcmp(cursor->word, lowercase_word) == 0)
        {
            return true;
        }
    }
    return false;
}

// hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

// loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // initialize hash table
    for (unsigned int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // create a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        toLowercase(word);
        strcpy(new_node->word, word);

        // hash the word to determine the index
        unsigned int index = hash(word);

        // insert the node into the linked list at the index
        new_node->next = table[index];
        table[index] = new_node;
    }

    fclose(file);
    return true;
}

// returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int word_count = 0;

    // iterate through each bucket in the hash table
    for (unsigned int i = 0; i < N; i++)
    {
        // traverse the linked list at the bucket
        for (node *cursor = table[i]; cursor != NULL; cursor = cursor->next)
        {
            word_count++;
        }
    }

    return word_count;
}

// unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate through each bucket in the hash table
    for (unsigned int i = 0; i < N; i++)
    {
        // traverse the linked list at the bucket
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = temp->next;
            free(temp);
        }
    }
    return true;
}
