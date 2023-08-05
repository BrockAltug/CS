#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
#define LENGTH 45

// prototype for hash function
unsigned int hash(const char *word);

// load dictionary into memory
bool load(const char *dictionary);

// returns true if word is in dictionary, else false
bool check(const char *word);

// returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void);

// unloads dictionary from memory
bool unload(void);

#endif // DICTIONARY_H
