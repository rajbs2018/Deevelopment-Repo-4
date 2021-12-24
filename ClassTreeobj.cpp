#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
}NODE , *PNODE, **PPNODE;

class Tree
{
private:
		PNODE first;
		
public:
	Tree();
	void Insert(int);
	bool Search(int);
};

Tree::Tree()
	{
		first = NULL;
	}
		
		
void Tree::Insert(int no)
	{
		PNODE temp = first;
		PNODE newn = new NODE;
		
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
					cout<<"Dplicate node\n";
					
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

bool Tree::Search(int no)
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
	Tree obj;
	int no = 0;
	bool bret = false;
	
	PNODE first = NULL;
	
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
