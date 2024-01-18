#include "token.h"

token charToToken(char c, int isInString);
char tokenToChar(token t);

void tokensToStr(token tokens[], char str[]);
void strToTokens(token tokens[], char str[]);
void printTokens(token tokens[]);