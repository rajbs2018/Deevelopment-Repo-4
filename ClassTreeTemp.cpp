#include<iostream>
using namespace std;

template<typename T>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};

template<class T>
class Tree
{
private:
	 node<T>*first;
	 int size;
		
public:
	Tree();
	void Insert(T);
	bool Search(T);
};

template<class T>
Tree<T>::Tree()
	{
		first = 0;
		int size = 0;
	}
		
		
template<class T>		
void Tree<T>::Insert(T no)
	{
		node<T>* temp = first;
		node<T>* newn = new node<T>;
		
		newn -> data = no;
		newn -> lchild = NULL;
		newn -> rchild = NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			while(1)		//Unconditional loop  for(;;) ,while(true),while(1)
			{
				if(temp -> data == no)
				{
					cout<<"Duplicate node\n";
					
					delete newn;
					break;
				}
				else if(no < (temp -> data))  // lahan data
				{
					if(temp -> lchild == NULL)
					{
						temp -> lchild = newn;
						break;
					}
					temp = temp -> lchild;
				}
				else if( no > (temp -> data))	// mota data
				{
					if(temp -> rchild == NULL)
					{
						temp -> rchild = newn;
						break;
					}
					temp = temp -> rchild;
				}
			}
		}
	}

template<class T>
bool Tree<T>::Search(T no)
	{
		if(first == NULL)		// tree is empty
		{
			return false;
		}
		else 					// tree contain atleast one node
		{
			while(first != NULL)
			{
				if(first -> data == no)  //node sapadla
				{
					break;
				}
				else if(no > (first -> data))
				{
					first = first -> rchild;
				}
				else if(no < (first -> data))
				{
					first = first -> lchild;
				}
			}
		}

			if(first == NULL)
			{
				return false;
			}
			else
			{
				return true;
			}
	}

int main()
{
	Tree <int>obj;
	int no = 0;
	bool bret = false;
	
	obj.Insert(51);
	obj.Insert(21);
	obj.Insert(101);
	
	cout<<"Enter number to search \n";
	cin>>no;
	
	bret = obj.Search(no);
	if(bret == true)
	{
		cout<<"Data is there\n";
	}
	else
	{
		cout<<"Data is not there \n";
	}
	
	
	return 0;
}


/*
Output Of Program

E:\LB_17\Project>g++ Program247.cpp -o Myexe

E:\LB_17\Project>Myexe
Enter number to search
21
Data is there

E:\LB_17\Project>Myexe
Enter number to search
51
Data is there

E:\LB_17\Project>Myexe
Enter number to search
101
Data is there

E:\LB_17\Project>Myexe
Enter number to search
10
Data is not there
*/
