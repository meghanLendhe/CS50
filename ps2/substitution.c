#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int checkCipherKey(string key)
{
    int duplicateFlag[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int len = strlen(key);

    int index = 0;

    if (len < 26)
    {
        return 1;
    }

    for (int i = 0; i < len; i++)
    {
        char x = key[i];

        if (isalpha(x))
        {
            index = toupper(x) - 'A';

            if (duplicateFlag[index] == 1)
            {
                return 3;
            }
            else
            {
                duplicateFlag[index] = 1;
            }
        }
        else
        {
            return 2;
        }
    }

    return 0;
}

void encrypt(string plainText, string cipherKey, char cipherText[])
{

    int len = strlen(plainText);

    int keyIndex = 0;

    for (int i = 0; i < len; i++)
    {
        char x = plainText[i];

        if (isalpha(x))
        {
            keyIndex = toupper(x) - 'A';

            if (islower(x))
            {
                cipherText[i] = tolower(cipherKey[keyIndex]);
            }
            else
            {
                cipherText[i] = toupper(cipherKey[keyIndex]);
            }
        }
        else
        {
            cipherText[i] = x;
        }
    }

    cipherText[len] = '\0';
}

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Enter a 26-character alphabetical cipher key!\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Enter a cipher key only!\n");
        return 1;
    }
    else
    {
        string cipherKey = argv[1];

        int keyValidity = checkCipherKey(cipherKey);

        if (keyValidity == 0)
        {
            string plainText = get_string("plaintext: ");
            int len = strlen(plainText);
            char cipherText[len + 1];
            encrypt(plainText, cipherKey, cipherText);
            printf("ciphertext: %s\n", cipherText);
            return 0;
        }
        else if (keyValidity == 1)
        {
            printf("Your key is short. It should have 26 unique letters!\n");
            return 1;
        }
        else if (keyValidity == 2)
        {
            printf("Your key has non alphabetical characters!\n");
            return 1;
        }
        else if (keyValidity == 3)
        {
            printf("Your key has repeating letters. All 26 letters in the key must be unique.\n");
            return 1;
        }
    }
}
