#include "helpers.h"
#include <math.h>

// Function to calculate the average of RGB values
RGBTRIPLE getAverageRGB(RGBTRIPLE pixel1, RGBTRIPLE pixel2, RGBTRIPLE pixel3, RGBTRIPLE pixel4)
{
    int totalRed = pixel1.rgbtRed + pixel2.rgbtRed + pixel3.rgbtRed + pixel4.rgbtRed;
    int totalGreen = pixel1.rgbtGreen + pixel2.rgbtGreen + pixel3.rgbtGreen + pixel4.rgbtGreen;
    int totalBlue = pixel1.rgbtBlue + pixel2.rgbtBlue + pixel3.rgbtBlue + pixel4.rgbtBlue;

    RGBTRIPLE averagePixel;
    averagePixel.rgbtRed = round((float)totalRed / 4);
    averagePixel.rgbtGreen = round((float)totalGreen / 4);
    averagePixel.rgbtBlue = round((float)totalBlue / 4);

    return averagePixel;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            // Calculate the average of red, green, and blue values
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            // Set all RGB values to the calculated average
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            // Calculate new RGB values using sepia formulas
            int sepiaRed = round(0.393 * pixel.rgbtRed + 0.769 * pixel.rgbtGreen + 0.189 * pixel.rgbtBlue);
            int sepiaGreen = round(0.349 * pixel.rgbtRed + 0.686 * pixel.rgbtGreen + 0.168 * pixel.rgbtBlue);
            int sepiaBlue = round(0.272 * pixel.rgbtRed + 0.534 * pixel.rgbtGreen + 0.131 * pixel.rgbtBlue);

            // Cap values at 255
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels from left to right to reflect horizontally
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    // Make a copy of the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j] = image[i][j];
        }
    }

    // Apply blur effect to the original image using averages from the temporary image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Define the surrounding pixels for averaging (including the current one)
            RGBTRIPLE pixel1 = (i > 0) ? tempImage[i - 1][j] : tempImage[i][j];
            RGBTRIPLE pixel2 = (j > 0) ? tempImage[i][j - 1] : tempImage[i][j];
            RGBTRIPLE pixel3 = (i < height - 1) ? tempImage[i + 1][j] : tempImage[i][j];
            RGBTRIPLE pixel4 = (j < width - 1) ? tempImage[i][j + 1] : tempImage[i][j];

            // Calculate the average of RGB values and update the original pixel
            image[i][j] = getAverageRGB(pixel1, pixel2, pixel3, pixel4);
        }
    }
}
