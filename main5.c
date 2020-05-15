#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct item
{
    int digit;
    struct item *next;
    struct item *prev;
} Item;

//Структура, описывающая многоразрядное число
typedef struct number
{
    Item *first;
    Item *last;
    int n;
} Number;

Number CreateNumber(char str[]);
void AddDigit(Number *number, int digit);
void PrintNumber(Number number);

Number SumNumber(Number n1, Number n2);
Number LongMulShort(Number n1, int mult);
Number Ymn(Number n1, Number n2);

int main()
{
    clock_t time;
    time = clock();
    
    char strNumber[10];
    printf("Enter the number: ");
	for (int correct = 0; correct == 0;)
	{
		char ch;
		if (scanf_s("%s", strNumber, sizeof(strNumber)) != 1)
		{
			printf("\nWrong input, try again");
			while ((ch = getchar()) != '\n')
				putchar(ch);
		}
		else
			correct = 1;
	}
    int intNumber = atoi(strNumber);
    Number a = CreateNumber(strNumber);
    Number temp = a;
    Number tempRes = CreateNumber("0");
    int k = intNumber - 1;
    for (int j = intNumber - 2; j > 0; j--) {
        for (int i = k; i > 0; i--) {
            tempRes = SumNumber(tempRes, temp);
            PrintNumber(tempRes);
            if (i == 1)
			{
                k--;
                temp = tempRes;
                tempRes = CreateNumber("0");
            }
        }
        printf("\n");
    }
    printf("Factorial is ");
    PrintNumber(temp);
    return 0;
}

Number SumNumber(Number n1, Number n2)
{
    Number sum = CreateNumber("");
    Item *p1 = n1.first, *p2 = n2.first;
    int digit, pos = 0, s1, s2;
    
    while (p1 || p2)
	{
        if (p1)
		{
            s1 = p1 -> digit;
            p1 = p1 -> next;
        }
		else
		{
			s1 = 0;
		}
        if (p2)
		{
            s2 = p2 -> digit;
            p2 = p2 -> next;
        }
		else
		{
			s2 = 0;
		}
        digit = (s1 + s2 + pos) % 10;
        pos = (s1 + s2 + pos) / 10;
        AddDigit(&sum, digit);
    }
    if (pos)
	{
        AddDigit(&sum, pos);
    }
    return sum;
}

Number LongMulShort(Number number1, int mult)
{
    Number res = CreateNumber("");
    Item *tempRes = number1.first;
    int digit = 0, s = 0, mod = 0, pos = 0;
    
    while (tempRes)
	{
        if (tempRes) 
		{
            s = tempRes -> digit;
            tempRes = tempRes -> next;
        }
        pos = s * mult + mod;
        if (pos > 9) {
            digit = pos % 10;
            AddDigit(&res, digit);
        }
		else
		{
			AddDigit(&res, pos);
		}
        mod = (pos - digit) / 10;
		if (!tempRes)
		{
			AddDigit(&res, mod);
		}
    }
    return res;
}

Number Ymn(Number n1, Number n2)
{
    Number result = CreateNumber("");
    Item *temp1 = n1.first, *temp2 = n2.first;
    int s1 = 0, s2 = 0;
    int digit = 0, pos = 0, mod = 0;
    
    //int digitTemp;
    
    /*printf("fisrt n1 = %i\n", p1 -> digit);
    printf("fisrt n2 = %i\n", p1 -> digit);*/
    
    while (temp1 || temp2)
	{
        if (temp1)
		{
            s1 = temp1 -> digit;
            temp1 = temp1 -> next;
        }
        else
		{
            s1 = 1;
        }
        if (temp2)
		{
            s2 = temp2 -> digit;
            temp2 = temp2 -> next;
        }
        else
		{
            s2 = 1;
        }
        pos = s1 * s2 + mod;
        if (pos > 9) 
		{
            digit = pos % 10;
            AddDigit(&result, digit);
        }
        else
		{
            AddDigit(&result, pos);
        }
        mod = (pos - digit) / 10;
		if (!temp1 || !temp2)
		{
			AddDigit(&result, mod);
		}
        //digit = (s1 * s2 + pos) % 10;
        //digitTemp = s1 * s2;
        //pos = (s1 + s2) / 10;
        
        /*AddDigit(&result, digit);
        
        if (digitTemp > 9) {
            digitTemp /= 10;
            AddDigit(&result, digitTemp);
        }*/
    }
    return result;
}

Number CreateNumber(char str[])
{
    Number number = {NULL, NULL, 0};
    
    for (int i = strlen(str) - 1; i >= 0; i--)
	{
        AddDigit(&number, str[i] - '0');
    }
    return number;
}

void AddDigit(Number *number, int digit)
{
    Item *p = (Item*)malloc(sizeof(Item));
    
    p -> digit = digit;
    p -> next = p -> prev = NULL;
    
    if (number -> first == NULL)
	{
        number -> first = number -> last = p;
    }
    else
	{
        number -> last -> next = p;
        p -> prev = number -> last;
        number -> last = p;
    }
    
    number -> n++;
}

void PrintNumber(Number number)
{   
    Item *p = number.last;
    
    while (p)
	{
        printf_s("%i", p -> digit);
        p = p -> prev;
    }
    printf("\n");
}
