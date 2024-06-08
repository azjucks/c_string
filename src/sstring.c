#include <stdio.h>

#include "sstring.h"

sstring_t sstringNew(const char* str)
{
    unsigned int len = strlen(str);
    void* buffer = calloc(1, sizeof(int) + (1 + len) * sizeof(char));

    unsigned char* bufferAsBytes = buffer;

    int* firstInt = (int*)(bufferAsBytes + 0);
    *firstInt = len;

    char* ch = (char*)(bufferAsBytes + sizeof(int));

    ch = memcpy(ch, str, (len + 1) * sizeof(char));

    return (sstring_t)buffer + sizeof(int);
}

unsigned char* getBuffer(sstring_t sstr)
{
    return (unsigned char*)sstr - sizeof(int);
}

void sstringFree(sstring_t sstr)
{
    unsigned char* buffer = getBuffer(sstr);
    free(buffer);
}

unsigned int sstringLength(const sstring_t sstr)
{
    unsigned char* buffer = getBuffer(sstr);
    return *(int*)(buffer);
}

sstring_t sstringDup(const sstring_t sstr)
{
    unsigned int len = sstringLength(sstr);
    void* buffer = calloc(1, sizeof(int) + (1 + len) * sizeof(char));

    unsigned char* bufferAsBytes = buffer;

    int* firstInt = (int*)(bufferAsBytes + 0);
    *firstInt = len;

    char* ch = (char*)(bufferAsBytes + sizeof(int));

    ch = memcpy(ch, sstr, (len + 1) * sizeof(char));

    return (sstring_t)buffer + sizeof(int);
}

sstring_t sstringCat(sstring_t dest, const char* str)
{
    unsigned int dest_len = sstringLength(dest);
    unsigned int str_len = strlen(str);

    unsigned char* buffer = getBuffer(dest);

    int* firstInt = (int*)buffer;
    *firstInt += str_len;

    buffer = realloc(buffer, sizeof(int) + (*firstInt + 1) * sizeof(char));

    char* ch = (char*)(buffer + sizeof(int));

    ch = memcpy(ch + dest_len, str, (str_len + 1) * sizeof(char));

    return (sstring_t)buffer + sizeof(int);
}

sstring_t sstringCatSStr(sstring_t dest, const sstring_t sstr)
{
    unsigned int dest_len = sstringLength(dest);
    unsigned int sstr_len = sstringLength(sstr);

    unsigned char* dest_buffer = getBuffer(dest);

    int* firstInt = (int*)dest_buffer;
    *firstInt += sstr_len;
    
    dest_buffer = realloc(dest_buffer, sizeof(int) + (*firstInt + 1) * sizeof(char));

    char* ch = (char*)(dest_buffer + sizeof(int));

    ch = memcpy(ch + dest_len, (char*)sstr, (sstr_len + 1) * sizeof(char));

    return (sstring_t)dest_buffer + sizeof(int);
}