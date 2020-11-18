#include <math.h>

double series(double x, double eps)
{
    double a = -(1 / x * x), k = 1, sum = a, x = x * x, p = pow(-1, k), q = pow(-1, k + 1);
    printf("\n\n\ta=%.2lf, k=%.2lf, sum=%.2lf, eps=%.6lf", a, k - 1, sum, eps);

    while(fabs(a)>eps)
    {
        a = a * (q * x) / (4 * k * k * p + 2 * k * p);
        sum = sum + a;
        k = k + 1;
        printf("\n\ta=%.2lf, abs(a)=%.10lf  k=%.2lf, sum=%.2lf, eps=%.6lf", a, fabs(a), k - 1, sum, eps);
    }

    printf("\n\n\teps=%.6lf, sum=%.8lf", eps, sum);

    return sum;
}
