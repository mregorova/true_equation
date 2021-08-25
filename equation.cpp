#define _CRT_SECURE_NO_WARNINGS //turning off the warnings to make this thing work

#include <stdio.h>
#include <math.h>


int main() {
    double a = 0;
    char msg_a[] = "Enter a: ";
    double get_double(const char* msg_a);
    a = get_double(msg_a);

    double b = 0;
    char msg_b[] = "Enter b: ";
    double get_double(const char* msg_b);
    b = get_double(msg_b);

    double c = 0;
    char msg_c[] = "Enter c: ";
    double get_double(const char* msg_c);
    c = get_double(msg_c);

    if (a == 0) { //checking if our equation is quadratic
        void lineal(double a, double b, double c);
        lineal(a, b, c);
    }
    else {
        void quadratic(double a, double b, double c);
        quadratic(a, b, c);
    }
    return 0;
}

void lineal(double a, double b, double c)
{
    double x4 = 0;
    x4 = -c / b;
    printf("x = %f", x4);
}

void quadratic(double a, double b, double c)
{
    double d = 0;
    double discriminant(double a, double b, double c);
    d = discriminant(a, b, c); //counting discriminant

    if (d >= 0) { //discovering different types of solutions
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

double get_double(const char* msg) {
    char answer[256];  // строка для чтения
    double x; // итоговое вещественное число

    printf("%s", msg); // выводим приглашение ко вводу
    fgets(answer, sizeof(answer), stdin); // считываем строку

    // пока не будет считано вещественное число
    while (sscanf(answer, "%lf", &x) != 1) {
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
        fgets(answer, sizeof(answer), stdin); // и заново считываем строку
    }

    return x; // воозвращаем корректное вещественное число
}