#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count = 0; //Declare and initialize global variable
int change(int inputrounded); //Declare function change with "int inputrounded" as its parameter

int main()
{
    float input; //Declaration of local variable "input"
    do //Continuously prompt user for change owed if input is not more than or equal to 0
    {
        input = get_float("Enter change owed: ");
    }
    while (!(input >= 0));

    int inputrounded = round(input * 100); //Call out "round" function from math header to create a new variable with its value as the result of the "rounding" out function.
    count = change(inputrounded); //Call out written function called "change"

    printf("Number of coins to be given out: %d \n", count);
}

int change(int inputrounded) // Function called change with inputrounded. This function will apply the greedy approach mentioned in the CS50 notes.
{                            
    while (inputrounded >= 25)
    {
        inputrounded -= 25;
        count++;
    }
    while (inputrounded >= 10)
    {
        inputrounded -= 10;
        count++;
    }
    while (inputrounded >= 5)
    {
        inputrounded -= 5;
        count++;
    }
    while (inputrounded >= 1)
    {
        inputrounded -= 1;
        count++;
    }
    return (count); //Returns the variable count.
}