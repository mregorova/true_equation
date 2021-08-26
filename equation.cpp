#define _CRT_SECURE_NO_WARNINGS // turning off the warnings to make this thing work

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/*
double a = 0,  b = 0, c = 0;
double a = 0,  b = 4, c = 0;
double a = 20, b = 0, c = 0;
double a = 0,  b = 0, c = 0;
double a = 0,  b = 0, c = 0;
double a = 0,  b = 0, c = 0;
double a = 0,  b = 0, c = 0;
double a = 0,  b = 0, c = 0;
double a = 0,  b = 0, c = 0;
double a = 0,  b = 0, c = 0;
*/

// Keep reading from input stream until a newline is read
void flushInput()
{
    int c;

    do
    {
        if ((c = getchar()) == EOF)
        {
            exit(1);
        }
    } while (c != '\n');
}

int linear(double a, double b, double c, double* x1)
{
    if (b == 0)
    {
        if (c == 0)
        {
            return -1;
        }

        else
        {
            return 0;
        }
    }

    else
    {
        *x1 = -c / b;
        return 1;
    }

    return 777;
}

double discriminant(double a, double b, double c)
{
    double d = pow(b, 2) - 4 * a * c;

    return d;
}

int quadratic(double a, double b, double c, double* x1, double* x2)
{
    double d = 0;
    d = discriminant(a, b, c); // counting discriminant

    if (d >= 0)
    { // discovering different types of solutions
        if (d == 0)
        {
            *x1 = (-b) / (a * 2);

            return 1;
        }

        else
        {
            *x1 = (-b + sqrt(d)) / (a * 2);
            *x2 = (-b - sqrt(d)) / (a * 2);

            return 2;
        }
    }

    return 0;
}


int solve(double a, double b, double c, double* x1, double* x2)
{
    if (a == 0)
    {
        return linear(a, b, c, x1);
    }
    else
    {
        return quadratic(a, b, c, x1, x2);
    }
}

int main() {

    double a = 0;
    double b = 0;
    double c = 0;

    double x2 = 0;
    double x1 = 0;

    printf("Enter coefficients a b c: \n");

    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        printf("Please try again\n");

        scanf("%lg %lg %lg", &a, &b, &c);

        // fflush(stdin);

        flushInput();

    }

    solve(a, b, c, &x1, &x2);

    //assert(x1 != NULL);
    //assert(x2 != NULL);

    // assert(std::isfinite(a));
    // assert(isfinite(b));
    // assert(isfinite(c));

    switch (solve(a, b, c, &x1, &x2))
    {
    case -1:
        printf("Infinite number of solutions");
        break;
    case 0:
        printf("No solutions :(");
        break;
    case 1:
        printf("x = %lg", x1);
        break;
    case 2:
        printf("x1 = %lg x2 = %lg", x1, x2);
        break;
    default:
        printf("Something went wrong");
        break;
    }


    return 0;
}