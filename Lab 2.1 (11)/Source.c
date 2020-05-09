#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
//#include <complex.h>

void input(double *x, double *y)
{
	printf("If a complex number is a+bi, then\na=");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if (scanf_s("%lf", x) != 1)
		{
			printf("\nWrong input, try again");
			while ((ch = getchar()) != '\n')
				putchar(ch);
		}
		else
			correct = 1;
	}
	printf("b=");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if (scanf_s("%lf", y) != 1)
		{
			printf("\nWrong input, try again");
			while ((ch = getchar()) != '\n')
				putchar(ch);
		}
		else
			correct = 1;
	}
}

void output(double x, double y)
{
	if (y < 0) printf("\nAlgebraic form is %f%f*i", x, y);
	else printf("\nAlgebraic form is %f+%f*i", x, y);
}

void badoutput(double x, double y)
{
	double z = sqrt(x*x + y * y);
	double phi = atan(y / x) - M_PI;
	printf("\nLinear form is %f*e^%f", z, phi);
}

void colsomething(double x, double y)
{
	if (y < 0) 
		printf("\nAlgebraic form is %f%f*i", x, y);
	else 
		printf("\nAlgebraic form is %f+%f*i", x, y);
	badoutput(x, y);
}

void powerof(double x, double y)
{
	int n;
	printf("\nn=");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if (scanf_s("%d", &n) != 1)
		{
			printf("\nWrong input, try again");
			while ((ch = getchar()) != '\n')
				putchar(ch);
		}
		else
			correct = 1;
	}
	double z = pow(sqrt(x*x + y * y), n);
	double phi = atan(y / x);
	double cos_n_phi = z * cos(n*phi), sin_n_phi = z * sin( n*phi);
	if (sin_n_phi < 0) printf("\n%f%f*i", cos_n_phi, sin_n_phi);
	else printf("\n%f+%f*i", cos_n_phi, sin_n_phi);

}

int main()
{
	int x;
	double a = 0, b = 0;
	int exit = 0;
	do
	{
		printf("\n");
		printf("\n|============Main Menu===========|");
		printf("\n| What would you like to do?     |");
		printf("\n| 1 - Enter a complex number     |");
		printf("\n| 2 - Display its linear form    |");
		printf("\n| 3 - Display its algebraic form |");
		printf("\n| 4 - Find its colloquial        |");
		printf("\n| 5 - Find its power of some n   |");
		printf("\n| 6 - Author                     |");
		printf("\n| 7 - Exit                       |");
		printf("\n|================================|");
		printf("\n");
		for (int correct = 0; correct == 0;)
		{
			char ch;
			if (scanf_s("%d", &x) != 1)
			{
				printf("\nWrong input, try again");
				while ((ch = getchar()) != '\n')
					putchar(ch);
			}
			else
				correct = 1;
		}
		switch (x)
		{
		case 1: input(&a, &b); break;
		case 2: badoutput(a, b); break;
		case 3: output(a, b); break;
		case 4: colsomething(a, -b); break;
		case 5: powerof(a, b); break;
		case 6: printf("\nHello there!"); break;
		case 7: exit = 1; break;
		default: printf("Wrong input");
		}
	} while (!exit);
}