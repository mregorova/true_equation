#define _CRT_SECURE_NO_WARNINGS // turning off the warnings to make this thing work

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
1) ??????? ???? ?????? ?? 3 ?????????????
2) ?????????, ??? ??????????? ??? ?????? 3 ??????????
3) ???????????? ?????? ? ???????????: ????????? ???????????? ? ??????? ?? ??????????(&), ?????????????? ???????? ??????????
*/

/// TODO:
///4) - assert(isfinite(...))

void flushInput()
{
    // Keep reading from input stream until a newline is read
    int c;
    do
    {
        if ((c = getchar()) == EOF) exit(1);
    } while (c != '\n');
}

void linear(double a, double b, double c)
{
    if (b == 0) {
        if (c == 0) {
            printf("Infinity number of solutions\n");
        }
        else {
            printf("No solutions :(\n");
        }
    }
    else {
        double x4 = 0;
        x4 = -c / b;
        printf("x = %f", x4);
    }
    //return 0;
}

void quadratic(double a, double b, double c)
{
    double d = 0;
    double discriminant(double a, double b, double c);
    d = discriminant(a, b, c); // counting discriminant

    if (d >= 0) { // discovering different types of solutions
        if (d == 0) {
            double x3 = 0;
            x3 = (-b) / (a * 2);

            printf("x = %f", x3);
        }
        else {
            double x1 = 0;
            x1 = (-b + sqrt(d)) / (a * 2);
            double x2 = 0;
            x2 = (-b - sqrt(d)) / (a * 2);

            printf("x1 = %f x2 = %f", x1, x2);
        }
    }
    else {
        printf("No solutions :(");
    }
}

double discriminant(double a, double b, double c)
{
    double d = 0;
    d = pow(b, 2) - 4 * a * c;
    return d;
}

int main() {
    double a = 0, b = 0, c = 0;

    printf("Enter coefficients a b c: \n");
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3) {
        printf("Please try again\n");
        scanf("%lg %lg %lg", &a, &b, &c);
        flushInput();
    }

    if (a == 0) { // checking if our equation is quadratic
        linear(a, b, c);
    }
    else {
        quadratic(a, b, c);
    }
    return 0;
}