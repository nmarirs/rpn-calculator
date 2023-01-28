#include <math.h>
#include <stdio.h>

#include "operations.h"

/*
    a is higher on stack than b
*/
double add(double a, double b)
{
    return b + a;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return b * a;
}

double divide(double a, double b)
{
    return a / b;
}

double exponent(double a, double b)
{
    return pow(a, b);
}

double _log10(double a)
{
    return log10(a);
}

double loge(double a)
{
    return log(a);
}

// are these really necessary?
double _sin(double a)
{
    return sin(a);
}

double _cos(double a)
{
    return cos(a);
}

double _tan(double a)
{
    return tan(a);
}

double _csc(double a)
{
    return 1/sin(a);
}

double _sec(double a)
{
    return 1/cos(a);
}

double _cot(double a)
{
    return 1/tan(a);
}

double factorial(double a)
{
    double result = 1;

    if (a - (int)a!= 0)
    {
        printf("%f is not an integer. Continuing with %d\n", a, (int)a);
    }
    while (a > 1)
    {
        result *= (int)a;
        a -= 1;
    }
    return result;
}