#include "helpers.h"

// colorize method
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // go over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // check if the pixel is black (all RGB components are 0)
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // set the pixel to red (max value red, no green or blue)
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 0;
                image[i][j].rgbtBlue = 0;
            }
        }
    }
}
