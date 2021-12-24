#include<iostream>
using namespace std;

template<typename T>
struct node
{
	int data;
	struct node *next;
};

template<class T>
class Queue	//Singly linear linked list
{
private:
	node<T>*first;
	int size;
	
public:
	Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count();
	
};

template<class T>
Queue<T>::Queue()
	{
		first =NULL;
		size = 0;
	}

template<class T>		
void Queue<T>::Enqueue(T no)	//InsertLast()
	{
		node<T>*newn = new node<T>;
		newn-> next = NULL;
		newn -> data = no;
			
		if(size == 0)
		{
		first = newn;
		}
		else 
		{
			node<T>*temp = first;
			while(temp -> next != NULL)
			{
				temp =temp -> next;
			}
				temp -> next = newn;
			}
			size++;
		}

template<class T>		
int Queue<T>::Dequeue()	//DeleteFirst()
	{
		int no = 0;
		node<T>*temp = first;
		if(first == NULL)
		{
			cout<<"Queue is empty\n";
			return -1;
		}
		if(size == 1)
		{
			first = first -> next;
			delete first;
			first = NULL;
		}
		else
		{
			no = first -> data;
			first = first -> next;
			delete temp;
		}
		size--;
			
		return no;
	}
		
template<class T>		
void Queue<T>::Display()
	{
		node<T>*temp = first;
		for(int i = 1; i<= size ; i++,temp = temp -> next)
		{
			cout<<"|"<<temp -> data<< "|->";
		}
	cout<<"\n";
				
	}
	
template<class T>	
int Queue<T>::Count()
	{
		return size;
	}

int main()
{
	Queue <int>obj;
	int iRet = 0;
	
	obj.Enqueue(11);
	obj.Enqueue(21);
	obj.Enqueue(51);
	obj.Enqueue(101);
	
	cout<<"Elemets of Queue : \n";
	
	obj.Display();
	int iret = obj.Dequeue();
	cout<<"Removed element from queue : "<<iret<<"\n";
	
	obj.Display();	// 51 21 11
	
	iRet = obj.Count();
	cout<<"Size of stack : "<<iret<<"\n";
	
	
}