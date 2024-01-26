#include <stdio.h>
#include <string.h>
#include "gsonHandler.h"

//reads a file using stdio; crashes if not .gson
FILE *readFile(char filename[])
{
    errorHandler(isGson(filename), 1, filename);

    FILE *pFile = fopen(filename, "r");

    errorHandler(validateFile(pFile), 1, filename);

    return pFile;

}

ERROR isGson(char filename[])
{
    char gson[] = ".gson";
    int extLength = strlen(gson);
    int filenameLength = strlen(filename);

    int extStartIndex = filenameLength - extLength;

    for (int i=0; i<extLength; i++)
        if (gson[i] != filename[extStartIndex + i])
            return EXT_NOT_GSON;
    return NONE;

}

ERROR validateFile(FILE *pFile)
{
    if (pFile == NULL)
        return NAME_DOES_NOT_EXIST;
    return NONE;
}

void writeToBuffer(FILE *pFile, char buffer[])
{
    char bufferComments[BUFFER_SIZE];
    fread(bufferComments, 1, BUFFER_SIZE, pFile);
    removeComments(bufferComments, buffer);
}

void printFile(FILE *pFile)
{
    char buffer[BUFFER_SIZE];
    writeToBuffer(pFile, buffer);

    for (int i=0; buffer[i] != ';'; i++)
        printf("%c", buffer[i]);
}

void removeComments(char with[], char without[])
{
    int length = bufferLength(with);
    int moveback = 0;

    for (int i=0; i<length; i++)
    {
        if (with[i] != '#')
            without[i - moveback] = with[i];
        
        else if (! (with[i] >= 1 && with[i] <= 126)) //checks for invalid characters
            moveback++;

        else
        {
            moveback += nextLineBreak(with, i);
            i += nextLineBreak(with, i);
        }
    }
}

int bufferLength(char buffer[])
{
    int i = 0;

    while (buffer[i] != EOF)
        i++;
    
    return i+2;
}

//returns distance between startIdx to next linebreak
int nextLineBreak(char str[], int startIdx)
{
    int i;

    for (i = startIdx; str[i] != '\n'; i++)
        if (str[i] == EOF)
            return BUFFER_SIZE;
    return i - startIdx;
}
