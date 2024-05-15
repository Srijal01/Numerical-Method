//regression chap 2
//C program to fit a straight line on given points
#include<stdio.h>
int main() 
{
    int n, i, j;
    float sum1 = 0, sum2 = 0, sum3 = 0, a, b;
    // Input
    printf("Enter number of observations:\n");
    scanf("%d", &n);
    float x[n], y[n], augmented_matrix[2][3];
    printf("Enter value of x:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);
    printf("Enter values of y:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i]);
    // Computations
    for (i = 0; i < n; i++) 
	{
        sum1 += x[i];
        sum2 += y[i];
        sum3 += x[i] * y[i];
    }
    augmented_matrix[0][0] = n;
    augmented_matrix[0][1] = sum1;    
    augmented_matrix[0][2] = sum2;
    augmented_matrix[1][0] = sum1;
    augmented_matrix[1][1] = sum1;
    augmented_matrix[1][2] = sum3;
    float ratio = augmented_matrix[1][0] / augmented_matrix[0][0];
    for (i = 0; i < 3; i++)
        augmented_matrix[1][i] = augmented_matrix[1][i] - ratio * augmented_matrix[0][i];
    // Printing the Upper triangular matrix
    printf("\nThe Upper Triangular Matrix:\n");
    for (i = 0; i < 2; i++) 
	{
        for (j = 0; j < 3; j++)
            printf("%.2f ", augmented_matrix[i][j]);
        printf("\n");
    }
    // Finding a and b by back substitution (a = intercept, b = slope)
    b = augmented_matrix[1][2] / augmented_matrix[1][1];
    a = (augmented_matrix[0][2] - augmented_matrix[0][1] * b) / augmented_matrix[0][0];
    printf("\nIntercept=%.2f and slope=%.2f\n\n", a, b);
    printf("The equation of the line: y = %.2f + %.2fx\n", a, b);
    return 0;
}
