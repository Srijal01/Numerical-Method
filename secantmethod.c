//Secant method
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 0.0001	// to find answer till 4 correct decimal places
float findValueAt(float x) 
{
    return x * x * x - 5 * x + 1;
}
float findX(float x1, float x2) 
{
    float fx1 = findValueAt(x1);
    float fx2 = findValueAt(x2);
    if (fabs(fx2 - fx1) < EPSILON) 
	{
        printf("Error: Division by zero or too close. Exiting.");
        exit(1);
    }
    return (x1 * fx2 - x2 * fx1) / (fx2 - fx1);
}
int main() 
{
    int maxIteration, i = 1;
    float x1, x2, x;
    printf("Enter the value of x1 and x2:\n");
    scanf("%f %f", &x1, &x2);
    printf("Enter maximum number of iterations:\n");
    scanf("%d", &maxIteration);
    x = findX(x1, x2);
    do 
	{
        x1 = x2;
        x2 = x;
        printf("Iterations=%d Root=%f\n", i, x);
        x = findX(x1, x2);    
        if (fabs(x - x2) < EPSILON) 
		{
            printf("Final Root=%f Total Iterations=%d", x, i + 1);
            return 0;
        }
        i++;
    } while (i <= maxIteration);
    printf("Final Root=%f", x);
    return 0;
}
