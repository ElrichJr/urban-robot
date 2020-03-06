#include <conio.h>
#include <stdio.h>
#include <math.h>

#define MAX_INT 2147483647

int main()
{
	int k, p, s;
	int check = 1;
	do
	{
		printf_s("Starting capital is: ");
		scanf_s("%i", &k);
		if ((k > 0) && (k < MAX_INT))
		{
			check = 0;
		}
	} while (check);
	check = 1;
	do
	{
		printf_s("Growth percentage: ");
		scanf_s("%i", &p);
		if ((p > 0) && (p < MAX_INT))
		{
			check = 0;
			continue;
		}
		if (p < 1)
		{
			printf_s("This is a very unprofitable business, are you sure? y/n ");
			if (getchar() == 'n')
			{
				check = 0;
			}
		}
	} while (check);
	check = 1;
	do
	{
		printf_s("Shop cost: ");
		scanf_s("%i", &s);
		if ((s > 0) && (s < MAX_INT))
		{
			check = 0;
		}
		if (s < k)
		{
			printf_s("You can already afford the shop, are you sure? y/n ");
			if (getchar() == 'n')
			{
				check = 0;
			}
		}
	} while (check);
	float difference = s / (float)k;
	printf_s("%f", difference);
	int year;
	for (int i = 0; difference > powf((float)p/100 + 1, i); i++)
	{
		year = i+1;
	}
	printf_s("%i", year);
	_getch();
	return 0;
}