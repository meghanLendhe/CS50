#include <stdio.h>

void printChar(int z, char c)
{
    for (int j = 0; j < z; j++)
    {
        printf("%c", c);
    }
}

void constructPyramid(int n)
{

    for (int i = 0; i < n; i++)
    {
        printChar((n - i + 1), ' ');

        printChar((i + 1), '#');

        printf("  ");

        printChar((i + 1), '#');

        printChar((n - i + 1), ' ');

        printf("\n");
    }
}

int main(void)
{
    char buffer[100];
    int n = 0;
    printf("How many steps should the pyramid have? It can have 8 at most.\n");

    while (1)
    {
        if (fgets(buffer, sizeof(buffer), stdin))
        {
            if (buffer[0] == '\n')
            {
                printf("You just pressed Enter without typing a number.\n");
                continue;
            }
            else
            {
                if (sscanf(buffer, "%d", &n) == 1)
                {

                    if (n > 0 && n < 9)
                    {
                        printf("\nBuilding a pyramid with %i steps\n\n", n);
                        constructPyramid(n);
                        printf("\n");
                        break;
                    }
                    else
                    {
                        printf("Invalid input! Please enter a number between 1 and 8.\n");
                        continue;
                    }
                }
                else
                {
                    printf("Invalid input! Please enter a number.\n");
                    // Clear the buffer
                    while ((getchar()) != '\n')
                        ;
                }
            }
        }
    }
}
