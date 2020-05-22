#include <stdio.h>
#include <string.h>


void insert(char where[80], char what, int place)
{
	for (int i = 78; i > place; i--)
	{
		where[i] = where[i - 1];
	}
	where[place] = what;
}

void main()
{
	char str[80];
	printf_s("Please enter the line:\n");
	gets(str);
	int end = 0;
	int spacesIn=0;
	while (end < 79)
	{
		if (str[end] == '\0')
		{
			break;
		}
		end++;
		if (str[end] == ' ')
		{
			spacesIn++;
		}
	}
	printf_s("There are %i spaces\n", spacesIn);
	printf_s("End is on %i\n", end);
	if(end==79)
	{
		str[79] = '\0';
	}
	int spaces = 79-end;
	if (spacesIn == 0)
	{
		for (int i = 0; i < spaces / 2; i++)
		{
			insert(str, ' ', 0);
		}
		puts(str);
		return;
	}
	int spacesPer = spaces / spacesIn;
	spaces = spaces - spacesPer * spacesIn;
	for (int i = 0; i < 80; i++)
	{
		if (str[i] == ' ')
		{
			for (int j = spacesPer; j > 0; j--)
			{
				insert(str, ' ', i);
			}
			if (spaces > 0)
			{
				insert(str, ' ', i);
				i++;
				spaces--;
			}
			puts(str);
			i = i + spacesPer;
		}
	}
	printf_s("Final result\n");
	puts(str);
	system("pause");
}