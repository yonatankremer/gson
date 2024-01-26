#include <stdio.h>

#ifndef ERROR_H
#include "errorHandling/errorHandler.h"
#endif

#ifndef BUFFER_SIZE
#include "buffer.h"
#endif

FILE *readFile(char filename[]);

ERROR isGson(char filename[]);
ERROR validateFile(FILE *pFile);

void writeToBuffer(FILE *pFile, char buffer[]);
void printFile(FILE *pFile);
void removeComments(char with[], char without[]);
int bufferLength(char buffer[]);
int nextLineBreak(char str[], int startIdx);
