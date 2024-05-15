//Bisection Method
#include<stdio.h>
float findvalue(float x) 
{
    return x*x*x - x - 4;
}
float bisect(float x1, float x2) 
{
    return (x1 + x2) / 2;
}
int main() 
{
    int maxIteration, i = 0; // Initialize i to 0 to count iterations accurately
    float x1, x2, x;
    printf("Enter maximum number of iterations:\n");
    scanf("%d", &maxIteration);
    printf("Enter the value of x1 and x2 (starting boundary): ");
    scanf("%f %f", &x1, &x2);
    if (findvalue(x1) * findvalue(x2) > 0) 
	{
        printf("Roots are Invalid.\n");
        return 1; // Exit program indicating error
    }
    printf("Roots lie between %f and %f\n", x1, x2);
    // Find root
    while (i < maxIteration) 
	{
        x = bisect(x1, x2); // find the mid point
        if (findvalue(x) * findvalue(x1) < 0)
            x2 = x; // x2 is shifted
        else if (findvalue(x) * findvalue(x2) < 0)
            x1 = x; // x1 is shifted
        printf("Iteration=%d Root=%f\n", i + 1, x);
        i++;
    }
    printf("Root=%f Total Iterations=%d\n", x, i);
    return 0;
}

