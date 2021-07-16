#include <stdio.h>
#include <cs50.h>

long int eNum;
int count = 0;

long int digitcounter(long int ccNum);

int main()
{
    int ccArray[16];
    long int ccNum = 0;
    long int pccNum;

    int Sum1, Sum2, tSum;

    do
    {
        printf("\nEnter credit card number to validate: ");
        scanf("%li", &ccNum);
        eNum = digitcounter(ccNum);
        pccNum = ccNum;
    }
    while (!(eNum == 13 || eNum == 15 || eNum == 16));

    while (ccNum != 0)
    {
        ccArray[count] = ccNum % 10;
        ccNum /= 10;
        count++;
    }

    if (eNum == 13)
    {
        Sum1 = ((ccArray[1] + ccArray[3] + ccArray[5] + ccArray[7] + ccArray[9] + ccArray[11]) * 2);
        Sum2 = (ccArray[0] + ccArray[2] + ccArray[4] + ccArray[6] + ccArray[8] + ccArray[10]);
        tSum = (Sum1 % Sum2);
        if (tSum == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (eNum == 16)
    {
        printf("Digit Count: 16");
    }
    else
    {
        printf("Digit Count: 16");
    }
}

long int digitcounter(long int ccNum)
{
    eNum = 0;
    do
    {
        eNum++;
        ccNum /= 10;
    }
    while(ccNum > 0);
    return(eNum);
}
