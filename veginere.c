#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
	{
		printf ("WRONG, try again\n");
		return 1;
	}
	int i, n;// n - длина введ. параметра, i - считатель
	i = 0;
	n = strlen(argv[1]);
	char kod[n];//массив введ. параметра
	int kodnumb[n];
	int alfup = 0; //счетчик алфавита
	int alflo = 0;
	int alfkod = 0;
	int numbkod = 0;
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char lower[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char str[1000];	//массив для вводимого предложения
	while (i < n)
	{
		if ((isdigit(argv[1][i])) || (ispunct(argv[1][i])))
		{
			printf ("WRONG, try again\n");
			return 1;			
		}
		else
		{
			kod[i] = argv[1][i];
			i++;
		}
	}
	int strn=0;//индексы массива & счётчик введённых символов
	char c; //вводимые символы;
	while ((c = getchar()) != '\n')
	{
		str[strn] = c;
		strn++;
	}
	char shifr[strn];
	int shif = 0;// индекс зашифрованого предложения
	int nn = 0;//индекс кода
	while (nn < n)
	{
		if (kod[nn] == lower[alfkod])
		{
			kodnumb[numbkod] = alfkod;
			nn++;
			alfkod = 0;
			numbkod++;
		}
		else
		{
			alfkod++;
		}
	}
	numbkod = 0;
	int q;
	while (shif < strn)
	{
		if (ispunct(str[shif]))
		{
			shifr[shif] = str[shif];
			shif++;
		}
		else if (isspace(str[shif]))
		{
			shifr[shif] = str[shif];
			shif++;
		}
		else if (isupper(str[shif]))
		{
			while (str[shif] != upper[alfup])
			{
				alfup++;
			}
			q = alfup + kodnumb[numbkod];
			shifr[shif] = upper[q];
			shif++;
			numbkod++;
			alfup = 0;
			if (numbkod == n)
			{ 
				numbkod = 0;
			}
		}
		else 
		{
			while (str[shif] != lower[alflo])
			{
				alflo++;
			}
			q = alflo + kodnumb[numbkod];
			shifr[shif] = lower[q];
			numbkod++;
			shif++;
			alflo=0;
			if (numbkod == n)
			{ 
				numbkod = 0;
			}
		}
	}
	int temp = 0;
	for(;temp < shif;temp++) printf("%c", shifr[temp]);
	printf("\n");
	return 0;
}

