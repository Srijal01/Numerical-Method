//Two Point Forward Difference Formula
#include <stdio.h>
#include <math.h>
double two_point_forward_difference(double f(double), double x, double h) 
{
    return (f(x + h) - f(x)) / h;
}
int main() 
{
    double (*func)(double);
    func = sin;
    double x, h;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the value of h: ");
    scanf("%lf", &h);
    double approx_derivative = two_point_forward_difference(func, x, h);
    printf("Approximate derivative at x = %lf is %lf\n", x, approx_derivative);
    return 0;
}
