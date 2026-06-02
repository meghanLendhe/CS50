#include <ctype.h>
#include <stdio.h>

int mapping[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculateScore(char word[20])
{
    int score = 0;
    int i = 0, index = 0;
    char x;

    while (1)
    {
        x = word[i];
        if (x != '\n')
        {
            index = toupper(x) - 'A';

            if (index >= 0 && index < 26)
            {
                score += mapping[index];
            }
            else
            {
                printf("Not a valid letter.\n");
            }

            i++;
        }
        else
            break;
    }

    return score;
}

int main(void)
{
    char wordA[20], wordB[20];
    int scoreA, scoreB;

    printf("\nPlayer 1: ");
    while (1)
    {

        if (fgets(wordA, sizeof(wordA), stdin))
        {
            if (wordA[0] == '\n')
            {
                printf("You just pressed Enter without typing anything.\n");
                continue;
            }
            break;
        }
    }

    printf("\nPlayer 2: ");
    while (1)
    {

        if (fgets(wordB, sizeof(wordB), stdin))
        {
            if (wordB[0] == '\n')
            {
                printf("You just pressed Enter without typing anything.\n");
                continue;
            }
            break;
        }
    }

    scoreA = calculateScore(wordA);

    printf("\nPlayer 1: %i\n", scoreA);

    scoreB = calculateScore(wordB);

    printf("\nPlayer 2: %i\n", scoreB);

    if (scoreA > scoreB)
    {
        printf("\n\nPlayer 1 wins!\n");
    }
    else if (scoreA == scoreB)
    {
        printf("\n\nTie!\n");
    }
    else
        printf("\n\nPlayer 2 wins!\n");
}
