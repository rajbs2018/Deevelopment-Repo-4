#include<iostream>
using namespace std;

template<typename T>
class Sorting
{
	private:
	T Arr[5];
	
	public:
	void SelectionSort(T Arr[]);
};

template<class T>
void Sorting<T>::SelectionSort(T Arr[])
{
	T temp = 0;
	int i = 0, j =0 , minindex = 0;
		int size = 5;
		for(i = 0; i< size;i++)
		{
			minindex = i;
			for(j = i; j < size ; j++)
			{
				if(Arr[minindex] > Arr[j])
				{
					minindex = j;
				}
			}
			temp = Arr[i];
			Arr[i] = Arr[minindex];
			Arr[minindex] = temp;
		}
}

int main()
{
	Sorting <int>iSSobj;
	
	int  i = 0;
	int Irr[5] = {11,9,2,56,15};
	
	iSSobj.SelectionSort(Irr);
	
	for(i = 0 ; i < 5 ; i++)
	{
		cout<<Irr[i]<<"\t";
	}
	cout<<"\n";
	
	
	Sorting <float>fSSobj;

	float Frr[5] = {11.5,9.5,2.,56.5,15.5};
	
	fSSobj.SelectionSort(Frr);
	
	for(i = 0 ; i < 5 ; i++)
	{
		cout<<Frr[i]<<"\t";
	}
	cout<<"\n";
	
	
	Sorting <char>cSSobj;
	
	char Crr[5] = {'E','C','D','B','A'};
	
	cSSobj.SelectionSort(Crr);
	
	for(i = 0 ; i < 5 ; i++)
	{
		cout<<Crr[i]<<"\t";
	}
	return 0;
}