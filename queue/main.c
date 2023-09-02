//
// Created by just do it on 2023/9/2.
//
#include "queue.h"
#include <stdio.h>

int main()
{
    Queue q;
    initQueue(&q, 10);
    for(int i = 1; i <= 20; i++)
        enQueue(&q, i);

    int e;
    while(!isEmpty(&q))
    {
        deQueue(&q, &e);
        printf("%d ", e);
    }
    printf("\n");
    LinkQueue lq;
    initQueueL(&lq);
    for(int i = 1; i <= 20; i++)
        enQueueL(&lq, i);

    while(!isEmptyL(&lq))
    {
        deQueueL(&lq, &e);
        printf("%d ", e);
    }
}