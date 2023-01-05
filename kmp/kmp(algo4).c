//
// Created by zr on 23-1-5.
// algorithms 4中使用自动机的kmp
// https://www.zhihu.com/question/24382751
//

#include "kmp.h"
#include <string.h>
#include <stdlib.h>

void getDFA(const char* pat, int** dfa, int R, int M)
{
    dfa[pat[0]][0] = 1;
    for(int X = 0, j = 1; j < M; j++)
    {
        for(int c = 0; c < R; c++)
            dfa[c][j] = dfa[c][X];
        dfa[pat[j]][j] = j + 1;
        X = dfa[pat[j]][X];
    }
}

int kmp_search_v2(const char* txt, const char* pattern)
{
    int R = 256;
    int M = strlen(pattern);
    int** dfa = (int**) malloc(R * sizeof(int*));
    for(int r = 0; r < R; r++)
        dfa[r] = (int*) malloc(M * sizeof(int));
    getDFA(pattern, dfa, R, M);
    int N = strlen(txt);
    int i, j;
    for(i = 0, j = 0; i < N && j < M; i++)
        j = dfa[txt[i]][j];
    for(int r = 0; r < R; r++)
        free(dfa[r]);
    free(dfa);
    if(j == M)
        return i - M;
    return N;
}