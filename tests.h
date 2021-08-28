#pragma once

enum Solves_Amount;

/** 

    Unit test

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    @param[in] numSols_main is the expected number of solutions
    @param[in] x1_main is the expected solution
    @param[in] x2_main is the expected solution
    @param[out] numSols is the number of solutions
    @param[out] x1 is the solution
    @param[out] x2 is the solution
    */


int equationTest(int numTest, double a, double b, double c, int numSols_main, double x1_main, double x2_main);

/**
    Running unit test

    @param[out] failed is the number of failed tests
    */


int runEquationTest();

/**
    Function for the whole solution

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    @param[out] x1 is the first solution
    @param[out] x2 is the second solution
    */

Solves_Amount solve(double a, double b, double c, double* x1, double* x2);

/**
    It is used for comparing two double numbers
    @param[in] num1 is first comparing number
    @param[in] num2 is second comparing number
    @param[out] 1 - numbers are equal
    @param[out] 0 - numbers aren't equal
    */

int cmp_doubles(double num1, double num2);

/**
    Function for the whole solution

    @param[in] a is first coef
    @param[in] b is second coef
    @param[in] c is third coef
    @param[out] x1 is the first solution
    @param[out] x2 is the second solution
    */

Solves_Amount solve(double a, double b, double c, double* x1, double* x2);