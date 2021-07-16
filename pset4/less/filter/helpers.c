#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int color_average_rounded, i, j; //Initialization of local variables
    float color_average_temp;
    for (i = 0; height > i; i++) //Loop on first row
    {
        for (j = 0; width > j; j++) //Loop on first row by column
        {
            color_average_temp = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0; //Calculate average; returns as float value
            color_average_rounded = round(color_average_temp); //Round out the float
            image[i][j].rgbtRed = color_average_rounded; //Set average;
            image[i][j].rgbtGreen = color_average_rounded;
            image[i][j].rgbtBlue = color_average_rounded;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    //sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    //sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    float sepiaRed, sepiaGreen, sepiaBlue;
    int i, j; //, sepiaRed, sepiaGreen, sepiaBlue, originalRed, originalGreen, originalBlue,
    for (i = 0; height > i; i++)
    {
        for (j = 0; width > j; j++)
        {
            //originalRed = image[i][j].rgbtRed;
            //originalGreen = image[i][j].rgbtGreen;
            //originalBlue = image[i][j].rgbtBlue;
            sepiaRed = 0.393 *  image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            sepiaGreen = 0.349 *  image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            sepiaBlue = 0.272 *  image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            //sepiaRed_temp = 0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue;
            //sepiaGreen_temp = 0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue;
            //sepiaBlue_temp = 0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue;
            //sepiaRed = round(sepiaRed_temp);
            //sepiaGreen = round(sepiaGreen_temp);
            //sepiaBlue = round(sepiaBlue_temp);
            if (sepiaRed > 255){ sepiaRed = 255; }
            if (sepiaGreen > 255){ sepiaGreen = 255; }
            if (sepiaBlue > 255){ sepiaBlue = 255; }
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half_width, temp_Red, temp_Green, temp_Blue, i, j;
    half_width = round(width / 2);
    for (i = 0; height > i; i++)
    {
        for (j = 0; half_width > j; j++)
        {
            temp_Red = image[i][j].rgbtRed; //Holds original pixel value
            temp_Green = image[i][j].rgbtGreen;
            temp_Blue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed; //Overwrites one side with the other
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtRed = temp_Red;      //Overwrites one side that wasn't overwritten,
            image[i][width - j - 1].rgbtGreen = temp_Green;  //we swap the other side's original values which is stored in the temp
            image[i][width - j - 1].rgbtBlue = temp_Blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int first_row, first_column, last_row, last_col, sum_red, sum_green, sum_blue, c, i, j;
    //red_00, green_00, blue_00 || red_01, green_01, blue_01 || red_02, green_02, blue_02;
    //red_03, green_03, blue_03 || red_04, green_04, blue_04 || red_05, green_05, blue_05;
    //red_06, green_06, blue_06 || red_07, green_07, blue_07 || red_08, green_08, blue_08;
    //00_box, 01_box, 02_box;
    //03_box, XX_box, 05_box;   NOTE TO SELF: USE THIS TO VISUALIZE A 3x3 BOX!!
    //06_box, 07_box, 08_box;
    first_row = first_column = 0;
    last_row = height - 1;
    last_col = width - 1;

    RGBTRIPLE image_temp[height][width];
    for (i = 0; height > i; i++)
    {
        for (j = 0; width > j; j++)
        {
            image_temp[i][j] = image[i][j];
        }
    }
    for (i = 0; height > i; i++)
    {
        for (j = 0; width > j; j++)
        {
            c = sum_red = sum_green = sum_blue = 0;
            //first column
            if ((i - 1 >= first_row) && (j - 1 >= first_column))
            {
                sum_red += image_temp[i - 1][j - 1].rgbtRed;
                sum_green += image_temp[i - 1][j - 1].rgbtGreen;
                sum_blue += image_temp[i - 1][j - 1].rgbtBlue;
                c += 1;
            }
            //else { sum_red += 0; sum_green += 0; sum_blue += 0, c += 0; }
            if (j - 1 >= first_column)
            {
                sum_red += image_temp[i][j - 1].rgbtRed;
                sum_green += image_temp[i][j - 1].rgbtGreen;
                sum_blue += image_temp[i][j - 1].rgbtBlue;
                c += 1;
            }
            if ((j - 1 >= first_column) && (i + 1 <= last_row))
            {
                sum_red += image_temp[i + 1][j - 1].rgbtRed;
                sum_green += image_temp[i + 1][j - 1].rgbtGreen;
                sum_blue += image_temp[i + 1][j - 1].rgbtBlue;
                c += 1;
            }
            //second column
            if (i - 1 >= first_row)
            {
                sum_red += image_temp[i - 1][j].rgbtRed;
                sum_green += image_temp[i - 1][j].rgbtGreen;
                sum_blue += image_temp[i - 1][j].rgbtBlue;
                c += 1;
            }
            if ((i >= first_row) && (j >= first_column) && (i <= last_row) && (j <= last_col)) //CENTER OF 3 x 3
            {
                sum_red += image_temp[i][j].rgbtRed;
                sum_green += image_temp[i][j].rgbtGreen;
                sum_blue += image_temp[i][j].rgbtBlue;
                c += 1;
            }
            if (i + 1 <= last_row)
            {
                sum_red += image_temp[i + 1][j].rgbtRed;
                sum_green += image_temp[i + 1][j].rgbtGreen;
                sum_blue += image_temp[i + 1][j].rgbtBlue;
                c += 1;
            }
            //third column
            if ((i - 1 >= first_row) && (j + 1 <= last_col))
            {
                sum_red += image_temp[i - 1][j + 1].rgbtRed;
                sum_green += image_temp[i - 1][j + 1].rgbtGreen;
                sum_blue += image_temp[i - 1][j + 1].rgbtBlue;
                c += 1;
            }
            if (j + 1 <= last_col)
            {
                sum_red += image_temp[i][j + 1].rgbtRed;
                sum_green += image_temp[i][j + 1].rgbtGreen;
                sum_blue += image_temp[i][j + 1].rgbtBlue;
                c += 1;
            }
            if ((i + 1 <= last_row) && (j + 1 <= last_col))
            {
                sum_red += image_temp[i + 1][j + 1].rgbtRed;
                sum_green += image_temp[i + 1][j + 1].rgbtGreen;
                sum_blue += image_temp[i + 1][j + 1].rgbtBlue;
                c += 1;
            }
            image[i][j].rgbtRed = round(sum_red / (c * 1.0));
            image[i][j].rgbtGreen = round(sum_green / (c * 1.0));
            image[i][j].rgbtBlue = round(sum_blue / (c * 1.0));
        }
    }
    return;
}
