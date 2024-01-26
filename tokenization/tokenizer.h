#ifndef TOKEN_H
#include "token.h"
#endif

#ifndef BUFFER_SIZE
#include "../buffer.h"
#endif

token charToToken(char c, int isInString);
char tokenToChar(token t);

void tokensToStr(token tokens[], char str[]);
void strToTokens(token tokens[], char str[]);
void printTokens(token tokens[]);