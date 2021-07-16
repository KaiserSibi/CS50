#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? \n"); //Ask user to input name
    printf("hello, %s\n", name); //Print out inputted name
}