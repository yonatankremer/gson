#ifndef ERROR_H
#include "error.h"
#endif

#ifndef MAX_FILE_LENGTH
#include "../maxFileLength.h"
#endif

#include <stdlib.h>
#include <stdio.h>

void errorHandler(ERROR error, int toAbort, char *argFilename);