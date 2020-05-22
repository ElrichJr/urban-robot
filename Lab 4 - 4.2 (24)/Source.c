#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void Letters(char *destination, char *input)
{
	strcpy(destination, input);

	for (int i = 0; i < strlen(destination); i++)
	{
		if (destination[i] == '\n')
		{
			destination[i] = destination[i + 1];
		}
		destination[i] = tolower(destination[i]);
	}

	for (int i = 1; i < strlen(destination); i++)
	{
		char temp = destination[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (destination[j] == temp)
			{
				for (int k = j; k < strlen(destination); k++)
				{
					destination[k] = destination[k + 1];
				}
				i--;
			}

			if (destination[j] > temp)
			{
				destination[j + 1] = destination[j];
				destination[j] = temp;
			}
		}
	}
}

void main()
{
	char word[80];
	for (int correct = 0; correct == 0;)
	{
		printf("Enter your word: ");
		gets(word);
		correct = 1;
		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] == ' ')
			{
				printf("\nThis isn't a single word, try again");
				correct = 0;
				break;
			}
		}
	}
	FILE *dict = NULL;
	fopen_s(&dict, "Dictionary.txt", "r");
	if (dict == NULL)
	{
		printf("Can't open the dictionary, closing the program");
		return;
	}
	char *wordLetters = (char*)malloc(sizeof(word));
	Letters(wordLetters, word);
	int notfound = 1;
	printf("Words with same letters as %s\n", word);
	while (!feof(dict))
	{
		char dictWord[80];
		fgets(dictWord, 79, dict);
		char *dictLetters = malloc(sizeof(dictWord));
		Letters(dictLetters, dictWord);
		if (!strcmp(wordLetters, dictLetters))
		{
			printf("%s", dictWord);
			notfound = 0;
		}
	}
	if (notfound)
	{
		printf("Not found\n");
	}
	if (fclose(dict))
	{
		printf("Soething went wrong while closing the file");
	}
	return;
}