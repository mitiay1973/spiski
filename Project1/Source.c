#include <malloc.h>
#include <stdio.h>
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
	for (size_t i = 0; i < n - 1; i++)
	{
		p2 = calloc(1, sizeof(struct list));
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;
	}
	p1->next = NULL;
	return los;
}

void Print(LOS los)
{
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
	printf("\n");
}

LOS Delete_Los(LOS los)
{

	LOS ind = los;
	while (ind)
	{
		ind = los->next;
		
		los = ind;
	}
}

LOS Delete_element(LOS los, int k)
{
	if (k == 1)
	{
		 los=los->next;
		
	}
	else
	{
	for (size_t i = 0; i < k - 2; i++)
	{
		los = los->next;
	}
	LOS p1 = los;
	los->next = los->next->next;
	}
	//free(p1);
}

void Swap_element(LOS los, int a, int m)
{
	LOS min = los;
	LOS max = los;
	LOS _max = los;
	if (a != 1) {
		for (size_t n = -1; n < a ; n++)
		{
			min = min->next;
		}
		for (size_t n = 0; n < m-2; n++)
		{
			_max = _max->next;
		}
		LOS l2 = _max->next;
		max = l2->next;
		LOS l1 = min->next;
		min->next = l2;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return los;
	}
	else {
		for (size_t n = 0; n < m - 2; n++)
		{
			_max = _max->next;
		}
		LOS l2 = _max->next;
		max = l2->next;
		LOS l1 = min->next;
		min->next = los;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return los;
	}
}

LOS Insert_Into_LOS(LOS los, struct list item, int k)
{
	LOS el = malloc(sizeof(struct list));
	el->a = item.a;
	if (k == 1)
	{
		el->next = los;
		los = el;
	}
	else
	{
		for (size_t i = 1; i < k - 1; i++)
		{
			los = los->next;
			if (!(los->next))
			{
				printf("Неверный индекс");
				break;
			}
		}
		void* temp = los->next;
		los->next = el;
		el->next = temp;
	}
	return los;
}

int main()
{
	LOS los = create(10);
	Print(los);
	struct list item = {19,NULL};
	
	los=Insert_Into_LOS(los, item, 1);
	Print(los);
	//Delete_element(los, 1);
	//Print(los);
	Swap_element(los, 1, 5);
	//Delete_element(los, 2);
	Print(los);
	//Print(Delete_element(los, N+1));
	
	//Print(los);
	return 0;
}