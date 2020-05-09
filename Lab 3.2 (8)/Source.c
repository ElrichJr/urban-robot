#include <stdio.h>
#include <conio.h>



void main()
{
	int n;
	printf_s("\nWidth of the grid ");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if ((scanf_s("%i", &n) == 1) && (n > 0))
			correct = 1;
		if ((ch=getchar()) != '\n')
			correct = 0;
		if((correct == 0) && (n > 0))
			while (getchar() != '\n');
		if (correct==0)
			printf("\nWrong input, try again");
	}
	int **arr = (int **)malloc(n * sizeof(int*));
	int m;
	printf_s("\nHeight of the grid ");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if ((scanf_s("%i", &m) == 1) && (m > 0))
			correct = 1;
		if ((ch = getchar()) != '\n')
		{
			correct = 0;
		}
		if (correct == 0)
			printf("\nWrong input, try again");
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(m * sizeof(int));
	}
	int l, k;
	printf_s("Coordinates increase leftwards and downwards");
	printf_s("\nStarting point is (0;0)");
	printf_s("\nHorizontal coordinates of the point: ");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if (scanf_s("%i", &l) == 1)
			correct = 1;
		if ((ch = getchar()) != '\n')
		{
			correct = 0;
		}
		else
			correct = correct * 1;
		if (correct == 0)
			printf("\nWrong input, try again");
	}
	printf_s("Vertical coordinates of the point: ");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if (scanf_s("%i", &k) == 1)
			correct = 1;
		if ((ch = getchar()) != '\n')
		{
			correct = 0;
		}
		else
			correct = correct * 1;
		if (correct == 0)
			printf("\nWrong input, try again");
	}
	int maxsize = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int resx = abs(i - k) + 1;
			maxsize = (maxsize < resx / 10) ? resx / 10 : maxsize;
			int resy = abs(j - l) + 1;
			maxsize = (maxsize < resy / 10) ? resy / 10 : maxsize;
			arr[i][j] = (resx > resy) ? resx : resy;
		}
	}
	printf_s("\nMatrix result");
	for (int i = 0; i < n; i++)
	{
		printf_s("\n");
		for (int j = 0; j < m; j++)
		{
			printf_s("%i", arr[i][j]);
			int z = -1;
			while (z < maxsize-arr[i][j]/10)
			{
				printf_s(" ");
				z++;
			}
		}
	}
	_getch();
}