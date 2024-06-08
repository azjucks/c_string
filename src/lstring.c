#include "lstring.h"

lstring_t lstringNew(const char* str)
{
    lstring_t lstring;
    unsigned int len = strlen(str);

    lstring.length = len;
    lstring.buffer = calloc(lstring.length, sizeof(char));
    memcpy(lstring.buffer, str, lstring.length * sizeof(char));

    return lstring;
}

void lstringFree(lstring_t lstr)
{
    free(lstr.buffer);
}

lstring_t lstringCat(lstring_t dest, lstring_t str)
{
    int dest_len = dest.length;

    dest.length += str.length;
    dest.buffer = realloc(dest.buffer, (dest.length + 1) * sizeof(char));

    memcpy(dest.buffer + dest_len, str.buffer, (dest.length + 1) * sizeof(char));

    return dest;
}