//Newton's Divided Difference Interpolation
#include <stdio.h>
int main() 
{
    int n, i, j;
    float v = 0, p, xv, x[10], fx[10], a[10];
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the value of x: ");
    scanf("%f", &xv);
    printf("Enter the value of x and f(x) at i=%d:\n", 0);
    scanf("%f%f", &x[0], &fx[0]);
    for (i = 1; i < n; i++) 
	{
        printf("Enter the value of x and f(x) at i=%d:\n", i);
        scanf("%f%f", &x[i], &fx[i]);
        for (j = n - 1; j > i; j--) 
		{
            fx[j] = (fx[j] - fx[j - 1]) / (x[j] - x[j - 1]);
        }
    }
    for (i = 0; i < n; i++) 
	{
        a[i] = fx[i];
    }
    v = a[0];
    for (i = 1; i < n; i++) 
	{
        p = 1;
        for (j = 0; j < i; j++) 
		{
            p = p * (xv - x[j]);
        }
        v = v + a[i] * p;
    }
    printf("Interpolation value = %.2f\n", v);
    return 0;
}
