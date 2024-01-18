#include "gsonHandler.h"



//reads a file using stdio; crashes if not .gson
FILE *readFile(char filename[])
{
    if (!isGson(filename))
    {
        printf("file '%s' isn't a .gson file.\nCrashing.\n", filename);
        abort();
    }

    FILE *pFile = fopen(filename, "r");

    if (pFile == NULL)
    {
        printf("there is no file named %s", filename);
        abort();
    }

    return pFile;

}

int isGson(char filename[])
{
    char gson[] = ".gson";
    int extLength = strlen(gson) + 1; //to make up for '\0' character
    int filenameLength = strlen(filename) + 1;

    int extStartIndex = filenameLength - extLength;

    for (int i=0; i<extLength; i++)
        if (gson[i] != filename[extStartIndex + i])
            return 0;
    return 1;

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

    while (buffer[i] != ';')
        i++;
    
    return i+2;
}

//returns distance between startIdx to next linebreak
int nextLineBreak(char str[], int startIdx)
{
    int i;

    for (i = startIdx; str[i] != '\n'; i++)
        if (str[i] == ';')
            return BUFFER_SIZE;
    return i - startIdx;
}
