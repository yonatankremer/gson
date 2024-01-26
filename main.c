#include <stdio.h>
#include <stdlib.h>

#ifndef MAX_FILE_LENGTH
#include "maxFileLength.h"
#endif

#ifndef BUFFER_SIZE
#include "buffer.h"
#endif

#ifndef TOKEN_H
#include "tokenization/tokenizer.h"
#endif

#include "arg.h"
#include "gsonHandler.h"

int main(int argc, char **argv)
{
    char filename[MAX_FILE_LENGTH];

    getArg(argv[1]);
    strcpy(filename, argv[1]);

    FILE *pFile = readFile(filename);
    char buffer[BUFFER_SIZE];
    writeToBuffer(pFile, buffer);
    
    token tokens[BUFFER_SIZE];
    strToTokens(tokens, buffer);

    printTokens(tokens);


}