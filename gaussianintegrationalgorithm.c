//Gaussian Integration Algorithm
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (x)*(x)*(x)+1
int main()
{
	float a,b,z1,z2,c1,c2,x1,x2,v;
	printf("Enter Lower and Upper Limit:\n");
	scanf("%f%f",&a,&b);
	c1=c2=1;
	z1=-0.57735,z2=0.57735;
	x1=(b-a)/2*z1+(b+a)/2;
	x2=(b-a)/2*z2+(b+a)/2;
	v=(b-a)/2*((f(x1))+(f(x2)));
	printf("\nValue of Integration: %f\n",v);
	return 0;
}
