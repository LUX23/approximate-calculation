#include <stdio.h>
#include <conio.h>
#include <locale.h>


double series(double x, double eps);
int main()
{
    setlocale (LC_CTYPE, "RUSSIAN");

    double A, B, r, eps; // A, B - границы интервала табулирования
                         // r - шаг табулирования
                         // eps - допустимая погрешность
    printf("\n\tПечатается таблица функции, заданной рядом Тейлора\n"
           "\n\tВведите границы интервала\n");

    do
    {
        printf("\n\t\tЛевая:   ");
        scanf("%lf", &A);
        printf("\t\tПравая:  ");
        scanf("%lf", &B);
        if(A >= B)
            printf("\n\t\tЛевая должна быть меньше правой! Повторите.\n");
    }
    while(A >= B);

    printf("\n\n\tВведите шаг табулирования: ");

    do
    {
        scanf("%lf", &r);
        if(B - A < r || r <=0)
            printf("\n\t\tШаг должен быть меньше длины интервала и быть больше 0!"
                         "\n\t\tПовторите: ");
    }
    while(B - A < r || r <=0);

    printf("\n\tВведите допустимую погрешность вычисления"
           "\n\n\t\t0 < eps < 1: ");

    do
    {
        scanf("%lf", &eps);
        if (eps >= 1 || eps <= 0)
            printf("\n\tВведено недопустимое значение. Положено eps = 0.00001."
                                    "\n\tПовторите: ");

    }
    while(eps >= 1 || eps <= 0);

    printf("\n\n\t\t\tТаблица"
           "\n\n\t\t+----------+--------------+"
             "\n\t\t|    x     |      F(x)    |"
             "\n\t\t+----------+--------------+"); 
    
    for(double x = A; x <= B + eps; x += r)
    {
        printf("\n\t\t|%8.2lf  |%12.4lf  |", x, series(x, eps)); // x - текущее значение аргумента
                                                                 // series(x, eps) - вычисленное значение функции
        printf("\n\t\t+----------+--------------+");
    } 

    getch();
    return 0;
}
