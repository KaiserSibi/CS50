#include <stdio.h>
#include <cs50.h>
#include <math.h>

int charactercounter(char textsample[]); //Functions
int wordcounter(char textsample[]);
int sentencecounter(char textsample[]);
void indexer(int rIndex);

int charcount = 0; //Declration and initialization of global variables
int counter = 0;
int characters = 0;
int words = 0;
int sentences = 0;

int main()
{
    char textsample[1000]; //initialization and declraation of local variables; 1000 size of char array
    float index = 0.00;
    float avgwords;
    float avgsentences;
    int rIndex;

    printf("Enter text sample: \n");
    fgets(textsample, sizeof(textsample), stdin); //accept char array
    printf("_________________________________\n");

    charactercounter(textsample); //call functions
    wordcounter(textsample);
    sentencecounter(textsample);

    printf("%d Letter(s)\n", characters);
    printf("%d Word(s)\n", words);
    printf("%d Sentence(s)\n", sentences);

    avgwords = (float)characters / (float)words * 100; //calculate average characters per 100 words
    avgsentences = (float)sentences / (float)words * 100; //calculate average sentences per 100 words
    index = 0.0588 * avgwords - 0.296 * avgsentences - 15.8; //calculate Coleman-Liau index
    rIndex = round(index); //round value of index and assign result to rIndex
    indexer(rIndex); //call function

    //printf("Index Score: %f || ", index);
    //printf("Rounded Index Score: %d\n", rIndex);
    //printf("L = %f; S = %f\n", avgwords, avgsentences);
    //printf("%c %c %c %c %c %c %c %c %c %c", textsample[0], textsample[1], textsample[2], textsample[3], textsample[4], textsample[5], textsample[6], textsample[7], textsample[8], textsample[9]);
    return 0;
}

int charactercounter(char textsample[]) //character counter function
{
    for (counter = 0; textsample[counter] != '\0'; counter++)
    {
        if ((textsample[counter] >= 65 && textsample[counter] <= 90) || (textsample[counter] >= 97 && textsample[counter] <= 122))
        {
            characters = characters + 1;
        }
    }
    return (characters);
}

int wordcounter(char textsample[]) //counts words when by counting spaces
{
    for (counter = 0; textsample[counter] != '\0'; counter++)
    {
        if (textsample[counter] == 32)
        {
            words = words + 1;
        }
    }
    return (words = words + 1);
}

//counts sentences by counting dots, exclamation points, and question marks if I didn't get their ASCII values wrong.
int sentencecounter(char textsample[]) 
{
    for (counter = 0; textsample[counter] != '\0'; counter++)
    {
        if ((textsample[counter] == 33) || (textsample[counter] == 46) || (textsample[counter] == 63))
        {
            sentences = sentences + 1;
        }
    }
    return (sentences);
}

void indexer(int rIndex) //prints out appropriate grade level according to the value of rIndex.
{
    if (rIndex > 10)
    { 
        printf("Grade 16+\n"); 
    }
    else if (rIndex > 9)
    { 
        printf("Grade 10\n"); 
    }
    else if (rIndex > 8)
    { 
        printf("Grade 9\n"); 
    }
    else if (rIndex > 7)
    { 
        printf("Grade 8\n"); 
    }
    else if (rIndex > 6)
    { 
        printf("Grade 7\n"); 
    }
    else if (rIndex > 5)
    { 
        printf("Grade 6\n"); 
    }
    else if (rIndex > 4)
    { 
        printf("Grade 5\n"); 
    }
    else if (rIndex > 3)
    {
        printf("Grade 4\n"); 
    }
    else if (rIndex > 2)
    { 
        printf("Grade 3\n"); 
    }
    else if (rIndex > 1)
    { 
        printf("Grade 2\n"); 
    }
    else if (rIndex > 0)
    { 
        printf("Grade 1\n");
    }
    else if (rIndex < 0)
    { 
        printf("Before Grade 1\n"); 
    }
    else
    { 
        printf("Unable to process!\n"); 
        
    }
}