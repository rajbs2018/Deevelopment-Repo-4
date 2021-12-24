#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE ,*PNODE ,**PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn ->next = *Head;
		(*Head) -> prev = newn;
		
		*Head= newn;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	
	if(*Head != NULL)
	{
		*Head =(*Head) -> next;
		free(temp);
	}
	
}

void DeleteLast(PPNODE Head)
{
	PNODE temp =*Head;
	
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)-> next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	
	while(temp -> next -> next != NULL)
	{
		temp = temp -> next;
		
	}
	free(temp -> next);
	temp -> next = NULL;
	
}

void InsertLast(PPNODE Head,int no)
{
	PNODE newn = NULL;
	PNODE temp =*Head;
	
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next; 
		}
		
		temp -> next = newn;
		newn -> prev = temp;
	}
}
void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d| ->",Head -> data);
		Head = Head -> next;
	}
	printf("NULL\n");
	
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

void InsertAtPos(PPNODE Head , int no , int ipos)
{
	int size = 0 , i = 0;
	PNODE temp = *Head;
	PNODE newn = NULL;

	size = Count(*Head);
	
	if(((ipos) < 1) || (((ipos) > size + 1)))
	{
		printf("Invalide choice");
		return;
	}		
	else if(ipos == 1)
	{
		InsertFirst(Head,no);
	}
	else if(ipos == size + 1)
	{
		InsertLast(Head , no);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn -> data = no;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		for(i = 1 ; i < ipos -1 ; i++)
		{
			temp = temp -> next;
		}
		
		newn -> next = temp -> next;
		newn -> prev = temp -> next -> prev;
		temp -> next = newn;
		
	}
	
	
}

void DeleteAtPos(PPNODE Head , int iPos )
{
	int size = 0;
	PNODE temp = *Head;
	PNODE targated = NULL;
	int i = 0;
	
	size = Count(*Head);
	
	if((iPos < 1)||(iPos > size))	//Filter for invalis position
	{
		printf("Invalid position\n");
		return;
	}
	
	if(iPos == 1)	//First position
	{
		DeleteFirst(Head);
	}
	else if(iPos == size + 1)	//Last Position
	{
		DeleteLast(Head);
	}
	else	//In between position
	{
		for(i = 1; i < iPos - 1  ; i++)
		{
			temp = temp -> next;
		}
		targated = temp -> next;
		temp -> next = targated -> next;
		targated -> next -> prev = targated -> prev;
		free(targated);
	}
}



int main()
{
	PNODE first = NULL;
	int iChoice = 1 , value = 0, iRet = 0 , pos = 0;
	
	while(iChoice != 0)
	{
		printf("\n_________________________________________________________________\n");
		printf("Enter the desired operation that you want to perform on LinkedList\n");
		printf("1 : Insert the node at first position\n");
		printf("2 : Insert the node at last position\n");
		printf("3 : Insert the node at desired position\n");
		printf("4 : Delete the first node\n");
		printf("5 : Delete the last node\n");
		printf("6 : Delete the node at desired position\n");
		printf("7 : Display thr containts of List\n");
		printf("8 : Count the number of nodes from linked list\n");
		printf("0 : Terminate the application\n");
		printf("\n_________________________________________________________________\n");
		
		scanf("%d",&iChoice);
		
		switch(iChoice)
		{
			case 1:
			printf("Enter the data to insert\n");
			scanf("%d",&value);
			InsertFirst(&first,value);
			break;
			
			case 2:
			printf("Enter the data to insert\n");
			scanf("%d",&value);
			InsertLast(&first,value);
			break;
			
			case 3:
			printf("Enter the data to insert\n");
			scanf("%d",&value);
			printf("Enter the position\n");
			scanf("%d",&pos);
			InsertAtPos(&first,value,pos);
			break;
			
			case 4:
			DeleteFirst(&first);
			break;
			
			case 5:
			DeleteLast(&first);
			break;
			
			case 6:
			printf("Enter the position\n");
			scanf("%d",&pos);
			DeleteAtPos(&first,pos);
			break;
			
			case 7 :
			printf("Element  of Linked Lis\n");
			Display(first);
			break;
			
			
			case 8:
			iRet = Count(first);
			printf("Number of elements are : %d\n", iRet);
			break;
			
			
			case 0:
			printf("Thanks for using Marellous Linked List\n");
			break;
			
			default :
			printf("Please enter Proper choice\n");
			break;
			
		}
	}
	return 0 ;
}