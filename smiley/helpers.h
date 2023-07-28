#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} RGBTRIPLE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: colorize infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "wb");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 3;
    }

    // read BITMAPFILEHEADER
    BYTE bf[14];
    fread(&bf, sizeof(BYTE), 14, inptr);

    // read BITMAPINFOHEADER
    BYTE bi[40];
    fread(&bi, sizeof(BYTE), 40, inptr);

    // Ensure infile is a 24-bit uncompressed BMP 4.0
    if (bf[0] != 'B' || bf[1] != 'M' || bi[14] != 40 || bi[28] != 24)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 4;
    }

    int width = bi[18] + (bi[19] << 8) + (bi[20] << 16) + (bi[21] << 24);
    int height = bi[22] + (bi[23] << 8) + (bi[24] << 16) + (bi[25] << 24);

    // allocate memory for image
    RGBTRIPLE *image = malloc(width * height * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        printf("Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 5;
    }

    // read image data
    fread(image, sizeof(RGBTRIPLE), width * height, inptr);

    // iterate over pixels
    for (int i = 0; i < width * height; i++)
    {
        // Check if pixel is black (R=0, G=0, B=0)
        if (image[i].rgbtRed == 0 && image[i].rgbtGreen == 0 && image[i].rgbtBlue == 0)
        {
            // Change color to red (R=255, G=0, B=0)
            image[i].rgbtRed = 255;
            image[i].rgbtGreen = 0;
            image[i].rgbtBlue = 0;
        }
    }

    // write BITMAPFILEHEADER and BITMAPINFOHEADER
    fwrite(&bf, sizeof(BYTE), 14, outptr);
    fwrite(&bi, sizeof(BYTE), 40, outptr);

    // write image data
    fwrite(image, sizeof(RGBTRIPLE), width * height, outptr);

    // free memory for image
    free(image);

    // close files
    fclose(inptr);
    fclose(outptr);

    return 0;
}
