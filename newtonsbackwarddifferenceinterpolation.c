//Newton's Backward Difference Interpolation
#include <stdio.h>
void newton_backward(float x[], float y[], int n, float value, float *result) 
{
    float prod = 1;
    *result = y[n - 1];
	int i, j;
    for (i = 1; i < n; i++) 
	{
        for (j = 0; j < i; j++) 
		{
            x[j] = x[j + 1] - x[j];
        }
        prod = 1;
        for (j = 0; j < i; j++) 
		{
            prod *= (value - x[j]);
        }
        *result = y[n - 1] + prod * y[n - 1 - i];
    }
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
    float value;
    printf("Enter the value of f\n");
    scanf("%f", &value);
    float result;
    newton_backward(x, y, n, value, &result);
    printf("Value at %0.4f is %0.4f\n", value, result);
    return 0;
}
