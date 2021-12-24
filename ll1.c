#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head , int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		*Head = newn;
	}
}

void InsertLast(PPNODE Head, int no)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	
	newn =(PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	
	if(*Head == NULL)
	{
		(*Head) = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
	}
	
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head != NULL)
	{
		*Head = (*Head) -> next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head) -> next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		free(temp -> next);
	}
	temp -> next = NULL;
}

void Display(PNODE Head)
{
	
	while(Head != NULL)
	{
		printf("|%d| -> ",Head -> data);
		Head = Head -> next;
	}
	printf("NULL");
	printf("\n");
}

int Count(PNODE Head)
{	
	int iCnt = 0;
	
	while(Head != NULL)
	{
		iCnt++;
		Head = Head -> next;
	}
	return iCnt;
}
int main()
{
	PNODE first = NULL;
	int iRet = 0;
	
	InsertFirst(&first,101);
	InsertFirst(&first,100);
	
	InsertLast(&first , 20);
	
	Display(first);
	
	DeleteFirst(&first);
	
	Display(first);
	
	DeleteLast(&first);
	
	Display(first);
	
	iRet = Count(first);
	printf("\n%d",iRet);
	
	return 0;
}