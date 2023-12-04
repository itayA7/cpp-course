#include <iostream>

using namespace std;

char **firstmission(char *text, int *size)
{
    char *textCopy = text;
    char **words;
    *size = 1;
    while (*textCopy) // check the number of words
    {
        if (*textCopy == ' ')
        {
            *size = *size + 1;
        }
        textCopy++;
    }
    textCopy = text;
    words = new char *[*size];
    char **copyOfWords = words;
    int wordPos = 0;
    while (*textCopy)
    {
        if (*textCopy == ' ')
        {
            textCopy++;
            wordPos++;
        }
        else
        {
            char *currentWordStart = textCopy;
            int wordLen = 0;
            while (*textCopy != ' ' && *textCopy != '\0')
            {
                wordLen++;
                textCopy++;
            }
            words[wordPos] = new char[wordLen + 1];
            textCopy = currentWordStart;
            for (int i = 0; i < wordLen; i++)
            {
                words[wordPos][i] = *textCopy;
                textCopy++;
            }
            words[wordPos][wordLen] = '\0';
        }
    }
    return words;
}

char **secondmission(char *text, int *size)
{
    char *textCopy = text;
    char **words;
    *size = 1;
    while (*textCopy) // check the number of words
    {
        if (*textCopy == ' ')
        {
            *size = *size + 1;
        }
        textCopy++;
    }
    textCopy = text;
    words = new char *[*size];
    int wordPos = 0;
    while (*textCopy)
    {
        if (*textCopy == ' ')
        {
            textCopy++;
            wordPos++;
        }
        else
        {
            char *currentWordStart = textCopy;
            int wordLen = 0;
            while (*textCopy != ' ' && *textCopy != '\0')
            {
                wordLen++;
                textCopy++;
            }
            words[wordPos] = new char[wordLen * 2 + 1];
            textCopy = currentWordStart;
            for (int i = 0; i < wordLen; i++)
            {
                words[wordPos][i] = *textCopy;
                textCopy++;
            }
            textCopy = currentWordStart;
            for (int i = wordLen; i < wordLen * 2; i++)
            {
                words[wordPos][i] = *textCopy;
                textCopy++;
            }
            words[wordPos][wordLen * 2] = '\0';
        }
    }

    return words;
}

int main()
{
    char sentence[] = "one two three four five six hola!";
    int len = 0;
    char **wordArrayMission1 = firstmission(sentence, &len);
    len = 0;
    char **wordArrayMission2 = secondmission(sentence, &len);
    cout << "the length of this sentence is: " << len << endl;

    // Print the array of words
    for (int i = 0; i < len; i++)
    {
        cout << "word number " << i + 1 << " is: " << wordArrayMission1[i] << endl;
        delete wordArrayMission1[i];
    }
    delete[] wordArrayMission1;

    cout << "mission 2 results:" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "word number " << i + 1 << " is: " << wordArrayMission2[i] << endl;
        delete wordArrayMission2[i];
    }
    delete[] wordArrayMission2;

    return 0;
}