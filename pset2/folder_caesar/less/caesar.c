#include <stdio.h>
#include <stdlib.h> //strtod

//Function declarations
int f_int_count_char(char *char_conv_from_argv);
int f_userinput();
int f_encrypt(double double_conv_from_argv);

//Global variables
char userinput[100];

int main(int argc, char *argv[]) //Hidden some test stuff as a comment to check if I got it logically
{
    if (argv[1] != NULL && argv[2] == NULL)
    {
        char *char_conv_from_argv;
        double double_conv_from_argv = strtod(argv[1], &char_conv_from_argv);
        //printf("\n%d - %s\n", (int)double_conv_from_argv, char_conv_from_argv);
        //printf("%s _TESTING \n", char_conv_from_argv);
        int int_count_char = f_int_count_char(char_conv_from_argv);
        //printf("%d\n", int_count_char);
        if (int_count_char == 0)
        {
            f_userinput();
            f_encrypt(double_conv_from_argv);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
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

int f_userinput()
{
    printf("Plaintext: ");
    fgets(userinput, sizeof(userinput), stdin); //accept char array
    return 0;
}

int f_encrypt(double double_conv_from_argv)
{
    int i;
    int temp_userinput = 0;
    int adjusted_double_conv_from_argv = (int)double_conv_from_argv;

    for (i = 0; userinput[i] != '\0'; i++)
    {
        if (userinput[i] >= 65 && userinput[i] <= 90)
        {
            temp_userinput = userinput[i] + adjusted_double_conv_from_argv; //temporarily hold value
            if (temp_userinput > 90)
            {
                temp_userinput -= 90;
                if (temp_userinput > 26)
                {
                    while (temp_userinput >= 26)
                    {
                        temp_userinput -= 26;
                    }
                    if ((userinput[i] + temp_userinput) > 90)
                    {
                        userinput[i] = 65 + temp_userinput - 1;
                    }
                    else
                    {
                        userinput[i] = 97 + temp_userinput - 1;
                    }
                }
                else
                {
                    userinput[i] = 65 + temp_userinput - 1;
                }
            }
            else
            {
                userinput[i] += adjusted_double_conv_from_argv;
            }
        }
        if (userinput[i] >= 97 && userinput[i] <= 122)
        {
            temp_userinput = userinput[i] + adjusted_double_conv_from_argv; //temporarily hold value
            if (temp_userinput > 122)
            {
                temp_userinput -= 122;
                if (temp_userinput > 26)
                {
                    while (temp_userinput >= 26)
                    {
                        temp_userinput -= 26;
                    }
                    if (temp_userinput < 26)
                    {
                        userinput[i] = 97 + temp_userinput - 1;
                    }
                    else
                    {
                        userinput[i] = 97 + temp_userinput - 1;
                    }
                }
                else
                {
                    userinput[i] = 97 + temp_userinput - 1;
                }
            }
            else
            {
                userinput[i] += adjusted_double_conv_from_argv;
            }
        }
    }
    printf("ciphertext: %s\n", userinput);
    return 0;
}