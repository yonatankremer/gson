#ifndef GSON_OBJ_H
#define GSON_OBJ_H
#endif

#ifndef BUFFER_SIZE
#include "buffer.h"
#endif

typedef struct
{
    char str[BUFFER_SIZE];
    int num;
    struct gsonObj *obj;
} gsonObj;