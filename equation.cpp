//! @file equation.cpp
//! @mainpage Programm working with square equations
//! - equation.cpp
//!@author Egorova MS
//!@brief Used for solving square equations

#define _CRT_SECURE_NO_WARNINGS // turning off the warnings to make this thing work
//#define TESTS

enum Solves_Amount
{
    ERROR_IN_LINEAR = 777,
    INF_SOLUTIONS = -1,
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2
};

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

const double precision = 1e-10; // coefficient for comparing doubles (in a case of "rubbish")

void flushInput();
int input(double* a, double* b, double* c);
int cmp_doubles(double num1, double num2);
Solves_Amount linear(double b, double c, double* x1);
double discriminant(double a, double b, double c);
Solves_Amount quadratic(double a, double b, double c, double* x1, double* x2);
Solves_Amount solve(double a, double b, double c, double* x1, double* x2);
int equationTest(double a, double b, double c, int numSols_main, double x1_main, double x2_main);
int runEquationTest();
void printAnswer(double a, double b, double c, Solves_Amount numSols, double x1, double x2);


/**
    int main()
    ! Entering the coefficients and getting the solutions
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

/**
    void flushInput()
    ! It is used for clearing the buffer, which allows to scan vals many times
    */

    // Keep reading from input stream until a newline is read
void flushInput()
{
    int c = 0;

    do
    {
        if ((c = getchar()) == EOF) exit(1);
    } while (c != '\n');
}

/**
    int cmp_doubles(double num1, double num2)
    ! It is used for comparing two double numbers
    @param[in] num1 is first comparing number
    @param[in] num2 is second comparing number
    @param[out] 1 - numbers are equal
    @param[out] 0 - numbers aren't equal
    */

    //int isnan(double x);
int cmp_doubles(double num1, double num2)
{
    assert(isfinite(num1));
    assert(isfinite(num2));

    return (fabs(num1 - num2) < precision);
}

/**
    int linear(double a, double b, double c, double* x1)
    ! Function for linear equation

    !@param[in] a is first coef
    !@param[in] b is second coef
    !@param[in] c is third coef
    !@param[out] x1 is the solution
    */

Solves_Amount linear(double b, double c, double* x1)
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

/**
    double discriminant(double a, double b, double c)
    ! Function for counting discriminant

    !@param[in] a is first coef
    !@param[in] b is second coef
    !@param[in] c is third coef
    !@param[out] d is the discriminant
    */

double discriminant(double a, double b, double c)
{    
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    
    double d = b*b - 4 * a * c;

    return d;
}

/**
    int quadratic(double a, double b, double c, double* x1, double* x2)
    ! Function for square equation

    !@param[in] a is first coef
    !@param[in] b is second coef
    !@param[in] c is third coef
    !@param[out] x1 is the first solution
    !@param[out] x2 is the second solution
    */

Solves_Amount quadratic(double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);

    double d = 0;
    d = discriminant(a, b, c); // counting discriminant

    assert(isfinite(d));

    if (d >= -precision)
    { // discovering different types of solutions
        if (cmp_doubles(d, 0))
        {
            *x1 = (-b) / (a * 2);

            return ONE_SOLUTION;
        }

        else
        {
            d = sqrt(d);
            *x1 = (-b + d) / (a * 2);
            *x2 = (-b - d) / (a * 2);

            return TWO_SOLUTIONS;
        }
    }

    return NO_SOLUTIONS;
}

/**
    int solve(double a, double b, double c, double* x1, double* x2)
    ! Function for the whole solution

    !@param[in] a is first coef
    !@param[in] b is second coef
    !@param[in] c is third coef
    !@param[out] x1 is the first solution
    !@param[out] x2 is the second solution
    */


Solves_Amount solve(double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
    assert(x2 != NULL);
    
    if (cmp_doubles(a, 0))
    {
        return linear(b, c, x1);
    }
    else
    {
        return quadratic(a, b, c, x1, x2);
    }
}

/**
    int equationTest(int numTest, double a, double b, double c, int numSols_main, double x1_main, double x2_main)
    ! Unit test

    !@param[in] a is first coef
    !@param[in] b is second coef
    !@param[in] c is third coef
    !@param[in] numSols_main is the expected number of solutions
    !@param[in] x1_main is the expected solution
    !@param[in] x2_main is the expected solution
    !@param[out] numSols is the number of solutions
    !@param[out] x1 is the solution
    !@param[out] x2 is the solution
    */

int equationTest(double a, double b, double c, int numSols_main, double x1_main, double x2_main)
{
    
        assert(isfinite(a));
        assert(isfinite(b));
        assert(isfinite(c));
        assert(isfinite(x1_main));
        assert(isfinite(x2_main));
        
        static int numTest = 0;
        numTest++;

        double x1 = 0;
        double x2 = 0;
        int numSols = solve(a, b, c, &x1, &x2);
        if (numSols != numSols_main)
        {
            printf("Test %d failed: a = %lg, b = %lg, c = %lg; Solutions: %lg %lg - Should be: %lg %lg", numTest, a, b, c, x1, x2, x1_main, x2_main);
            return 0;
        }
        else
        {
            if (!cmp_doubles(x1, x1_main) || !cmp_doubles(x2, x2_main))
            {
                printf("Test %d failed: a = %lg, b = %lg, c = %lg; Solutions: %lg %lg - Should be: %lg %lg", numTest, a, b, c, x1, x2, x1_main, x2_main);
                return 0;
            }
            else
            {
                printf("Test %d is succed\n", numTest);
                return 1;
            }
        }
    
}

/**
    int runEquationTest()
    ! Running unit test

    !@param[out] failed is the number of failed tests
    */

int runEquationTest() 
{
    int failed = 0;
    if (equationTest(0, 0,  0, -1,  0,  0) == 0) failed++;
    if (equationTest(1, 2, -3,  2,  1, -3) == 0) failed++;
    if (equationTest(0, 4,  0,  1,  0,  0) == 0) failed++;
    if (equationTest(0, 2, -4,  1,  2,  0) == 0) failed++;
    if (equationTest(0, 0, 13,  0,  0,  0) == 0) failed++;
    if (equationTest(1,-1,  3,  0,  0,  0) == 0) failed++;
    if (equationTest(1, 4,  4,  1, -2,  0) == 0) failed++;
    return failed;
}

/**
    int input(double* a, double* b, double* c)
    ! Function for entering the coefficients

    !@param[in] a is first coef
    !@param[in] b is second coef
    !@param[in] c is third coef
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
    void printAnswer(double a, double b, double c, double x1, double x2)
    ! Function for giving the answer

    !@param[in] a is first coef
    !@param[in] b is second coef
    !@param[in] c is third coef
    !@param[out] x1 is the first solution
    !@param[out] x2 is the second solution
    */

void printAnswer(double a, double b, double c, Solves_Amount numSols, double x1, double x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);
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