// Написать функцию, возвращающую значение вычисленное с заданной точностью eps.
// Функцию протестировать в интервале [A, B] с шагом r.
// Значения A, B, r, eps в программу вводить с клавиатуры.
// Результаты вычислений выводить в виде таблицы.
#include <stdio.h>
#include <conio.h>
#include <locale.h>

double series(double x, double eps);
int main()
{
    setlocale (LC_CTYPE, "RUSSIAN");

    double A, B, r, eps;

    printf("\n\tПечатается таблица функции, заданной рядом Тейлора\n"
           "\n\tВведите границы интервала\n");

    do
    {
        printf("\n\t\tЛевая:   ");
        scanf("%lf", &A);
        printf("\t\tПравая:  ");
        scanf("%lf", &B);
        if(A > B)
            printf("\n\t\tЛевая должна быть меньше правой! Повторите.\n");
    }
    while(A >= B);
    
    printf("\n\n\tВведите шаг табулирования: ");

    do
    {
        scanf("%lf", &r);
        if(B - A < r)
            printf("\n\t\tШаг должен быть меньше длины интервала!"
                         "\n\t\tПовторите: ");
    }
    while(B - A < r);
    
    printf("\n\tВведите допустимую погрешность вычисления"
           "\n\n\t\t0 < eps < 1: ");

    do
    {
        scanf("%lf", &eps);
        if (eps >= 1 || eps <= 0)
            printf("\n\tВведено недопустимое значение."
                                    "\n\tПовторите: ");

    }
    while(eps >= 1 || eps <= 0);
    
    printf("\n\n\t\t\tТаблица"
           "\n\n\t\t+----------+--------------+"
             "\n\t\t|    x     |      F(x)    |"
             "\n\t\t+----------+--------------+");

    for(double x = A; x <= B + eps; x += r)
    {
        printf("\n\t\t|%8.2lf  |%12.4lf  |", x, series(x, eps));
        printf("\n\t\t+----------+--------------+");
    }

    getch();
    return 0;
}
