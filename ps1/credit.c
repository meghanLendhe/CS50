#include <cs50.h>
#include <stdio.h>

void processNumber(long long cardNumber)
{
    int digitHistory[] = {0, 0};
    int count = 0;
    int multiplyFlag = 0;
    int checkSum = 0;

    while (cardNumber != 0)
    {
        int digit = cardNumber % 10;
        ++count;

        if (multiplyFlag)
        {
            if (digit != 0)
            {
                int twiceOfDigit = digit * 2;
                if (twiceOfDigit < 10)
                {
                    checkSum += twiceOfDigit;
                }
                else
                {
                    while (twiceOfDigit != 0)
                    {
                        checkSum += (twiceOfDigit % 10);
                        twiceOfDigit /= 10;
                    }
                }
            }
            multiplyFlag = 0;
        }
        else
        {
            checkSum += digit;
            multiplyFlag = 1;
        }
        digitHistory[1] = digitHistory[0];
        digitHistory[0] = digit;
        cardNumber /= 10;
    }

    if ((checkSum % 10) != 0)
    {
        printf("\n\nINVALID\n");
    }
    else
    {
        switch (count)
        {

            case 15:
                printf("\n\nAMERICAN EXPRESS\n");
                break;

            case 13:
                printf("\n\nVISA\n");
                break;

            case 16:
                if (digitHistory[0] == 4)
                {
                    printf("\n\nVISA\n");
                }
                else
                {
                    printf("\n\nMASTERCARD\n");
                }

                break;
        }
    }
}

int main(void)
{
    long long input = get_long_long("Enter a credit card number.\n");
    processNumber(input);
}
