#ifndef __SSTRING_H_
#define __SSTRING_H_

#include <string.h>
#include <stdlib.h>

typedef char* sstring_t;

sstring_t sstringNew(const char* str);
void sstringFree(sstring_t sstr);
unsigned int sstringLength(const sstring_t sstr);
sstring_t sstringDup(const sstring_t sstr);
sstring_t sstringCat(sstring_t dest, const char* str);
sstring_t sstringCatSStr(sstring_t dest, const sstring_t sstr);

#endif