#include "errorHandler.h"

#ifndef NULL
#include <stddef.h>
#endif

void errorHandler(ERROR error, int toAbort, char *argFilename)
{

    if (error == NONE)
        return;


    char *filename = argFilename;

    if (argFilename == NULL)
        filename = "NULL";
    
    

    switch (error)
    {
        case NAME_DOES_NOT_EXIST:
            printf("there is no file named \"%s\"\n", filename);
            break;
        
        case NAME_TOO_LONG:
            printf("file name is too long, exceeding the maximum of %i characters.\n",
            MAX_FILE_LENGTH);
            break;
        
        case EXT_NOT_GSON:
            printf("file '%s' isn't a .gson file.\n", filename);
            break;

        default:
            printf("Something went wrong.\n");
            break;
    }

    if (toAbort)
    {
        printf("Crashing.\n");
        abort();
    }
}