#include <stdio.h>
#include <cs50.h>

int input();
int x = 0; //initialize global variable

int main(void)
{
    int a, b, c; //a = row, b = column, c = spacing
    x = input();

    while (!((x <= 8) && (x >= 1)))
    {
        printf("---INVALID ENTRY---\n");
        x = input();
    }
    for (a = 1; a <= x; a++)
    {
        for (c = 1; c <= x - a; c++) //Set up spacing; Will only work if variable c is less than or equal to the inputted number minus the current value for variable a.
        {
            printf(" ");
        }
        for (b = 1; b <= a; b++) //Prints the asterisks
        {
            printf("#");
        }
        printf("\n");
    }
}

int input()
{
    printf("Enter number of rows: ");
    scanf("%d", &x);
    return (x);
}