#include <math.h>
#include <stdio.h>
#include <conio.h>

float secondpart(float a, int b)
{
	float out = 1;
	while (b >= 1)
	{
		printf("\nTop part is a=%f", a);
		printf("\nFactorializing b=%i", b);
		out = out * a / b;
		printf("\nCurrent output out=%f", out);
		b--;
	}
	return(out);
}

float recoursin(float x, int n)
{
	float result = 0;
	while (n > 0)
	{

		printf("\nOk, so n=%i", n);
		int power = 2 * n - 1;
		printf("\nOk, so power=%i", power);
		result = result + powf(-1, n - 1)*secondpart(x, power);
		printf("\nOk, so result=%f", result);
		n--;
	}
	return (result);
}


void main()
{
	int n=0;
	float x=0, a1, a2;
	printf("Angle x=");
	scanf_s("%f", &x);
	printf("n in recoursive function is: ");
	scanf_s("%i", &n);
	printf("n in recoursive function is: %i",n);
	a1 = sin(x);
	a2 = recoursin(x,n);
	printf("\n\nsin x=%f", a1);
	printf("\nrecourse function of x is %f", a2);
	_getch();
}