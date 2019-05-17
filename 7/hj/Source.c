#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Word(char *mas_file, int *temp);

void Delete(FILE *file, FILE *file_cpy, int p);

int Word(char *mas_file, int *temp)
{
	int num = 1;
	char loud[7] = "eyuioa";
	int i = 0;
	int sym = 0;

	while (mas_file[i] != '\0')
	{
		for (int j = 0; j < 7; j++)
		{
			if (mas_file[i] == loud[j])
			{

				*temp=++sym;//склади
			}
		}
		if (mas_file[i] == ' ')
		{
			num++;
		}
		i++;
	}
	return num;
}


void Delete(FILE *file, FILE *file_cpy, int t)
{
	char ch;
	int p = 0;		
	int i = 0;

	fseek(file, 0, SEEK_SET);

	while ((ch = fgetc(file)) != EOF)
	{
		if (p < (t - 2))
		{
			if (ch == '.')
			{
				p++;
			}
			fputc((int)ch, file_cpy);
		}
	}
}

int main()
{
	int temp;
	int number = 0;
	char mas_file[100];
	int i = 0;
	int amount_str, amount_w;
	int p = 1;
	char buf[100];
	FILE * file;
	FILE * file_cpy;
	int word = 0;
	int syllable = 0;
	file = fopen("new_file.txt", "r");
	file_cpy = fopen("copy_file.txt", "w");
	if (file != NULL && file_cpy != NULL)
	{
		printf("File succsesful open\n ");
	}
	else
	{
		return 1;
	}

	printf("Input number of sentences - ");
	scanf("%d", &amount_str);

	while ((amount_w = fgetc(file)) != EOF)
	{
		if (amount_w == ' ' || amount_w == '.')
		{
			number++;
		}
		if (amount_w == '.')
		{
			p++;//кількість крапок в тексті 
		}
		if (p == amount_str)
		{
			mas_file[i] = amount_w;
			i++;
		}
		mas_file[i] = '\0';
	}

	printf("Number of words in your sentences are %d\n", Word(mas_file, &temp));
	printf("This is your sentences\n %s\n", mas_file);
	printf("Number of syllables in  word  -  %d\n", temp);
	
	fseek(file, 0, SEEK_SET);

	while (fgets(mas_file, 100, file) != NULL)
	{
		word+=Word(mas_file, &temp);
		syllable += temp;
	}


	printf("Average value of syllables in one word is %.3lf\n\n", (double)syllable/(double)word);

	Delete(file, file_cpy, p); 
	
	printf("Text is copy in copy_file.txt  without 2 last sentences\n");

	int fcloseall(void);
	system("pause");
	return 0;
}