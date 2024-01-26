#include "arg.h"
#define assetsDir "assets/"

void getArg(char filename[])
{
    errorHandler(safeArg(filename), 1, filename);
    strcat(assetsDir, filename);
}

ERROR safeArg(char filename[])
{
    if (strlen(filename) > MAX_FILE_LENGTH)
        return NAME_TOO_LONG;
    return NONE;
}