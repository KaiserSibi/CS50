#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Typedef ----
//8-bit unsigned integer
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc < 2 && argv[1] != NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else
    {
        char *infile = argv[1]; //for (int i = 0; 1 > i; i++){ printf("%s\n", infile); } -----TESTING PURPOSES
        FILE *inp_file = fopen(infile, "r");
        if (inp_file == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", infile);
            return 1;
        }
        else
        {
            char out_filename[8];
            int img_counter = -1;
            BYTE temp_storage[512];

            while ((fread(&temp_storage, sizeof(temp_storage), 1, inp_file)) != 0)
            {
                if ((temp_storage[0] == 0xff && temp_storage[1] == 0xd8 && temp_storage[2] == 0xff) && ((temp_storage[3] == 0xe0
                        || temp_storage[3] == 0xe1)))
                {
                    img_counter++;
                    sprintf(out_filename, "%03d.jpg", img_counter);

                    FILE *out_file = fopen(out_filename, "w");

                    if (out_file == NULL)
                    {
                        fclose(inp_file);
                        fprintf(stderr, "Could not create %s.\n", out_filename);
                        return 1;
                    }
                    else
                    {
                        do
                        {
                            fwrite(&temp_storage, sizeof(temp_storage), 1, out_file);
                            if ((fread(&temp_storage, sizeof(temp_storage), 1, inp_file)) == 0)
                            {
                                break;
                            }
                        }
                        while (!((temp_storage[0] == 0xff && temp_storage[1] == 0xd8 && temp_storage[2] == 0xff) && ((temp_storage[3] == 0xe0
                                 || temp_storage[3] == 0xe1))));
                        fclose(out_file);
                        fseek(inp_file, -sizeof(temp_storage), SEEK_CUR);
                    }
                }
            }
        }
        fclose(inp_file);
        // OLD CODE -- BACKUP
        //printf("Go Ahead"); //TESTING PURPOSES
        //BYTE temp_storage[512];
        //bool first_jpg = false;
        //while (fread(temp_storage, sizeof(BYTE), 512, inp_file) || feof(inp_file) == 0)
        //{
        //    if (temp_storage[0] == 0xff && temp_storage[1] == 0xd8 && temp_storage[2] == 0xff && (temp_storage[3] & 0xf0) == 0xe0)
        //    {
        //        if(!first_jpg)
        //        {
        //            first_jpg = true;
        //        }
        //        else
        //        {
        //            fclose(curr_image);
        //        }
        //    }
        //    else
        //    {
        //    }
        //}
    }
    return 0;
}