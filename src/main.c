#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "operations.h"
#include "stacks.h"


int isnum(char string[])
{
    for (char c = *string; c != '\0'; c = *++string)
    {
        if (!isdigit(c) && c != '.')
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("Reverse Polish Notation Calculator. b to burn. q to quit. v to view. p to pop. h for help\n");
    char token[30];
    Stack* value_stack = malloc(sizeof(Stack));
    stack_init(15, value_stack);

    while (1)
    {
        printf("> ");
        scanf("%s", token);   

        // quit
        if (token[0] == 'q')
        {
            printf("Quitting..\n");
            return 0;
        }
        // help
        if (token[0] == 'h')
        {
            printf("Available commands:\n"
            " Arithmetic: + , - , * , /\n"
            " Logarithms and Exponents: ^ , loge, log10\n"
            " Trigonometry: sin, cos, tan, csc, sec, cot\n"
            " Misc: !\n"
            "\n"
            "Calculator:\n"
            " q - quit\n"
            " v - view the entire stack\n"
            " b - burn/clear the stack (removes all stored values)\n"
            " p - pop/remove the highest item in the stack\n"
            " h - view this help page\n"
            "\n"
            "How to use:\n"
            "This calculator is based on the Postfix notation. The operands are written first followed by the operator\n"
            "Eg. a + b  ->  a b +\n"
            "To use the calculator, type out the operands first and hit Enter one by one to store them in the stack\n"
            "Call the operator by typing it after the operands have been entered\n"
            "For the above case, first enter 'a' followed by 'b' and then '+'\n"
            "");
        }
        // burn
        else if (token[0] == 'b')
        {
            stack_burn(value_stack);
            printf("Stack has burned to the ground\n");
        }
        // view
        else if (token[0] == 'v')
        {
            stack_view(value_stack);
        }
        // pop
        else if (token[0] == 'p')
        {
            double val = stack_pop(value_stack);
            printf("Popped stack, returned: %f\n", val);
        }
        // store
        else if (isnum(token))
        {
            int size = stack_push((double)atof(token), value_stack);
            printf("Pushed [%d] %f (store)\n", size, atof(token));
        }
        // operate
        else 
        {
            double result = 0;
            int skip = 0;
            if (strcmp(token, "+") == 0)
            {
                result = add(stack_pop(value_stack), stack_pop(value_stack));
            }
            else if (strcmp(token, "-") == 0)
            {
                result = subtract(stack_pop(value_stack), stack_pop(value_stack));
            }
            else if (strcmp(token, "*") == 0)
            {
                result = multiply(stack_pop(value_stack), stack_pop(value_stack));
            }
            else if (strcmp(token, "/") == 0)
            {
                result = divide(stack_pop(value_stack), stack_pop(value_stack));
            }
            else if (strcmp(token, "^") == 0)
            {
                result = exponent(stack_pop(value_stack), stack_pop(value_stack));
            }
            else if (strcmp(token, "loge") == 0)
            {
                result = loge(stack_pop(value_stack));
            }
            else if (strcmp(token, "log10") == 0)
            {
                result = _log10(stack_pop(value_stack));
            }
            else if (strcmp(token, "sin") == 0)
            {
                result = _sin(stack_pop(value_stack));
            }
            else if (strcmp(token, "cos") == 0)
            {
                result = _cos(stack_pop(value_stack));
            }
            else if (strcmp(token, "tan") == 0)
            {
                result = _tan(stack_pop(value_stack));
            }
            else if (strcmp(token, "cot") == 0)
            {
                result = _cot(stack_pop(value_stack));
            }
            else if (strcmp(token, "csc") == 0)
            {
                result = _csc(stack_pop(value_stack));
            }
            else if (strcmp(token, "sec") == 0)
            {
                result = _sec(stack_pop(value_stack));
            }
            else if (strcmp(token, "!") == 0)
            {
                result = factorial(stack_pop(value_stack));
            }
            else
            {
                printf("Invalid Command. Enter 'h' for help\n");
                skip = 1;
            }

            if (!skip)
            {
                int size = stack_push(result, value_stack);
                if (size > 0)
                {
                    printf("Pushed [%d] %f (eval)\n", size, result);
                }
            }
        }
        // clear buffer
        while (getchar() != '\n')
        {
            continue;
        }
    }
}