#include <stdio.h>
#include <stdlib.h> //strtod
#include <ctype.h> //tolower

//Function declarations
int f_int_count_char(char *char_conv_from_argv);
int f_get_key(char *char_conv_from_argv);
int f_userinput();
int f_alpha_base();
int f_encrypt();
int f_checkduplicates_inkey(char *char_conv_from_argv);

//Global variables
char userinput[100];
char conv_key[26]; //KEY FROM ARGV

int main(int argc, char *argv[]) //Hidden some test stuff as a comment to check if I got it logically
{
    if (argv[1] != NULL && argv[2] == NULL)
    {
        char *char_conv_from_argv;
        double double_conv_from_argv = strtod(argv[1], &char_conv_from_argv);
        if (double_conv_from_argv != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            int int_count_char = f_int_count_char(char_conv_from_argv);
            if (int_count_char == 26)
            {
                f_get_key(char_conv_from_argv);
                f_checkduplicates_inkey(char_conv_from_argv);
                if (conv_key[0] == '\0')
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }
                else
                {
                    f_userinput();
                    f_encrypt();
                    printf("ciphertext: %s\n", userinput);
                    return 0;
                }
            }
            else
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            return 0;
        }
    }
    else
    {
        printf("./substitution key \n");
        return 1;
    }
}

int f_int_count_char(char *char_conv_from_argv) //Counts how many characters there are in the separated char array
{
    int i;
    int count = 0;
    //printf("%s\n", char_conv_from_argv);
    for (i = 0; char_conv_from_argv[i] != '\0'; i++)
    {
        count++;
    }
    //printf("%d\n", count);
    return (count);
}

int f_userinput() //get plaintext!!!
{
    printf("Plaintext: ");
    fgets(userinput, sizeof(userinput), stdin); //accept char array
    return 0;
}

int f_get_key(char *char_conv_from_argv) //get key from argv
{
    int i;
    for (i = 0; char_conv_from_argv[i] != '\0'; i++)
    {
        if ((char_conv_from_argv[i] >= 65 && char_conv_from_argv[i] <= 90 ) || 
        (char_conv_from_argv[i] >= 97 && char_conv_from_argv[i] <= 122))
        {
            conv_key[i] = char_conv_from_argv[i]; //copy contentof char_conv_from_argv to conv_key
        }
        else
        {
            conv_key[0] = '\0';
            return 0;
        }
    }
    //printf("%s\n", conv_key);
    return 0;
}

int f_checkduplicates_inkey(char *char_conv_from_argv)
{
    //Check for duplicates in char_conv_from_argv
    int i, j;
    for (i = 0; i < 26; i++)
    {
        for (j = i + 1; j < 26; j++)
        {
            if (char_conv_from_argv[i] == char_conv_from_argv[j])
            {
                conv_key[0] = '\0';
            }
        }
    }
    return 0;
}

int f_encrypt()
{
    int i;
    //{0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}
    //{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};
    for (i = 0; userinput[i] != '\0'; i++)
    {
        if (userinput[i] == 'A')
        {
            userinput[i] = toupper(conv_key[0]);
        }
        else if (userinput[i] == 'B')
        {
            userinput[i] = toupper(conv_key[1]);
        }
        else if (userinput[i] == 'C')
        {
            userinput[i] = toupper(conv_key[2]);
        }
        else if (userinput[i] == 'D')
        {
            userinput[i] = toupper(conv_key[3]);
        }
        else if (userinput[i] == 'E')
        {
            userinput[i] = toupper(conv_key[4]);
        }
        else if (userinput[i] == 'F')
        {
            userinput[i] = toupper(conv_key[5]);
        }
        else if (userinput[i] == 'G')
        {
            userinput[i] = toupper(conv_key[6]);
        }
        else if (userinput[i] == 'H')
        {
            userinput[i] = toupper(conv_key[7]);
        }
        else if (userinput[i] == 'I')
        {
            userinput[i] = toupper(conv_key[8]);
        }
        else if (userinput[i] == 'J')
        {
            userinput[i] = toupper(conv_key[9]);
        }
        else if (userinput[i] == 'K')
        {
            userinput[i] = toupper(conv_key[10]);
        }
        else if (userinput[i] == 'L')
        {
            userinput[i] = toupper(conv_key[11]);
        }
        else if (userinput[i] == 'M')
        {
            userinput[i] = toupper(conv_key[12]);
        }
        else if (userinput[i] == 'N')
        {
            userinput[i] = toupper(conv_key[13]);
        }
        else if (userinput[i] == 'O')
        {
            userinput[i] = toupper(conv_key[14]);
        }
        else if (userinput[i] == 'P')
        {
            userinput[i] = toupper(conv_key[15]);
        }
        else if (userinput[i] == 'Q')
        {
            userinput[i] = toupper(conv_key[16]);
        }
        else if (userinput[i] == 'R')
        {
            userinput[i] = toupper(conv_key[17]);
        }
        else if (userinput[i] == 'S')
        {
            userinput[i] = toupper(conv_key[18]);
        }
        else if (userinput[i] == 'T')
        {
            userinput[i] = toupper(conv_key[19]);
        }
        else if (userinput[i] == 'U')
        {
            userinput[i] = toupper(conv_key[20]);
        }
        else if (userinput[i] == 'V')
        {
            userinput[i] = toupper(conv_key[21]);
        }
        else if (userinput[i] == 'W')
        {
            userinput[i] = toupper(conv_key[22]);
        }
        else if (userinput[i] == 'X')
        {
            userinput[i] = toupper(conv_key[23]);
        }
        else if (userinput[i] == 'Y')
        {
            userinput[i] = toupper(conv_key[24]);
        }
        else if (userinput[i] == 'Z')
        {
            userinput[i] = toupper(conv_key[25]);
        } //Line below is just to make sure to not change the following symbols to anything else.
        else if (userinput[i] == ' ' || userinput[i] == '!' || userinput[i] == '.' || userinput[i] == ',' || userinput[i] == '?') { }
        if (userinput[i] == 'a')
        {
            userinput[i] = tolower(conv_key[0]);
        }
        else if (userinput[i] == 'b')
        {
            userinput[i] = tolower(conv_key[1]);
        }
        else if (userinput[i] == 'c')
        {
            userinput[i] = tolower(conv_key[2]);
        }
        else if (userinput[i] == 'd')
        {
            userinput[i] = tolower(conv_key[3]);
        }
        else if (userinput[i] == 'e')
        {
            userinput[i] = tolower(conv_key[4]);
        }
        else if (userinput[i] == 'f')
        {
            userinput[i] = tolower(conv_key[5]);
        }
        else if (userinput[i] == 'g')
        {
            userinput[i] = tolower(conv_key[6]);
        }
        else if (userinput[i] == 'h')
        {
            userinput[i] = tolower(conv_key[7]);
        }
        else if (userinput[i] == 'i')
        {
            userinput[i] = tolower(conv_key[8]);
        }
        else if (userinput[i] == 'j')
        {
            userinput[i] = tolower(conv_key[9]);
        }
        else if (userinput[i] == 'k')
        {
            userinput[i] = tolower(conv_key[10]);
        }
        else if (userinput[i] == 'l')
        {
            userinput[i] = tolower(conv_key[11]);
        }
        else if (userinput[i] == 'm')
        {
            userinput[i] = tolower(conv_key[12]);
        }
        else if (userinput[i] == 'n')
        {
            userinput[i] = tolower(conv_key[13]);
        }
        else if (userinput[i] == 'o')
        {
            userinput[i] = tolower(conv_key[14]);
        }
        else if (userinput[i] == 'p')
        {
            userinput[i] = tolower(conv_key[15]);
        }
        else if (userinput[i] == 'q')
        {
            userinput[i] = tolower(conv_key[16]);
        }
        else if (userinput[i] == 'r')
        {
            userinput[i] = tolower(conv_key[17]);
        }
        else if (userinput[i] == 's')
        {
            userinput[i] = tolower(conv_key[18]);
        }
        else if (userinput[i] == 't')
        {
            userinput[i] = tolower(conv_key[19]);
        }
        else if (userinput[i] == 'u')
        {
            userinput[i] = tolower(conv_key[20]);
        }
        else if (userinput[i] == 'v')
        {
            userinput[i] = tolower(conv_key[21]);
        }
        else if (userinput[i] == 'w')
        {
            userinput[i] = tolower(conv_key[22]);
        }
        else if (userinput[i] == 'x')
        {
            userinput[i] = tolower(conv_key[23]);
        }
        else if (userinput[i] == 'y')
        {
            userinput[i] = tolower(conv_key[24]);
        }
        else if (userinput[i] == 'z')
        {
            userinput[i] = tolower(conv_key[25]);
        }
    }
    return 0;
}