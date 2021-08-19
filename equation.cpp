

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <math.h>


int main()
{
    float a,b,c;

    printf("Enter a: ");
    scanf("%f", &a);

    printf("Enter b: ");
    scanf("%f", &b);

    printf("Enter c: ");
    scanf("%f", &c);

    float d;
    d = pow(b,2) - 4*a*c;

    float x1, x2;
    x1 = (-b + sqrt(d)) / (a*2);
    x2 = (-b - sqrt(d)) / (a*2);

    printf("x1 = %f x2 = %f", x1,x2);

    return 0;
}
