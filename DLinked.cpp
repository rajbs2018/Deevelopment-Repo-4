#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE , *PNODE , **PPNODE;

class DoublyLL
{
private:
	PNODE first;
	int size;
	
public:
	DoublyLL()
	{
		first = NULL;
		size = 0;
	}
	
	
	
	void InsertFirst(int iNo)
	{
				
		PNODE newn = new NODE;
		
		newn -> data = iNo;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else 
		{
			newn -> next = first ;
			first -> prev = newn;
			first = newn;
			
		}
		size++;
	}
	
	
	void InsertLast(int iNo)
	{
		PNODE temp = first;
		
		PNODE newn = new NODE;
		
		newn -> data = iNo;
		newn -> next = NULL;
		newn -> prev = NULL;
		
		if(temp == NULL)
		{
			temp = newn;
		}
		else
		{
			while(temp -> next != NULL)
			{
				temp = temp -> next;
			}
			temp -> next = newn;
			newn -> prev = temp ;
		}
		size++;
	}
	
	
	
	void DeleteFirst()
	{
		PNODE temp = first ;
		
		if(first == NULL)
		{
			cout<<"Linked list is Empty \n";
			return;
		}
		else
		{
			first = first -> next;
			delete temp;
			first -> prev = NULL;
		}
		size--;
	}
	
	
	
	void DeleteLast()
	{
		PNODE temp = first;
		
		if(size == 0)
		{
			cout<<"Linked list is empty \n";
			return;
		}
		else
		{
			while(temp -> next -> next != NULL)
			{
				temp = temp -> next;
			}
			delete temp -> next; 
			temp -> next = NULL;
		}
		
		size--;
	}
	
	
	
	void Display()
	{
		PNODE temp = first;
		
		if(size == 0)
		{
			cout<<"Linked list is empty \n";
			cout<<"NULL";
		}
		
		while(temp != NULL)
		{
			cout<<temp -> data <<"\t";
			temp = temp -> next;
		}
		cout<<"\n";
	}
	
	
	int Count()
	{
		return size;
	}	
	
	
	
	void InsertAtPos(int iNo, int iPos)
	{
		PNODE temp = first;
		
		int i = 0;
		
		if((iPos < 1) || (iPos > size + 1))
		{
			cout<<"wrong input \n";
			return;
		}
		
		if(iPos == 1)
		{
			InsertFirst(iPos);
		}
		else if(iPos == size + 1)
		{
			InsertLast(iPos);
		}
		else
		{
			PNODE newn = new NODE;
			
			newn -> data = iNo;
			newn -> next = NULL;
			newn -> prev = NULL;
			
			for(i = 1; i < iPos - 1 ; i++)
			{
				temp = temp -> next;
			}
			newn -> next = temp -> next;
			newn -> prev = temp -> next -> prev;
			temp -> next -> prev = newn;
			temp -> next = newn;
			
		}
		size++;
	}
	
	
	
	void DeleteAtPos(int iPos)
	{
		PNODE temp = first;
		PNODE targated =NULL;
		int i = 0;
		
		if(size == 0)
		{
			cout<<"Linked list is empty \n";
			return;
		}
		else if(temp -> next == NULL)
		{
			delete temp -> next;
			temp = NULL;
		}
		else
		{
			for(i = 1 ; i < iPos - 1 ; i++)
			{
				temp =temp -> next;
			}
			targated = temp -> next;
			temp -> next = targated -> next;
			targated -> next -> prev = temp;
			delete targated;
		}
		size--;
	}
};

int main()
{
	DoublyLL obj;
	
	int iValue = 0, iRet = 0, iPos = 0, iChoice = 1;
	
	while(iChoice != 0)
	{
		cout<<"\n-------------------------------------------------------\n";
		cout<<"| 1 : Insert a Node at first position of linked list  |\n";
		cout<<"| 2 : Insert a Node at last position of linked list   |\n";
		cout<<"| 3 : Insert a Node at desired position of linked list|\n";
		cout<<"| 4 : Delete a first Node from linked list            |\n";
		cout<<"| 5 : Delete a last Node from linked list             |\n";
		cout<<"| 6 : Delete a Node at desired position               |\n";
		cout<<"| 7 : Display a linked list                           |\n";
		cout<<"| 8 : Count of linked list                            |\n";
		cout<<"| 0 : Exit from linked list                           |\n";
		cout<<"-------------------------------------------------------\n";

		
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
			cout<<"Insert a node at first position in linked list \n";
			cin>>iValue;
			obj.InsertFirst(iValue);
			cout<<"Inserted a node succesfully \n";
			break;
			
			case 2:
			cout<<"Insert a node at last position in linked list \n";
			cin>>iValue;
			obj.InsertLast(iValue);
			cout<<"Inserted a node succesfully \n";
			break;
			
			case 3:
			cout<<"Enter a number to add in linked list \n";
			cin>>iValue;
			cout<<"Enter a desired position to add a node in linked list \n";
			cin>>iPos;
			obj.InsertAtPos(iValue,iPos);
			cout<<"Inserted a node at desired position \n";
			break;
			
			case 4:
			cout<<"Deleted a first node from linked list \n";
			obj.DeleteFirst();
			break;
			
			case 5:
			cout<<"Deleted a last node from linked list \n";
			obj.DeleteLast();
			break;
			
			case 6:
			cout<<"Enter a desired position to delete a node from linked list \n";
			cin>>iPos;
			obj.DeleteAtPos(iPos);
			break;
			
			case 7:
			cout<<"Displyed Linked list \n";
			obj.Display();
			break;
			
			case 8:
			iRet = obj.Count();
			cout<<"Count of linked list \n"<<iRet;
			break;
			
			default:
			cout<<"Enter a number in range of 0 to 8 \n";
			break;
			
		}
	}
	return 0;
}