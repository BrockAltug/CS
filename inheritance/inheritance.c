#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the structure for a person
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

// constants for generations and indentation
const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

// Main method
int main(void)
{
    // seed random number generator
    srand(time(0));

    // create a new family with three generations
    person *p = create_family(GENERATIONS);

    // print family tree of blood types
    print_family(p, 0);

    // free memory
    free_family(p);
}

// method to create a family tree
person *create_family(int generations)
{
    // allocate memory for new person
    person *new_person = malloc(sizeof(person));

    // if there are still generations left to create
    if (generations > 1)
    {
        // create two new parents for the current person
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // set parent pointers for the current person
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;

        // randomly assign current person's alleles based on parents' alleles
        new_person->alleles[0] = parent0->alleles[rand() % 2];
        new_person->alleles[1] = parent1->alleles[rand() % 2];
    }
    else
    {
        // set parent pointers to NULL
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;

        // randomly assign alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    // return the newly created person
    return new_person;
}

// method to free memory of the family tree
void free_family(person *p)
{
    // handle base case
    if (p == NULL)
    {
        return;
    }

    // free parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // free child
    free(p);
}

// method to print the family tree
void print_family(person *p, int generation)
{
    if (p == NULL)
    {
        return;
    }

    // print appropriate indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // determine the relationship and print blood type
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // print parents
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// method to generate a random allele
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
