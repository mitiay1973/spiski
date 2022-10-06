#include <stdio.h>
#include <malloc.h>
#define N 10
struct list
{
	int a;
	struct list* next;
};
typedef struct list* LOS;
LOS create(int n)
{
	LOS los = calloc(1, sizeof(LOS));
	LOS p1 = los, p2;
	p1->a = 1;
	for (size_t i = 0; i < n-1; i++)
	{
		p2= calloc(1, sizeof(LOS));
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;
	}
	p1->next = NULL;
	return los;
}
void print(LOS los)
{
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
	printf("\n");
}
LOS deliteElement(LOS los, int n)
{
	if (n == 1)
	{	
		los->next = los;
		LOS p1 = los;
		
	}
	else
	{
		for (size_t i = 0; i < n - 2; i++)
		{
			los = los->next;
		}
		LOS p1 = los;
		los->next = los->next->next;
		//free(p1);
	}

}
void InsertElement(LOS los, LOS item, int n)
{
	if (n==1)
	{
		item->next = los;
		los = item;
	}
	else
	{
		for (size_t i = 0; i < n-2; i++)
		{
			los = los->next;
		}
		item->next = los->next;
		los->next = item;
	}
}
LOS deliteAll(LOS los)
{
	int j = N;
	for (size_t b = 0; b < j - 2; b++)
	{
		for (size_t i = 0; i < j - 2; i++)
		{
			los = los->next;
		}
		LOS p1 = los;
		los->next = los->next->next;
		j--;
	}		
}

int main()
{
	//LOS a = malloc(sizeof(LOS));
	//LOS b = malloc(sizeof(LOS));
	LOS los = create(N);
	print(los);
	deliteElement(los, 1);
	print(los);
	LOS item = malloc(sizeof(LOS));
	item->a = 777;
	item->next = NULL;
	InsertElement(los, item, 4);
	print(los);
	//deliteAll(los);
	//print(los);
	return 0;
}
