#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string text)
{
    int letterCount = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }

    return letterCount;
}

int countWords(string text)
{
    int wordCount = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {

        if (text[i] == ' ' && text[i - 1] != ' ')
        {
            wordCount++;
            continue;
        }

        if (i == len - 1)
        {
            wordCount++;
        }
    }

    return wordCount;
}

int countSentences(string text)
{
    int multipleSpacesFlag = 0;

    int sentenceCount = 0;

    int firstCharIndex = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {

        if (i > 0 && text[i] == ' ' && text[i - 1] == ' ')
        {
            multipleSpacesFlag = 1;
            continue;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            if (multipleSpacesFlag == 0 && text[firstCharIndex] != ' ' && text[i - 1] != ' ')
            {
                sentenceCount++;
                i++;
                firstCharIndex = i + 1;
            }

            multipleSpacesFlag = 0;
        }
    }

    return sentenceCount;
}

int main()
{

    string text = get_string("Text: ");

    int letterCount = countLetters(text);

    int wordCount = countWords(text);

    int sentenceCount = countSentences(text);

    float avgLetters = 100 * ((float) letterCount / wordCount);

    float avgSentences = 100 * ((float) sentenceCount / wordCount);

    int index = (int) round(0.0588 * avgLetters - 0.296 * avgSentences - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
