#include <stdio.h>
#include <conio.h>
#include <locale.h>

double series(double, double);
int main()
{
    char *locale = setlocale(LC_ALL, "RUSSIAN");

    double A, B;
    printf("\n\t���������� ������� �������, �������� ����� �������\n"
           "\n\t������� ������� ���������\n");

    do
    {
        printf("\n\t\t�����:   ");
        scanf("%lf", &A);
        printf("\t\t������:  ");
        scanf("%lf", &B);
        if(A > B)
            printf("\n\t\t����� ������ ���� ������ ������! ���������.\n");
    }
    while(A > B);

    double r, eps;
    printf("\n\n\t������� ��� �������������: ");

    do
    {
        scanf("%lf", &r);
        if(B - A < r)
            printf("\n\t\t��� ������ ���� ������ ����� ���������!"
                         "\n\t\t���������: ");
    }
    while(B - A < r);

    printf("\n\t������� ���������� ����������� ����������"
           "\n\n\t\t0 < eps < 1: ");

    do
    {
        scanf("%lf", &eps);
        if(eps >= 1 || eps <= 0) printf("\n\t������� ������������ ��������."
                                    "\n\t���������: ");
    }
    while(eps >= 1 || eps <= 0);

    printf("\n\n\tA=%.2lf, B=%.2lf, r=%.2lf, eps=%.6lf", A, B, r, eps);
    printf("\n\n\t\t\t�������"
           "\n\n\t\t+--------+------------+"
             "\n\t\t|   x    |    F(x)    |"
             "\n\t\t+--------+------------+");

    for(x = A; x <= B + eps; x += r)
    {
        printf("\n\t\t|%8.2lf|%12.4lf|", x, series(x, eps));
        printf("\n\t\t+--------+------------+");
    }

    getch();
    return 0;
}


