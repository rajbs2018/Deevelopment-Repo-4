#include<iostream>
using namespace std;

template<typename T>
struct node
{
	int data;
	struct node *next;
};

template<class T>
class Stack	//Singly linear linked list
{
private:
	node<T>*first;
	int size;
public:
	Stack();
	void push(T);
	int pop();
	void Display();
	int Count();
		
};
template<class T>
Stack<T>::Stack()
	{
		first =NULL;
		size = 0;
	}
		
template<class T>		
void Stack<T>::push(T no)	//InsertFirst()
	{
		node<T>*newn = new node<T>;
			
		newn -> data = no;
		newn -> next = NULL;
			
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
		    newn -> next = first;
			first = newn;
		}
		size++;
	}

template<class T>		
int Stack<T>::pop()	//DeleteFirst()
	{
		int no = 0;
		node<T>*temp = first;
		if(first == NULL)
		{
			cout<<"Stack is empty\n";
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
void Stack<T>::Display()
	{
		node<T>*temp = first;
		while(temp != NULL)
		{
			cout<<"|"<<temp-> data<<"|"<<"\n";
			temp = temp -> next;
		}
	}
	
template<class T>
int Stack<T>::Count()
	{
		return size;
	}

int main()
{
	Stack <int>obj;
	
	obj.push(11);
	obj.push(21);
	obj.push(51);
	obj.push(101);
	
	cout<<"Elements from stack : \n";
	obj.Display();
	
	int iret = obj.pop();
	cout<<"Poped elelmens is :"<<iret<<"\n";
	
	cout<<"Elemens from stack : \n";
	obj.Display();	// 51 21 11
	
	iret = obj.Count();
	cout<<"Size of stack : "<<iret<<"\n";
	
	
}