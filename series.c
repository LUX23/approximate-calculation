#include <math.h>

double series(double x, double eps) // x - аргумент функции
                                    // eps - доп. погрешность
{
    double a= -(1 / x * x), k = 1, sum = a; // a - значение первого слагаемого ряда Тейлора
                                            // k - индекс эл-та
                                            // sum - тек. сумма
    x = x * x;

    while(fabs(a)>eps)
    {
        a = a * (pow(-1, k + 1) * x) / (4 * k * k * pow(-1, k) + 2 * k * pow(-1, k)); // рекуррентная последовательность слагаемых заданного ряда
        sum = sum + a;
        k = k + 1;
    }

    return sum;
}
