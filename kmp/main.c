//
// Created by zr on 23-1-5.
//
#include "kmp.h"
#include "stdio.h"

int main()
{
    const char* txt = "abcdwhccdxdqw";
    const char* pat = "cdxd";
    printf("%d\n", kmp_search_v2(txt, pat));
    printf("%d\n", kmp_search_v1(txt, pat));
    return 0;
}