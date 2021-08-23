#define _CRT_SECURE_NO_WARNINGS //turning off the warnings to make this thing work

#include <stdio.h>
#include <math.h>


int main() {
    float a = 0;
    printf("Enter a: "); //entering coefficients
    scanf("%f", &a);

    float b = 0;
    printf("Enter b: ");
    scanf("%f", &b);

    float c = 0;
    printf("Enter c: ");
    scanf("%f", &c);

    if (a == 0) { //checking if our equation is quadratic
        void lineal(float a, float b, float c);
        lineal(a, b, c);
    }
    else {
        void quadratic(float a, float b, float c);
        quadratic(a, b, c);
    }
    return 0;
}

void lineal(float a, float b, float c)
{
    float x4 = 0;
    x4 = -c / b;
    printf("x = %f", x4);
}

void quadratic(float a, float b, float c)
{
    float d = 0;
    float discriminant(float a, float b, float c);
    d = discriminant(a, b, c); //counting discriminant

    if (d >= 0) { //discovering different types of solutions
        if (d == 0) {
            float x3 = 0;
            x3 = (-b) / (a * 2);

            printf("x = %f", x3);
        }
        else {
            float x1 = 0;
            x1 = (-b + sqrt(d)) / (a * 2);
            float x2 = 0;
            x2 = (-b - sqrt(d)) / (a * 2);

            printf("x1 = %f x2 = %f", x1, x2);
        }
    }
    else {
        printf("No solutions :(");
    }
}

float discriminant(float a, float b, float c)
{
    float d = 0;
    d = pow(b, 2) - 4 * a * c; 
    return d;
}