//
// Created by just do it on 2023/9/11.
//

#ifndef ALGORITHM_STACK_H
#define ALGORITHM_STACK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "common.h"
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

#ifndef STACK_ELEM
#define STACK_ELEM int
#else
    typedef struct BiTreeNode* BiTree;
#endif

typedef struct
{
    STACK_ELEM* base, *top;
    size_t size;
} sqStack;

Bool InitStack(sqStack* stack);
void DestoryStack(sqStack* stack);
void ClearStack(sqStack* stack);
size_t StackLength(sqStack* stack);
Bool StackEmpty(sqStack* stack);
Bool Top(sqStack* stack, STACK_ELEM* e);
Bool Push(sqStack* stack, STACK_ELEM e);
Bool Pop(sqStack* stack, STACK_ELEM* e);

#ifdef __cplusplus
}
#endif

#endif //ALGORITHM_STACK_H
