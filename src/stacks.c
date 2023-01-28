#include <stdlib.h>
#include <stdio.h>

#include "stacks.h"

int stack_init(int max, Stack *stk)
{
    stk->maxsize = max;
    stk->size = 0;
}

int stack_push(double value, Stack* stk)
{
    Node* new = malloc(sizeof(Node));
    if (stk->maxsize == stk->size)
    {
        printf("Stack Overflow on %p\n", stk);
        free(new);
        return -1;
    }
    else if (stk->size == 0)
    {
        new->next = NULL;
        new->value = value;
    }
    else
    {
        new->next = stk->top;
        new->value = value;
    }
    stk->size += 1;
    stk->top = new;
    return stk->size;
}

double stack_pop(Stack* stk)
{
    if (stk->size <= 0)
    {
        return 0;
    }
    double val = stk->top->value;
    Node* tofree = stk->top;

    stk->top = stk->top->next;
    free(tofree);
    stk->size -= 1;

    return val;
}

int stack_burn(Stack* stk)
{
    Node* head = stk->top;
    Node* tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    stk->size = 0;
    return 0;
}

double stack_view(Stack* stk)
{
    Node* head = stk->top;
    int level = stk->size;
    while (head != NULL)
    {
        printf("[%2d] -> %f\n", level, head->value);
        head = head->next;
        level -= 1;
    }
}