#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024


FILE *readFile(char filename[]);
int isGson(char filename[]);
void writeToBuffer(FILE *pFile, char buffer[]);
void printFile(FILE *pFile);
void removeComments(char with[], char without[]);
int bufferLength(char buffer[]);
int nextLineBreak(char str[], int startIdx);