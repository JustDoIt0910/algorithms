//
// Created by zr on 23-1-5.
// https://blog.csdn.net/v_july_v/article/details/7041827#t9
//

#include <string.h>
#include <stdlib.h>
#include "kmp.h"

void getNext(const char* pat, int* next)
{
    int M = strlen(pat);
    int k = -1; int j = 0;
    next[0] = -1;
    while(j < M - 1)
    {
        if(k == -1 || pat[k] == pat[j])
            next[++j] = ++k;
        else
            k = next[k];
    }
}

int kmp_search_v1(const char* txt, const char* pattern)
{
    int N = strlen(txt);
    int M = strlen(pattern);
    int* next = (int*) malloc(M * sizeof(int));
    getNext(pattern, next);
    int i = 0; int j = 0;
    while (i < N && j < M)
    {
        if(j == -1 || txt[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    free(next);
    if(j == M)
        return i - M;
    return N;
}