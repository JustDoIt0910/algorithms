//
// Created by just do it on 2023/9/2.
//

#ifndef ALGORITHM_QUEUE_H
#define ALGORITHM_QUEUE_H

#define Elem                    int

typedef struct Queue
{
    int front, rear;
    int size;
    Elem* data;
}Queue;

void initQueue(Queue* q, int size);
int isEmpty(Queue* q);
int enQueue(Queue* q, Elem e);
int deQueue(Queue* q, Elem* e);

typedef struct LinkQueueNode
{
    Elem data;
    struct LinkQueueNode* next;
}Node;

typedef struct LinkQueue
{
    Node* front, *rear;
}LinkQueue;

void initQueueL(LinkQueue* q);
int isEmptyL(LinkQueue* q);
int enQueueL(LinkQueue* q, Elem e);
int deQueueL(LinkQueue* q, Elem* e);

#endif //ALGORITHM_QUEUE_H
