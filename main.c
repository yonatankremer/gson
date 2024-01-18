#include <stdio.h>
#include <string.h>

#include "gsonHandler.c"
#include "gsonObj.c"
#include "tokenization/tokenizer.c"

int main(int argc, char **argv)
{
    char filename[100];
    strcpy(filename, "assets/");
    strcat(filename, argv[1]);


    FILE *pFile = readFile(filename);
    char buffer[BUFFER_SIZE];
    writeToBuffer(pFile, buffer);
    
    token tokens[BUFFER_SIZE];
    strToTokens(tokens, buffer);

    printTokens(tokens);


}