#include<iostream>
using namespace std;

template<typename T>
class ISorting
{
	private:
	T Arr[5];
	
	public:
	void InsertionSort(T Arr[]);
};

template<class T>
void ISorting<T>::InsertionSort(T Arr[])
{
	 T key = 0;
	int i = 0, j = 0;
		int size = 5;
		
		for(i = 1; i < size ; i++)
		{
			key = Arr[i];
			for(j = i-1; (j>=0)&&(Arr[j] > key);j--)
			{
				Arr[j+1] = Arr[j];
			}
			Arr[j+1] = key;
		}
}

int main()
{
	ISorting <int>iSSobj;
	
	int  i = 0;
	int Irr[5] = {11,9,2,56,15};
	
	iSSobj.InsertionSort(Irr);
	
	for(i = 0 ; i < 5 ; i++)
	{
		cout<<Irr[i]<<"\t";
	}
	cout<<"\n";
	
	
	Sorting <float>fSSobj;

	float Frr[5] = {11.5,9.5,2.,56.5,15.5};
	
	fSSobj.InsertionSort(Frr);
	
	for(i = 0 ; i < 5 ; i++)
	{
		cout<<Frr[i]<<"\t";
	}
	cout<<"\n";
	
	
	Sorting <char>cSSobj;
	
	char Crr[5] = {'E','C','D','B','A'};
	
	cSSobj.InsertionSort(Crr);
	
	for(i = 0 ; i < 5 ; i++)
	{
		cout<<Crr[i]<<"\t";
	}
	return 0;
}