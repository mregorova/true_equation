#include "tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int equationTest(int numTest, double a, double b, double c, int numSols_main, double x1_main, double x2_main)
{

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(x1_main));
    assert(isfinite(x2_main));

    //static int numTest = 0;
    //numTest++;

    double x1 = 0;
    double x2 = 0;
    int numSols = solve(a, b, c, &x1, &x2);
    if (numSols != numSols_main)
    {
        printf("Test %d failed: a = %lg, b = %lg, c = %lg; Solutions: %lg %lg - Should be: %lg %lg", 
                numTest, a, b, c, x1, x2, x1_main, x2_main);

        return 0;
    }
    else
    {
        if (!cmp_doubles(x1, x1_main) || !cmp_doubles(x2, x2_main))
        {
            printf("Test %d failed: a = %lg, b = %lg, c = %lg; Solutions: %lg %lg - Should be: %lg %lg", 
                    numTest, a, b, c, x1, x2, x1_main, x2_main);

            return 0;
        }
        else
        {
            printf("Test %d is succed\n", numTest);
            return 1;
        }
    }
}

int runEquationTest()
{
    int failed = 0;
    
    if (equationTest(__LINE__, 0,  0,  0, -1,  0,  0) == 0) failed++; // number of test, a, b, c, amount of solutions, first solution, second solution
    if (equationTest(__LINE__, 1,  2, -3,  2,  1, -3) == 0) failed++;
    if (equationTest(__LINE__, 0,  4,  0,  1,  0,  0) == 0) failed++;
    if (equationTest(__LINE__, 0,  2, -4,  1,  2,  0) == 0) failed++;
    if (equationTest(__LINE__, 0,  0, 13,  0,  0,  0) == 0) failed++;
    if (equationTest(__LINE__, 1, -1,  3,  0,  0,  0) == 0) failed++;
    if (equationTest(__LINE__, 1,  4,  4,  1, -2,  0) == 0) failed++;

    return failed;
}