
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lstring.h"
#include "sstring.h"

void test1()
{
    char* str = strdup("a string");
    printf("string : %s (length=%d)\n", str, (unsigned int)strlen(str));
    free(str);
}

void test2()
{
    lstring_t str = lstringNew("a string");
    printf("lstring : %s (length=%d)\n", str.buffer, str.length);

    lstringFree(str);
}

void test3()
{
    lstring_t str1 = lstringNew("a string");
    lstring_t str2 = lstringNew(" and an other string");
    str1 = lstringCat(str1, str2);

    printf("lstring : %s (length=%d)\n", str1.buffer, str1.length);

    lstringFree(str2);
    lstringFree(str1);
}

void test4()
{
    sstring_t str = sstringNew("a string");
    printf("sstring : %s (length=%d)\n", str, sstringLength(str));
    sstring_t str_dup = sstringDup(str);
    printf("sstring_dup : %s (length=%d)\n", str_dup, sstringLength(str_dup));
    str = sstringCat(str, " salut");
    printf("sstring_cat : %s (length=%d)\n", str, sstringLength(str));

    str = sstringCatSStr(str, str_dup);
    printf("sstring_cat_sstr : %s (length=%d)\n", str, sstringLength(str));


    sstringFree(str);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
