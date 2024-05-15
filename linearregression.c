//Linear Regression
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void linear_regression(float x[], float y[], int n, float *slope, float *intercept) 
{
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
	int i;
    for (i = 0; i < n; i++) 
	{
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }
    *slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    *intercept = (sum_y - *slope * sum_x) / n;
}
int main() 
{
    int n, i;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the values of x:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y:\n");
    for (i = 0; i < n; i++) 
	{
        scanf("%f", &y[i]);
    }
    float slope, intercept;
    linear_regression(x, y, n, &slope, &intercept);
    printf("The slope is %f\n", slope);
    printf("The intercept is %f\n", intercept);
    printf("Regression equation: %f x + %f",slope,intercept);
    return 0;
}
