#include<iostream>
using namespace std;

	
template<typename T>
class Sorting
{
	
	private:
	T Arr[5];
	int iLength;
	
	public:
	void BubbleSort(T Arr[],int);
};

template<class T>
void Sorting<T>::BubbleSort(T Arr[],int iLength)
	{
		int i = 0, j = 0;
		T temp = 0;
		
		for(i =0 ; i < iLength ; i++)
		{
			for(j = 0; j < iLength - i - 1; j++)
			{
				if(Arr[j]>Arr[j+1])
				{
					temp = Arr[j];
					Arr[j] = Arr[j + 1];
					Arr[j+1] = temp;
				}
				
			}
		}
	}
	
int main()
	{
	
		Sorting <int>iBobj;
		
		cout<<"Output of BubbleSort"<<"\n\n";
		
		int i = 0;
		int Irr[5] = {50,40,30,20,10}; 
		
		iBobj.BubbleSort(Irr,5);
		
		cout<<"Data After Sorting : \n";
		for(i = 0 ; i < 5 ; i++)
		{
			cout<<Irr[i]<<"\t";
		}
		
		
		Sorting <float>fBobj;
		
		i = 0;
		float Frr[5] = {50.5,40.5,30.5,20.5,10.5}; 
		
		fBobj.BubbleSort(Frr,5);
		
		cout<<"Data After Sorting : \n";
		for(i = 0 ; i < 5 ; i++)
		{
			cout<<Frr[i]<<"\t";
		}
		
		
		Sorting <char>cBobj;
		
		i = 0;
		char Crr[5] = {'E','D','C','B','A'}; 
		
		cBobj.BubbleSort(Crr,5);
		
		cout<<"Data After Sorting : \n";
		for(i = 0 ; i < 5 ; i++)
		{
			cout<<Crr[i]<<"\t";
		}
	
	}