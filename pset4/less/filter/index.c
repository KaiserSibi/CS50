#include <math.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(){
	char *infile = "infile1.bmp";
	char *outfile = "outfile.bmp";
	char *outbin = "outbin.bin";

	FILE *inptr = fopen(infile, "r");
    if (inptr == NULL){
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }
    else{
    	FILE *outptr = fopen(outfile, "w");
	    if (outptr == NULL)
	    {
	        fclose(inptr);
	        fprintf(stderr, "Could not create %s.\n", outfile);
	        return 2;
	    }
	    else{
	    	FILE *outbinptr = fopen(outbin, "w");
		    if (outbin == NULL)
		    {
		        fclose(inptr);
		        fprintf(stderr, "Could not create %s.\n", outbin);
		        return 3;
		    }
		    else{
		    	// Read infile's BITMAPFILEHEADER
			    BITMAPFILEHEADER bf;
			    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

			    // Read infile's BITMAPINFOHEADER
			    BITMAPINFOHEADER bi;
			    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

			    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
			    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
			        bi.biBitCount != 24 || bi.biCompression != 0){
			        fclose(outbinptr);
			        fclose(outptr);
			        fclose(inptr);
			        fprintf(stderr, "Unsupported file format.\n");
			        return 6;
			    }
			    else{
			    	int height = abs(bi.biHeight);
				    int width = bi.biWidth;

				    // Allocate memory for image
				    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
				    if (image == NULL){
				        fprintf(stderr, "Not enough memory to store image.\n");
				        fclose(outbinptr);
				        fclose(outptr);
				        fclose(inptr);
				        return 7;
				    }
				    else{
				    	// Determine padding for scanlines
					    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

					    // Iterate over infile's scanlines
					    for (int i = 0; i < height; i++)
					    {
					        // Read row into pixel array
					        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

					        // Skip over padding
					        fseek(inptr, padding, SEEK_CUR);
					    }

					    int color_average_rounded, i, j; //Initialization of local variables
					    float color_average_temp;
					    for (i = 0; height > i; i++){
					        for (j = 0; width > j; j++){
					            color_average_temp = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0; //Calculate average; returns as float value
					            color_average_rounded = round(color_average_temp);
					            image[i][j].rgbtRed = color_average_rounded;
					            image[i][j].rgbtGreen = color_average_rounded;
					            image[i][j].rgbtBlue = color_average_rounded;
					        }
					    }

					    int half_width, temp_Red, temp_Green, temp_Blue;
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
					    // Write outfile's BITMAPFILEHEADER
					    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

					    // Write outfile's BITMAPINFOHEADER
					    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

					    // Write new pixels to outfile
					    for (i = 0; i < height; i++)
					    {
					        // Write row to outfile
					        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

					        // Write padding at end of row
					        for (int k = 0; k < padding; k++)
					        {
					            fputc(0x00, outptr);
					        }
					    }

					    // Free memory for image
					    free(image);

					    // Close files
					    fclose(inptr);
					    fclose(outptr);
					    fclose(outbinptr);
					}
				}
			}
		}
	}
}
