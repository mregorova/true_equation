#define _CRT_SECURE_NO_WARNINGS //turning off the warnings to make this thing work

#include <stdio.h>
#include <math.h>


int main(){
    float a = 0, b = 0, c = 0;

    printf("Enter a: "); //entering coefficients
    scanf("%f", &a);

    printf("Enter b: ");
    scanf("%f", &b);

    printf("Enter c: ");
    scanf("%f", &c);

    float x = 0;
    if (a == 0) { //checking if our equation is quadratic
        x = -c / b;

        printf("x = %f", x);
    }
    else {
        float d = 0;
        d = pow(b, 2) - 4 * a * c; //counting discriminant

        float x1 = 0, x2 = 0;

        if (d >= 0) { //discovering different types of solutions
            if (d == 0) {
                x = (-b) / (a * 2);

                printf("x = %f", x);
            }
            else {
                x1 = (-b + sqrt(d)) / (a * 2);
                x2 = (-b - sqrt(d)) / (a * 2);

                printf("x1 = %f x2 = %f", x1, x2);
            }
        }
        else {
            printf("No solutions :(");
        }
    }

    

    return 0;
}