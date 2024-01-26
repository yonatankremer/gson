#ifndef ERROR_H
#include "errorHandling/errorHandler.h"
#endif

#ifndef MAX_FILE_LENGTH
#include "maxFileLength.h"
#endif

#include <string.h>

void getArg(char filename[]);
ERROR safeArg(char filename[]);