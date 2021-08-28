#pragma once

enum Solves_Amount
{
    ERROR_IN_LINEAR = 777,
    INF_SOLUTIONS = -1,
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2
};

const double Precision = 1e-10; //!< coefficient for comparing doubles (in a case of "rubbish")

/**
    It is used for clearing the buffer, which allows to scan vals many times
    */

void flushInput();
int input(double* a, double* b, double* c);

/**
    It is used for comparing two double numbers
    @param[in] num1 is first comparing number
    @param[in] num2 is second comparing number
    @param[out] 1 - numbers are equal
    @param[out] 0 - numbers aren't equal
    */

int cmp_doubles(double num1, double num2);
Solves_Amount solve_linear(double b, double c, double* x1);

/**
    Function for computing discriminant

    @param[in] a is first coef!
    @param[in] b is second coef!!
    @param[in] c is third coef!!!
    @param[out] d is the discriminant!!!!
    */

double discriminant_computing(double a, double b, double c);

/**
    Function for square equation

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    @param[out] x1 is the first solution
    @param[out] x2 is the second solution
    */


Solves_Amount solve_quadratic(double a, double b, double c, double* x1, double* x2);


/**
    Function for the whole solution

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    @param[out] x1 is the first solution
    @param[out] x2 is the second solution
    */

Solves_Amount solve(double a, double b, double c, double* x1, double* x2);
void printAnswer(double a, double b, double c, Solves_Amount numSols, double x1, double x2);
