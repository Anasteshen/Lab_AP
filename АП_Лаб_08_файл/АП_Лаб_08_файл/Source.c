#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct date_event
{
	int day;
	int month;
	int year;
}DateEvent;

typedef struct event
{
	struct date_event date;
	char name[100];

}EVENT;

void Sotr(EVENT* events, int n);

int main()
{
	int n = 1;
	int i = 0;
	int ch;
	FILE *file;
	file = fopen("new_file.txt", "r");

	if (file != NULL)
	{
		printf("File succsesful open\n ");
	}
	else
	{
		return 1;
	}

	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
		{
			n++;
		}
	}

	fseek(file, 0, SEEK_SET);

	EVENT * events = (EVENT*)malloc(sizeof(EVENT)*n);

	for (int i = 0; i < n; i++)
	{
		fscanf(file, "%d.%d.%d", &events[i].date.day, &events[i].date.month, &events[i].date.year);
		fgets(events[i].name, 200, file);
	//	printf("%d.%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
	}
	//for (int i = 0; i <= n; i++)
	//{
	//	i++;
	//	//printf("%d.%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
	//}
	EVENT* newMemory = events;
	newMemory = (EVENT*)realloc(newMemory, sizeof(EVENT)*(n + 1));
	if (newMemory == NULL)
	{
		puts("Error^ not enough memory");
		return 1;
	}
	events = newMemory;


	printf("Add another one  event: \n");
	printf("name of event: ");
	scanf("%s", &events[n].name);
	printf("date of event(dd.mm.yyyy): ");
	scanf("%d.%d.%d", &(events[n].date.day), &(events[n].date.month), &(events[n].date.year));//12.11.2000
/*
	for (int i = 0; i <= n; i++)
	{
		if (events[i].date.day > 9 && events[i].date.month < 10)
		{
			printf("%d.0%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}

		if (events[i].date.day < 10 && events[i].date.month > 9)
		{
			printf("0%d.%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}
		if (events[i].date.day < 10 && events[i].date.month < 10)
		{
			printf("0%d.0%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}
		else
			printf("%d.%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
	}*/

	printf("___________\n");
	Sotr(events, n);

	for (int i = 0; i <= n; i++)
	{
		if (events[i].date.day > 9 && events[i].date.month < 10)
		{
			printf("%d.0%d.%d  -  %s\n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}

		if (events[i].date.day < 10 && events[i].date.month > 9)
		{
			printf("0%d.%d.%d  -  %s\n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}
		if (events[i].date.day < 10 && events[i].date.month < 10)
		{
			printf("0%d.0%d.%d  -  %s\n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}
		else
			printf("%d.%d.%d  -  %s\n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
	}
	free(events);
	system("pause");
	return 0;
}

void Sotr(EVENT *events, int n)
{
	int neventdate;
	int eventdate;
	EVENT temp;
	neventdate = events[n].date.day + 30 * events[n].date.month + 365 * events[n].date.year;
	for (int i = 0; i < n; i++)
	{
		eventdate = events[i].date.day + 30 * events[i].date.month + 365 * events[i].date.year;
		if (neventdate < eventdate)
		{
			temp = events[i];
			events[i] = events[n];
			events[n] = temp;
		}
	}
}
