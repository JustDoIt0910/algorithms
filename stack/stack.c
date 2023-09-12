//
// Created by just do it on 2023/9/11.
//
#include "stack.h"

Bool InitStack(sqStack* stack)
{
    if(!stack)
        return false;
    stack->base = malloc( STACK_INIT_SIZE * sizeof(STACK_ELEM));
    if(!stack->base)
        return false;
    stack->top = stack->base;
    return true;
}

void DestoryStack(sqStack* stack)
{
    if(stack && stack->base)
        free(stack->base);
}

void ClearStack(sqStack* stack)
{
    if(!stack)
        return;
    stack->top = stack->base;
}

size_t StackLength(sqStack* stack)
{
    if(!stack)
        return 0;
    return stack->top - stack->base;
}

Bool StackEmpty(sqStack* stack)
{
    if(!stack)
        return true;
    return stack->top == stack->base;
}

Bool Top(sqStack* stack, STACK_ELEM* e)
{
    if(!stack || stack->top == stack->base)
        return false;
    *e = *(stack->top - 1);
    return true;
}

Bool Push(sqStack* stack, STACK_ELEM e)
{
    if(!stack)
        return false;
    if(stack->top - stack->base >= stack->size)
    {
        STACK_ELEM* b = realloc(stack->base,
                              (stack->size + STACK_INCREMENT) * sizeof(STACK_ELEM));
        if(!b) return false;
        stack->base = b;
    }
    *(stack->top++) = e;
    return true;
}

Bool Pop(sqStack* stack, STACK_ELEM* e)
{
    if(!stack || stack->top == stack->base)
        return false;
    *e = *(--stack->top);
    return true;
}