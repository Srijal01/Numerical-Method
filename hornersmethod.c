//Horner's method
#include <stdio.h>
double horner(double coeffs[], int size, double x) 
{
	int i;
    double result = 0;
    for (i = size - 1; i >= 0; i--) 
	{
        result = result * x + coeffs[i];
    }
    return result;
}
int main() 
{
    double coeffs[] = {-19, 7, -4, 6};
    double x = 3;
    printf("Result: %f\n", horner(coeffs, 4, x));
    return 0;
}
