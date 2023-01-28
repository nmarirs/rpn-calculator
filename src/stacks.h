#ifndef STACKS_H
#define STACKS_H

typedef struct Node
{
    double value;
    struct Node* next;
} Node;

typedef struct Stack
{
    int maxsize;
    int size;
    Node* top;
} Stack;

// Initialise stack
int stack_init(int max, Stack *stk);

// Push to stack and return stack size
int stack_push(double value, Stack* stk);

// Burn the stack
int stack_burn(Stack* stk);

// Pop stack and return pooped value
double stack_pop(Stack* stk);

// View the stack
double stack_view(Stack* stk);

#endif