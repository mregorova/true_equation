//@file equation.cpp
//@mainpage Programm working with square equations
// - equation.cpp
//@author Egorova MS
//@brief Used for solving square equations

#define _CRT_SECURE_NO_WARNINGS // turning off the warnings to make this thing work

#define TESTS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "equation.h"
#include "tests.h"

/**
    Entering the coefficients and getting the solutions
    */

int main() {

    double a = 0;
    double b = 0;
    double c = 0;

    double x2 = 0;
    double x1 = 0;

#ifdef TESTS

    runEquationTest();

#else

    input(&a, &b, &c);
    Solves_Amount numSols = solve(a, b, c, &x1, &x2);
    printAnswer(a, b, c, numSols, x1, x2);

#endif

    return 0;
}

    // Keep reading from input stream until a newline is read
void flushInput()
{
    int c = 0;

    while (c = getchar() != '\n' && c != EOF) ;
}

/**
    Function for entering the coefficients

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    */

int input(double* a, double* b, double* c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf("Enter coefficients a b c: \n");

    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
        printf("Please try again\n");

        // fflush(stdin);

        flushInput();

    }

    return 1;
}

/**
     Function for giving the answer

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    @param[out] x1 is the first solution
    @param[out] x2 is the second solution
    */

void printAnswer(double a, double b, double c, Solves_Amount numSols, double x1, double x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x2 != NULL);

    //int numSols = solve(a, b, c, &x1, &x2);
    switch (numSols)
    {
        case INF_SOLUTIONS:
            printf("Infinite number of solutions");
            break;
 
        case NO_SOLUTIONS:
            printf("No solutions :(");
            break;
        
        case ONE_SOLUTION:
            printf("x = %lg", x1);
            break;

        case TWO_SOLUTIONS:
            printf("x1 = %lg x2 = %lg", x1, x2);
            break;

        default:
            printf("Something went wrong");
            break;
    }
}
