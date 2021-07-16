#include <stdio.h>
#include <cs50.h>

long int eNum;
int count;

long int digitcounter(long int ccNum);
int modResultF(int tSum);

int main()
{
    int ccArray[16];
    int modresultArray[2];

    long int ccNum = 0;
    long int pccNum;
    int Sum1, Sum2, tSum;

    ccNum = get_long ("\nEnter credit card number to validate: ");
    eNum = digitcounter(ccNum);
    pccNum = ccNum;

    while (ccNum != 0)
    {
        ccArray[count] = ccNum % 10;
        ccNum /= 10;
        count++;
    }
    count = 0;

    if (eNum == 13)
    {
        Sum1 = ((ccArray[1] + ccArray[3] + ccArray[5] + ccArray[7] + ccArray[9] + ccArray[11]) * 2);
        Sum2 = (ccArray[0] + ccArray[2] + ccArray[4] + ccArray[6] + ccArray[8] + ccArray[10] + ccArray[12]);
        tSum = (Sum1 % Sum2);

        if (ccArray[12] == 4)
        {
            do
            {
                tSum %= tSum;
            }
            while (tSum != 0);

            if (tSum == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (eNum == 15)
    {
        Sum1 = ((ccArray[1] + ccArray[3] + ccArray[5] + ccArray[7] + ccArray[9] + ccArray[11] + ccArray[13]) * 2);
        Sum2 = (ccArray[0] + ccArray[2] + ccArray[4] + ccArray[6] + ccArray[8] + ccArray[10] + ccArray[12] + ccArray[14]);
        tSum = (Sum1 % Sum2);

        if ((ccArray[14] == 3) && (ccArray[13] == 4 || ccArray[13] == 7))
        {
            do
            {
                tSum %= tSum;
            }
            while (tSum != 0);

            if (tSum == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (eNum ==16)
    {
        Sum1 = ((ccArray[1] + ccArray[3] + ccArray[5] + ccArray[7] + ccArray[9] + ccArray[11] + ccArray[13] + ccArray[15]) * 2);
        Sum2 = (ccArray[0] + ccArray[2] + ccArray[4] + ccArray[6] + ccArray[8] + ccArray[10] + ccArray[12] + ccArray[14]);
        tSum = (Sum1 % Sum2);

        if (tSum == 0)
        {
            if (ccArray[15] == 4)
            {
                printf("VISA\n");
            }
            else if ((ccArray[15] == 5) && (ccArray[14] == 1 || ccArray[14] == 2 || ccArray[14] == 3 || ccArray[14] == 4 || ccArray[14] == 5))
            {
                printf("MASTERCARD\n");
            }
            else { printf("INVALID\n"); }
        }
        else if (tSum != 0)
        {
            do
            {
                tSum %= tSum;
            }
            while (tSum != 0);

            if (ccArray[15] == 4)
            {
                printf("VISA\n");
            }
            else if ((ccArray[15] == 5) && (ccArray[14] == 1 || ccArray[14] == 2 || ccArray[14] == 3 || ccArray[14] == 4 || ccArray[14] == 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
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