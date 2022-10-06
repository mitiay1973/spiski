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
	LOS los = calloc(1, sizeof(struct list));
	LOS p1 = los, p2;
	p1->a = 1;
	for (size_t i = 0; i < n-1; i++)
	{
		p2= calloc(1, sizeof(struct list));
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

		for (size_t i = -2; i < n; i++)
		{
			los = los->next;
		}
		LOS p1 = los;
		los->next = los->next->next;

}
LOS zamena(LOS los, int a, int b)
{
	LOS gol = los;
	LOS p1=0;
	LOS p2;
	los = gol;
	for (int i = -2; i < b-4; i++)
	{
		los = los->next;
		if (i == a)
		{
			p1 = los;
		}
	}
	p2 = los;
	los= p1;
	los = gol;
	for (int i = -2; i < a-4; i++)
	{
		los = los->next;
	}
	los = p2;
	return los;
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
	LOS ind = los;
	while (ind)
	{
		ind = los->next;
		free(los);
		los = ind;
	}

}

int main()
{
	//LOS a = malloc(sizeof(LOS));
	//LOS b = malloc(sizeof(LOS));
	LOS los = create(N);
	LOS s = los;
	print(los);
	los = s;
	deliteElement(los, 1);
	print(los);
	los = s;
	
	print(zamena(los, 2, 5));
	/*LOS item = malloc(sizeof(struct list));
	item->a = 777;
	item->next = NULL;
	InsertElement(los, item, 4);
	print(los);*/
	deliteAll(los);
	return 0;
}
