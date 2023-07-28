#include "bmp.h"


typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} RGBTRIPLE;
// colorize image
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Define the new red color value
    BYTE newRed = 0xFF; // Full red value (255)

    // Iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check if the pixel color is black (R=0, G=0, B=0)
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // Change the color to red by setting the red value to newRed (255) and the others to 0 (black).
                image[i][j].rgbtRed = newRed;
                image[i][j].rgbtGreen = 0x00; // Green = 0
                image[i][j].rgbtBlue = 0x00;  // Blue = 0
            }
        }
    }
}
