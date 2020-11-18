#include <math.h>

double series(double x, double eps)
{
    double a= -(1 / x * x), k = 1, sum = a;
    x = x * x;
    while(fabs(a)>eps)
    {
        a = a*(pow(-1, k + 1) * x) / (4 * k * k * pow(-1, k) + 2 * k * pow(-1, k));
        sum = sum+a;
        k = k+1;
    }
    return sum + eps;
}
