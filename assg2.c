#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	char data;
	struct Node *next;

}Node;
typedef struct Queue
{
	Node *front, *rear;
}Queue;

void init(Queue*);
void insert(Queue*, char);
char Remove(Queue*);
int isempty(Queue);

int main(int argc, char *argv[])
{
	char ch;
	FILE *fp, *fp1, *fp2, *fp3;
	Queue q1, q2, q3;

	init(&q1);
	init(&q2);
	init(&q3);

	fp = fopen(argv[1], "r");
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			break;
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			insert(&q1, ch);
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			insert(&q2, ch);
		}
		else
		{
			insert(&q3, ch);
		}
	}
	fclose(fp);

	fp1 = fopen("d:\\file1.txt", "w");
	fp2 = fopen("d:\\file2.txt", "w");
	fp3 = fopen("d:\\file3.txt", "w");

	while (!isempty(q1))
	{
		ch = Remove(&q1);
		ch = ch + 32;
		fputc(ch, fp1);
	}
	while (!isempty(q2))
	{
		ch = Remove(&q2);
		ch = ch + 32;
		fputc(ch, fp2);
	}
	while (!isempty(q3))
	{
		ch = Remove(&q3);
		fputc(ch, fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}


void init(Queue *q)
{
	q->front = NULL;
	q->rear = NULL;
}
void insert(Queue *q, char ch)
{
	Node *temp = (Node*)malloc(sizeof(Node) * 1);
	temp->data = ch;
	temp->next = NULL;
	if (q->front == NULL && q->rear == NULL)
	{
		q->front = q->rear = temp;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
	}
}
char Remove(Queue *q)
{
	Node *temp;
	char ch;
	if (q->front != q->rear)
	{
		temp = q->front;
		ch = q->front->data;
		q->front = q->front->next;
		free(temp);
	}
	else
	{
		temp = q->front;
		ch = q->front->data;
		q->front = q->rear = NULL;
		free(temp);
	}

	return ch;
}
int isempty(Queue q)
{
	if (q.front == NULL && q.rear == NULL)
		return 1;
	else
		return 0;
}