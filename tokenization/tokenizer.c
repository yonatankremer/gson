#include "tokenizer.h"
#include <stdio.h>

token charToToken(char c, int isIntString)
{
    switch (c)
    {
        case '#': return COMMENT;
        case '\n': return LINEBREAK;
        case ' ': return SPACE;

        case '\"': return STR_QUOT;

        case ':': return COLON;

        case '{': return OBJ_START;
        case '}': return OBJ_END;


        default:
            if (isIntString)
                return STR_CONTENT;
            return IDENTIFIER;
        
    }
}

char tokenToChar(token t)
{
    switch (t)
    {
        case COMMENT: return '#';
        case LINEBREAK: return 'L';
        case SPACE: return 'S';

        case STR_QUOT: return 'Q';

        case COLON: return ':';

        case OBJ_START: return '{';
        case OBJ_END: return '}';


        case IDENTIFIER: return 'i';
        case STR_CONTENT: return 'c';

        default: return 'N';
    }
}

void tokensToStr(token tokens[], char str[])
{
    int i;
    for (i=0; tokens[i] != EOF; i++)
        str[i] = tokenToChar(tokens[i]);
    str[++i] = tokenToChar(EOF);
}

void strToTokens(token tokens[], char str[])
{
    int isInString = 0;
    int i = 0;

    for (i=0; str[i] != EOF; i++)
    {
        if (str[i] == '\"')
            isInString = (isInString == 0) ? 1 : 0;

        tokens[i] = charToToken(str[i], isInString);
    }

    tokens[++i] = EOF;
}

void printTokens(token tokens[])
{
    char str[BUFFER_SIZE];
    tokensToStr(tokens, str);

    for(int i=0; tokens[i] != EOF; i++)
        if (str[i] == 'S')
            printf(" ");
        else if (str[i] == 'N')
            printf("\n");
        else if (str[i] == 'Q')
            printf("\"");
        else
            printf("%c", str[i]);
    
    printf("END_OF_FILE");
        
}