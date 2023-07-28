#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./license infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[8]; // Change the size to 8 to accommodate NUL terminator

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    if (infile == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    int idx = 0;

    // Read each line from the file and store the plate numbers in the array
    while (fgets(buffer, sizeof(buffer), infile))
    {
        // Remove the trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Allocate memory for the plate number
        plates[idx] = (char *) malloc(strlen(buffer) + 1);

        if (plates[idx] == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Copy the plate number into the allocated memory
        strcpy(plates[idx], buffer);
        idx++;
    }

    fclose(infile);

    for (int i = 0; i < idx; i++)
    {
        printf("%s\n", plates[i]);
        free(plates[i]); // Free the allocated memory
    }

    return 0;
}
