//
// Created by just do it on 2023/9/2.
//
#include "queue.h"
#include <stdlib.h>

/********************* 循环队列 **********************/

void initQueue(Queue* q, int size)
{
    q->rear = q->front = 0;
    q->size = size;
    q->data = malloc(sizeof(Elem) * size);
}

int isEmpty(Queue* q)
{
    return q->rear == q->front;
}

int enQueue(Queue* q, Elem e)
{
    if((q->rear + 1) % q->size == q->front)
        return -1;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % q->size;
    return 0;
}

int deQueue(Queue* q, Elem* e)
{
    if(isEmpty(q))
        return -1;
    *e = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    return 0;
}

/********************** 链式队列 ***********************/

void initQueueL(LinkQueue* q)
{
    q->front = q->rear = malloc(sizeof(Node));
}

int isEmptyL(LinkQueue* q)
{
    return q->front == q->rear;
}

int enQueueL(LinkQueue* q, Elem e)
{
    Node* node = malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
    return 0;
}

int deQueueL(LinkQueue* q, Elem* e)
{
    if(isEmptyL(q))
        return -1;
    Node* first = q->front->next;
    *e = first->data;
    q->front->next = first->next;
    if(q->rear == first)
        q->rear = q->front;
    free(first);
    return 0;
}