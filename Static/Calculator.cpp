#include "Calculator.h"
int Calculator::add(int a, int b)
{
    return a + b;
}
int Calculator::sub(int a, int b)
{
    return a - b;
}
int Calculator::mult(int a, int b)
{
    return a * b;
}
float Calculator::div(int a, int b)
{
    if (!b)
        throw "cannot divide by zero\n";
    return (float)a / b;
}