//Cholesky's Algorithm of LU Decomposition
#include <stdio.h>
#include<conio.h>
#include <math.h>
int main()
{
    float a[10][10], l[10][10], u[10][10];
    int i=0, j=0, k=0, n;
	float temp=0;
    printf("Enter the dimension of matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			temp=0;
			if(i==j)
			{
				for(k=0;k<j;k++)
				{
					temp+=((u[k][i])*(u[k][i]));
				}
				u[i][i]=sqrt((a[i][i]-temp));
			}
			else if(j>i)
			{
				for(k=0;k<i;k++)
				{
					temp+=(u[k][i]*u[k][j]);
				}
				u[i][j]=(1/(u[i][i]))*((a[i][j])-temp);
			}
			else
			{
				u[i][j]=0;
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			l[i][j]=u[j][i];
		}
	}
    printf("L Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\t%f",l[i][j]);
		}
		printf("\n");
	}
	printf("U Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("\t%f",u[i][j]);
		}
		printf("\n");
	}
    return 0;
}
