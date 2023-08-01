#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

typedef struct {
    char filename[8];
    FILE *fp;
} JPEGFile;

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

    int jpeg_counter = 0;
    JPEGFile *jpeg_files = NULL;

    BYTE block[BLOCK_SIZE];
    while (fread(block, 1, BLOCK_SIZE, forensic_image) == BLOCK_SIZE) {
        // Check for JPEG signatures
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0) {
            // Close the previous file (if any)
            if (jpeg_counter > 0) {
                fclose(jpeg_files[jpeg_counter - 1].fp);
            }

            // Create a new JPEG file
            snprintf(jpeg_files[jpeg_counter].filename, sizeof(jpeg_files[jpeg_counter].filename), "%03d.jpg", jpeg_counter);
            jpeg_files[jpeg_counter].fp = fopen(jpeg_files[jpeg_counter].filename, "w");
            if (jpeg_files[jpeg_counter].fp == NULL) {
                printf("Could not create the output JPEG file.\n");
                fclose(forensic_image);
                free(jpeg_files);
                return 1;
            }

            jpeg_counter++;
            jpeg_files = realloc(jpeg_files, jpeg_counter * sizeof(JPEGFile));
            if (jpeg_files == NULL) {
                printf("Memory allocation failed.\n");
                fclose(forensic_image);
                return 1;
            }
        }

        // Write the block to the current JPEG file
        if (jpeg_counter > 0) {
            fwrite(block, 1, BLOCK_SIZE, jpeg_files[jpeg_counter - 1].fp);
        }
    }

    // Close the last JPEG file (if any)
    if (jpeg_counter > 0) {
        fclose(jpeg_files[jpeg_counter - 1].fp);
    }

    // Free allocated memory
    free(jpeg_files);

    // Close the forensic image
    fclose(forensic_image);

    return 0;
}
