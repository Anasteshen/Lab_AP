
/*
The beginning of the revolution in England
01.02.1640
Proclamation of the republic in Englan
13.03.1649
Establishment in England of a parliamentary monarchy
19.12.1688
Restoration of the monarchy in England
11.12.1660
The war for the independence of the English colonies in North America
01.01.1775
Declaration of Independence
01.01.1776
Adoption of the US Constitution
11.12.1787

Establishment of the United States
 01.03.1776
*/
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

 int Sotr(EVENT* events, int n);

int main()
{
	int n;
	printf("Input number of events - ");
	scanf("%d", &n);

	EVENT *events = (EVENT*)malloc(sizeof(EVENT)*n);

	for (int i = 0; i < n; i++)
	{
		printf("name of event: ");
		scanf("%s", &events[i].name);

		printf("date of event(dd.mm.yyyy): ");
		scanf("%d.%d.%d", &(events[i].date.day), &(events[i].date.month), &(events[i].date.year));//12.11.2000
	}
	
	EVENT* newMemory = events;
	newMemory = (EVENT*)realloc(newMemory, sizeof(EVENT)*(n+1));
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
	}

	printf("___________\n");
	Sotr(events, n);

	for (int i = 0; i <= n; i++)
	{
		if (events[i].date.day > 9 && events[i].date.month < 10)
		{
			printf("%d.0%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}

		if (events[i].date.day < 10  && events[i].date.month > 9)
		{
			printf("0%d.%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}
		if (events[i].date.day < 10 && events[i].date.month < 10)
		{
			printf("0%d.0%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
		}
		else 
		printf("%d.%d.%d  -  %s \n", events[i].date.day, events[i].date.month, events[i].date.year, events[i].name);
	}
	free(events);
	system("pause");
	return 0;
}

int Sotr(EVENT *events, int n)
{
	int neventdate;
	int eventdate;
	EVENT temp;
	neventdate = events[n].date.day + 30*events[n].date.month+365*events[n].date.year;
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

