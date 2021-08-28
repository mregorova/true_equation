#include "equation.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

double discriminant_computing(double a, double b, double c)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    double d = b * b - 4 * a * c;

    return d;
}

    //int isnan(double x);
int cmp_doubles(double num1, double num2)
{
    assert(isfinite(num1));
    assert(isfinite(num2));

    return (fabs(num1 - num2) < Precision);
}

Solves_Amount solve(double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (cmp_doubles(a, 0))
    {
        return solve_linear(b, c, x1);
    }
    else
    {
        return solve_quadratic(a, b, c, x1, x2);
    }
}

/**
    Function for linear equation

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    @param[out] x1 is the solution
    */

Solves_Amount solve_linear(double b, double c, double* x1)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);

    if (cmp_doubles(b, 0))
    {
        if (cmp_doubles(c, 0))
        {
            return INF_SOLUTIONS;
        }

        else
        {
            return NO_SOLUTIONS;
        }
    }

    else
    {
        *x1 = -c / b;
        return ONE_SOLUTION;
    }

    return ERROR_IN_LINEAR;
}

Solves_Amount solve_quadratic(double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x2 != NULL);

    if (cmp_doubles(c, 0)) 
    {
        *x1 = 0;
        *x2 = -b / a;

        return TWO_SOLUTIONS;
    }

    double d = discriminant_computing(a, b, c); // computing discriminant

    assert(isfinite(d));

    if (cmp_doubles(d, 0))
    {
        *x1 = (-b) / (a * 2);

        return ONE_SOLUTION;
    }

    else
    {
        if (d < 0)
        {
            return NO_SOLUTIONS;
        }

        else
        {
            d = sqrt(d);
            *x1 = (-b + d) / (a * 2);
            *x2 = (-b - d) / (a * 2);

            return TWO_SOLUTIONS;
        }
    }
}