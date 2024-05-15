//Non-linear Regression with Exponential Model
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n, i;
	float a=0, b=0, r, x[10], y[10], sx=0, slgy=0, sxy=0, sx2=0;
	printf("Enter the number of points:\n");
	scanf("%d",&n);
	printf("Enter the value of x and fx:\n");
	for(i=0; i<n; i++)
	{
		scanf("%f%f",&x[i],&y[i]);
	}
	for(i=0; i<n; i++)
	{
		sx=sx+x[i];
		slgy=slgy+log(y[i]);
		sxy=sxy+x[i]*log(y[i]);
		sx2=sx2+x[i]*x[i];
	}
	b=((n*sxy)-(sx*slgy))/((n*sx2)-(sx*sx));
	r=(slgy/n)-(b*sx/n);
	a=exp(r);
	printf("Fitted curve is: y=%fe^%fx",a,b);
	return 0;
}