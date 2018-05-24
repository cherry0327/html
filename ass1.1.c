#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
typedef struct Customer
{
	int consumer_number;
	int bill_month;
	char consumer_name[20];
	int units_consumed;
	struct Customer *next;
}Customer;

Customer *head;
void AddRecord();
void Sort();
void Display();
void DisplayTop3();
void SearchOnBillMonth();
void Save();

int main()
{
	AddRecord();
	AddRecord();
	AddRecord();
	AddRecord();
	Display();
	Sort();
	printf("\n\n");
	Display();
	printf("\nTop 3 customers are:\n");
	DisplayTop3();
	printf("Consumer belonging to perticular month\n");
    SearchOnBillMonth();
	Save();
	return 0;
}
void AddRecord()
{
	Customer *trav = head;
	Customer *temp = (Customer*)malloc(sizeof(Customer) * 1);
	printf("Enter consumer number:\n");
	scanf("%d", &temp->consumer_number);
	printf("Enter consumer name:\n");
	scanf("%s", &temp->consumer_name);
	printf("Enter bill month:\n");
	scanf("%d", &temp->bill_month);
	printf("Enter units consumed:\n");
	scanf("%d", &temp->units_consumed);
	temp->next = NULL;
	
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		trav = head;
			while (trav->next != NULL)
			{
				trav = trav->next;
			}
		trav->next = temp;
	}
	n++;
}
void Display()
{
	Customer *trav = head;
	while (trav != NULL)
	{
		printf("%d\t%s\t%d\t%d\n", trav->consumer_number, trav->consumer_name, trav->bill_month, trav->units_consumed);
		trav = trav->next;
	}
}

void Save()
{
	Customer temp, *trav;
	FILE *fp = fopen("d:\\consumer.dat", "wb");
		trav = head;
	while (trav != NULL)
	{
		temp = *trav;
		fwrite(&temp, sizeof(temp), 1, fp);
		trav = trav->next;
	}
	fclose(fp);
}
void SearchOnBillMonth()
{
	int month;
	Customer *trav = head;
	printf("Enter month for search\n");
	scanf("%d", &month);
	while (trav != NULL)
	{
		if (trav->bill_month == month)
		{
			printf("%d\t%s\t%d\t%d\n", trav->consumer_number, trav->consumer_name, trav->bill_month, trav->units_consumed);
			
		}
		trav = trav->next;
	}
}
void DisplayTop3()
{
	int i = 0;
	Customer *trav = head;
	while (i < 3)
	{
		printf("%d\t%s\t%d\t%d\n", trav->consumer_number, trav->consumer_name, trav->bill_month, trav->units_consumed);
		trav = trav->next;
		i++;
	}
}

void Sort()
{
	int i, j;
	Customer temp, *first, *second;
	first = head;
	for (i = 0; i < n - 1; i++)
	{
		second = first->next;
		for (j = i + 1; j < n; j++)
		{
			if (first->units_consumed<second->units_consumed)
			{
				temp.consumer_number = first->consumer_number;
				strcpy(temp.consumer_name, first->consumer_name);
				temp.bill_month = first->bill_month;
				temp.units_consumed = first->units_consumed;

				first->consumer_number = second->consumer_number;
				strcpy(first->consumer_name, second->consumer_name);
				first->bill_month = second->bill_month;
				first->units_consumed = second->units_consumed;

				second->consumer_number = temp.consumer_number;
				strcpy(second->consumer_name, temp.consumer_name);
				second->bill_month = temp.bill_month;
				second->units_consumed = temp.units_consumed;

			}
			second = second->next;
		}
		first = first->next;
	}
}