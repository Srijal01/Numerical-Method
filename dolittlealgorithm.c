//Dolittle Algorithm of LU Decomposition
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main() 
{
    int n, i, j, k;
    float sum=0, a[5][5], u[5][5], l[5][5];
    printf("Enter Dimension Matrix:\n");
    scanf("%d",&n);
    printf("Enter Elements of the matrix:\n");
    for(i = 0; i < n; i++) 
	{
        for(j = 0; j < n; j++) 
		{
            scanf("%f", &a[i][j]);
        }
    }
    for(j = 0; j < n; j++) 
	{
        u[0][j] = a[0][j];
    }
    for(i = 0; i < n; i++) 
	{
        l[i][i] = 1;
    }
    for(i = 1; i < n; i++) 
	{
        l[i][0] = a[i][0] / u[0][0];
    }
    for(j = 1; j < n; j++) 
	{
        for(i = 1; i < j; i++) 
		{
            for(k = 0; k <= i - 1; k++) 
			{
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - sum;
            sum = 0;
        }
        for(i = j; i < n; i++) 
		{
            for(k = 0; k <= j - 1; k++) 
			{
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - sum;
            sum = 0;
        }
    }
    printf("L Matrix:\n");
    for(i = 0; i < n; i++) 
	{
        for(j = 0; j < n; j++) 
		{
            printf("\t%f", l[i][j]);
        }
        printf("\n");
    }
    printf("U Matrix:\n");
    for(i = 0; i < n; i++) 
	{
        for(j = 0; j < n; j++) 
		{
            printf("\t%f", u[i][j]);
        }
        printf("\n");
    }
    return 0;
}
