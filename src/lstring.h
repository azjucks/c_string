#ifndef __LSTRING_H_
#define __LSTRING_H_

#include <stdlib.h>
#include <string.h>

typedef struct lstring_t
{
    unsigned int length;
    char* buffer;
} lstring_t;

lstring_t lstringNew(const char* str);

void lstringFree(lstring_t lstr);

lstring_t lstringCat(lstring_t dest, lstring_t str);

#endif