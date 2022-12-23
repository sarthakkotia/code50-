#include "helpers.h"
#include <math.h>
// extra
#include <stdio.h>
// helpers.h only conatins the prototypes of the functions defined here
// non of the use right now

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // So to convert a pixel to grayscale, we just need to make sure the red, green, and blue values are all the same value. But how do we know what value to make them? Well, it’s probably reasonable to expect that if the original red, green, and blue values were all pretty high, then the new value should also be pretty high. And if the original values were all low, then the new value should also be low.

    // In fact, to ensure each pixel of the new image still has the same general brightness oimage[i][j].rgbtReddarkness as the old image, we can take the average of the red, green, and blue values to determine what shade of grey to make the new pixel.

    // If you apply that to each pixel in the image, the result will be an image converted to grayscale
    BYTE avg;
    float favg;
    // this loop to vary through height of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // what is the value of R,G,image[i][j].rgbtBlue of that image find the maximum value of them and then make the otheimage[i][j].rgbtRedtwo ones same value as this one
            // find the maximum of these values
            avg = (BYTE)((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            favg = ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // round of if in float value its>=0.5
            if ((favg - avg) >= 0.5)
            {
                avg++;
            }
            // now convert the others to max
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // There are a number of algorithms for converting an image to sepia, but for this problem, we’ll ask you to use the following algorithm. For each pixel, the sepia color values should be calculated based on the original color values per the below.

    // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    // Of course, the result of each of these formulas may not be an integer, but each value could be rounded to the nearest integer. It’s also possible that the result of the formula is a number greater than 255, the maximum value for an 8-bit color value. In that case, the red, green, and blue values should be capped at 255. As a result, we can guarantee that the resulting red, green, and blue values will be whole numbers between 0 and 255, inclusive.
    BYTE sepiaRed;
    BYTE sepiaGreen;
    BYTE sepiaBlue;
    float fsepiaRed;
    float fsepiaGreen;
    float fsepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            sepiaRed = (int)(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            fsepiaRed = (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            // round off
            if ((fsepiaRed - sepiaRed) >= 0.5)
            {
                sepiaRed++;
            }
            // as sepiaRed could only store till 255 therefore it would return wrong answer when answer is >255 in that case use the calculated floating point value to make it correct and set sepiared to max 255
            if (fsepiaRed >= 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = (int)(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            fsepiaGreen = (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            if ((fsepiaGreen - sepiaGreen) >= 0.5)
            {
                sepiaGreen++;
            }

            if (fsepiaGreen >= 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = (int)(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            fsepiaBlue = (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if ((fsepiaBlue - sepiaBlue) >= 0.5)
            {
                sepiaBlue++;
            }

            if (fsepiaBlue >= 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Some filters might also move pixels around. Reflecting an image, for example, is a filter where the resulting image is what you would get by placing the original image in front of a mirror. So any pixels on the left side of the image should end up on the right, and vice versa.

    // Note that all of the original pixels of the original image will still be present in the reflected image, it’s just that those pixels may have rearranged to be in a different place in the image.
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Bluimage[i][j].rgbtRedimage
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of image of height +2 , width+2 and set the rest values to be 0 of the +2 heihgt pixels and similarly +2 width pixels
    RGBTRIPLE copy[height + 2][width + 2];

    // inner border
    // rows
    int ci = 0;
    int cl = height + 1;
    for (int q = 0; q < height + 2; q++)
    {
        for (int w = 0; w < width + 2; w++)
        {
            // top row
            if (q == 0)
            {
                copy[q][w].rgbtRed = 0;
                copy[q][w].rgbtGreen = 0;
                copy[q][w].rgbtBlue = 0;
            }
            // bottom row
            if (q == height + 1)
            {
                copy[q][w].rgbtRed = 0;
                copy[q][w].rgbtGreen = 0;
                copy[q][w].rgbtBlue = 0;
            }
        }
        copy[q][ci].rgbtRed = 0;
        copy[q][ci].rgbtGreen = 0;
        copy[q][ci].rgbtBlue = 0;
        copy[q][cl].rgbtRed = 0;
        copy[q][cl].rgbtGreen = 0;
        copy[q][cl].rgbtBlue = 0;
    }

    // outer border
    for (int k = 1; k < height + 1; k++)
    {
        for (int l = 1; l < width + 1; l++)
        {
            copy[k][l] = image[k - 1][l - 1];
        }
    }

    // code to blur for all except border

    int integar[3];
    float floats[3];
    int cornersi[3];
    float cornersf[3];
    int rowsi[3];
    float rowsf[3];

    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            // for corners
            if ((i == 1 && j == 1) || (i == 1 && j == width) || (i == height && j == 1) || (i == height && j == width))
            {
                cornersi[0] = ((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                                copy[i + 1][j + 1].rgbtRed) / 4);
                cornersi[1] = ((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen +
                                copy[i + 1][j + 1].rgbtGreen) / 4);
                cornersi[2] = ((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                                copy[i + 1][j + 1].rgbtBlue) / 4);

                cornersf[0] = ((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                                copy[i + 1][j + 1].rgbtRed) / 4.0);
                cornersf[1] = ((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen +
                                copy[i + 1][j + 1].rgbtGreen) / 4.0);
                cornersf[2] = ((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                                copy[i + 1][j + 1].rgbtBlue) / 4.0);

                for (int h = 0; h < 3; h++)
                {
                    if (cornersf[h] - cornersi[h] >= 0.5)
                    {
                        cornersi[h]++;
                    }
                    if (cornersi[h] > 255)
                    {
                        cornersi[h] = 255;
                    }
                }
                image[i - 1][j - 1].rgbtRed = cornersi[0];
                image[i - 1][j - 1].rgbtGreen = cornersi[1];
                image[i - 1][j - 1].rgbtBlue = cornersi[2];
            }
            // for border rows
            else if ((i == 1) || (i == height) || (j == 1) || (j == width))
            {
                rowsi[0] = ((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                             copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                             copy[i + 1][j + 1].rgbtRed) / 6);
                rowsi[1] = ((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                             copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen +
                             copy[i + 1][j + 1].rgbtGreen) / 6);
                rowsi[2] = ((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                             copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                             copy[i + 1][j + 1].rgbtBlue) / 6);

                rowsf[0] = ((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                             copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                             copy[i + 1][j + 1].rgbtRed) / 6.0);
                rowsf[1] = ((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                             copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen +
                             copy[i + 1][j + 1].rgbtGreen) / 6.0);
                rowsf[2] = ((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                             copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                             copy[i + 1][j + 1].rgbtBlue) / 6.0);

                for (int h = 0; h < 3; h++)
                {
                    if (rowsf[h] - rowsi[h] >= 0.5)
                    {
                        rowsi[h]++;
                    }
                    if (rowsi[h] > 255)
                    {
                        rowsi[h] = 255;
                    }
                }

                image[i - 1][j - 1].rgbtRed = rowsi[0];
                image[i - 1][j - 1].rgbtGreen = rowsi[1];
                image[i - 1][j - 1].rgbtBlue = rowsi[2];
            }
            // for rest
            else
            {
                integar[0] = ((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                               copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                               copy[i + 1][j + 1].rgbtRed) / 9);
                integar[1] = ((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                               copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen +
                               copy[i + 1][j + 1].rgbtGreen) / 9);
                integar[2] = ((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                               copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                               copy[i + 1][j + 1].rgbtBlue) / 9);

                floats[0] = ((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                              copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed +
                              copy[i + 1][j + 1].rgbtRed) / 9.0);
                floats[1] = ((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                              copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen +
                              copy[i + 1][j + 1].rgbtGreen) / 9.0);
                floats[2] = ((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                              copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue +
                              copy[i + 1][j + 1].rgbtBlue) / 9.0);

                for (int h = 0; h < 3; h++)
                {
                    if (floats[h] - integar[h] >= 0.5)
                    {
                        integar[h]++;
                    }
                    if (integar[h] > 255)
                    {
                        integar[h] = 255;
                    }
                }

                image[i - 1][j - 1].rgbtRed = integar[0];
                image[i - 1][j - 1].rgbtGreen = integar[1];
                image[i - 1][j - 1].rgbtBlue = integar[2];
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of image of height +2 , width+2 and set the rest values to be 0 of the +2 heihgt pixels and similarly +2 width pixels
    RGBTRIPLE copy[height + 2][width + 2];

    // inner border
    // rows
    int ci = 0;
    int cl = height + 1;
    for (int q = 0; q < height + 2; q++)
    {
        for (int w = 0; w < width + 2; w++)
        {
            // top row
            if (q == 0)
            {
                copy[q][w].rgbtRed = 0;
                copy[q][w].rgbtGreen = 0;
                copy[q][w].rgbtBlue = 0;
            }
            // bottom row
            if (q == height + 1)
            {
                copy[q][w].rgbtRed = 0;
                copy[q][w].rgbtGreen = 0;
                copy[q][w].rgbtBlue = 0;
            }
        }
        copy[q][ci].rgbtRed = 0;
        copy[q][ci].rgbtGreen = 0;
        copy[q][ci].rgbtBlue = 0;
        copy[q][cl].rgbtRed = 0;
        copy[q][cl].rgbtGreen = 0;
        copy[q][cl].rgbtBlue = 0;
    }

    // outer border
    for (int k = 1; k < height + 1; k++)
    {
        for (int l = 1; l < width + 1; l++)
        {
            copy[k][l] = image[k - 1][l - 1];
        }
    }

    int Gxi[3];
    int Gyi[3];
    int Gfinali[3];
    float Gfinalf[3];

    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            Gxi[0] = (copy[i][j].rgbtRed * 0 + copy[i][j + 1].rgbtRed * 2 + copy[i][j - 1].rgbtRed * (-2) +
                      copy[i - 1][j - 1].rgbtRed * (-1) + copy[i - 1][j].rgbtRed * 0 + copy[i - 1][j + 1].rgbtRed * 1 +
                      copy[i + 1][j - 1].rgbtRed * (-1) + copy[i + 1][j].rgbtRed * 0 + copy[i + 1][j + 1].rgbtRed * 1);
            Gxi[1] = (copy[i][j].rgbtGreen * 0 + copy[i][j + 1].rgbtGreen * 2 + copy[i][j - 1].rgbtGreen * (-2) +
                      copy[i - 1][j - 1].rgbtGreen * (-1) + copy[i - 1][j].rgbtGreen * 0 + copy[i - 1][j + 1].rgbtGreen * 1 +
                      copy[i + 1][j - 1].rgbtGreen * (-1) + copy[i + 1][j].rgbtGreen * 0 + copy[i + 1][j + 1].rgbtGreen * 1);
            Gxi[2] = (copy[i][j].rgbtBlue * 0 + copy[i][j + 1].rgbtBlue * 2 + copy[i][j - 1].rgbtBlue * (-2) +
                      copy[i - 1][j - 1].rgbtBlue * (-1) + copy[i - 1][j].rgbtBlue * 0 + copy[i - 1][j + 1].rgbtBlue * 1 +
                      copy[i + 1][j - 1].rgbtBlue * (-1) + copy[i + 1][j].rgbtBlue * 0 + copy[i + 1][j + 1].rgbtBlue * 1);

            Gyi[0] = (copy[i][j].rgbtRed * 0 + copy[i][j + 1].rgbtRed * 0 + copy[i][j - 1].rgbtRed * 0 +
                      copy[i - 1][j - 1].rgbtRed * (-1) + copy[i - 1][j].rgbtRed * (-2) + copy[i - 1][j + 1].rgbtRed * (-1) +
                      copy[i + 1][j - 1].rgbtRed * (1) + copy[i + 1][j].rgbtRed * 2 + copy[i + 1][j + 1].rgbtRed * 1);
            Gyi[1] = (copy[i][j].rgbtGreen * 0 + copy[i][j + 1].rgbtGreen * 0 + copy[i][j - 1].rgbtGreen * 0 +
                      copy[i - 1][j - 1].rgbtGreen * (-1) + copy[i - 1][j].rgbtGreen * (-2) + copy[i - 1][j + 1].rgbtGreen * (-1) +
                      copy[i + 1][j - 1].rgbtGreen * (1) + copy[i + 1][j].rgbtGreen * 2 + copy[i + 1][j + 1].rgbtGreen * 1);
            Gyi[2] = (copy[i][j].rgbtBlue * 0 + copy[i][j + 1].rgbtBlue * 0 + copy[i][j - 1].rgbtBlue * 0 +
                      copy[i - 1][j - 1].rgbtBlue * (-1) + copy[i - 1][j].rgbtBlue * (-2) + copy[i - 1][j + 1].rgbtBlue * (-1) +
                      copy[i + 1][j - 1].rgbtBlue * (1) + copy[i + 1][j].rgbtBlue * 2 + copy[i + 1][j + 1].rgbtBlue * 1);


            for (int e = 0; e < 3; e++)
            {
                Gfinali[e] = sqrt((Gxi[e] * Gxi[e]) + (Gyi[e] * Gyi[e]));
                Gfinalf[e] = sqrt((Gxi[e] * Gxi[e]) + (Gyi[e] * Gyi[e]));
            }

            for (int h = 0; h < 3; h++)
            {
                if (Gfinalf[h] - Gfinali[h] >= 0.5)
                {
                    Gfinali[h]++;
                }
                if (Gfinali[h] > 255)
                {
                    Gfinali[h] = 255;
                }
            }

            image[i - 1][j - 1].rgbtRed = Gfinali[0];
            image[i - 1][j - 1].rgbtGreen = Gfinali[1];
            image[i - 1][j - 1].rgbtBlue = Gfinali[2];
        }
    }
    return;
}
