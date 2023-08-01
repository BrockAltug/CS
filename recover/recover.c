#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 2) {
        printf("Usage: %s <forensic_image>\n", argv[0]);
        return 1;
    }

    // Open the forensic image
    FILE *forensic_image = fopen(argv[1], "r");
    if (forensic_image == NULL) {
        printf("Could not open the forensic image.\n");
        return 1;
    }

    // Initialize variables for JPEG recovery
    BYTE buffer[BLOCK_SIZE];
    int jpeg_counter = 0;
    FILE *jpeg_file = NULL;
    char filename[8];

    // Read the forensic image block by block
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, forensic_image) == BLOCK_SIZE) {
        // Check for the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // Close the previous JPEG file (if any)
            if (jpeg_file != NULL) {
                fclose(jpeg_file);
            }

            // Create a new JPEG file with the appropriate filename
            snprintf(filename, sizeof(filename), "%03d.jpg", jpeg_counter);
            jpeg_file = fopen(filename, "w");
            if (jpeg_file == NULL) {
                printf("Could not create the output JPEG file.\n");
                fclose(forensic_image);
                return 1;
            }

            // Increment the JPEG counter
            jpeg_counter++;
        }

        // Write the block to the current JPEG file (if it exists)
        if (jpeg_file != NULL) {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, jpeg_file);
        }
    }

    // Close the last JPEG file (if any)
    if (jpeg_file != NULL) {
        fclose(jpeg_file);
    }

    // Close the forensic image
    fclose(forensic_image);

    return 0;
}
