//Runge-Kutta Method
#include <stdio.h>
#include <conio.h>
#include <math.h>
float func(float x, float y)
{
    float f;
    f = 2.0 * y / x;
    ;
    return f;
}
int main()
{
    int i, n;
    float x0, y0, xp, h, m1, m2, m3, m4;
    printf("Enter initial value of x and y:");
    scanf("%f %f", &x0, &y0);
    printf("Enter x at which y is required:");
    scanf("%f", &xp);
    printf("Enter stepsize,h: ");
    scanf("%f", &h);
    n = (xp - x0) / h;
    for (i = 1; i <= n; i++)
    {
        m1 = func(x0, y0);
        m2 = func(x0 + 0.5 * h, y0 + 0.5 * m1 * h);
        m3 = func(x0 + 0.5 * h, y0 + 0.5 * m2 * h);
        m4 = func(x0 + h, y0 + m3 * h);
        x0 = x0 + h;
        y0 = y0 + (m1 + 2 * m2 + 2 * m3 + m4) * h / 6;
        printf("%f\t%f\n", x0, y0);
    }
    printf("\nValue of y at x=%f is %f", x0, y0);
    return 0;
}
