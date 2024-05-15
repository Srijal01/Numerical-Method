//Fixed-point iteration
#include<stdio.h>
#include<math.h>
#define EPSILON 0.001
float f(float x)
{
    return x*x*x + x*x - 1;
}
float findValueAt(float x)
{
    return 1/sqrt(1+x);
}
float differentiate(float x)
{
    return -1/2.0 * (pow((1+x),-3/2));
}
int main()
{
    int maxIteration,i;
    float a,b,x,x0;
    printf("Enter maximum number of Iterations:\n");
    scanf("%d",&maxIteration);
    do
    {
        printf("Enter the value of a and b(starting boundary): ");
        scanf("%f%f",&a,&b);
        if(f(a)*f(b) > 0)
        {
            printf("Boundary values are Invalid.\n");
            continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",a,b);
            break;
        }
    } while(1);
    x0 = (a+b)/2; // Compute initial approximation
    if(fabs(differentiate(x0)) < 1)
        printf("Function form is correct. Iteration method can be applied.\n");
    else
    {
        printf("Function form is not correct. Iteration method can't be applied.\n");
        return 0;
    }
    for(i = 1; i <= maxIteration; i++)
    {
        x = findValueAt(x0); // Find the next approximation
        printf("Iterations=%d Root=%f\n", i, x);
        if(fabs(x - x0) < EPSILON || i == maxIteration) // Check termination conditions
        {
            printf("Iterations=%d Final Root=%f\n", i, x);
            break;
        }
        x0 = x; // Update the previous approximation
    }
    return 0;
}
