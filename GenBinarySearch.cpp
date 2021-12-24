#include<iostream>
using namespace std;

template<typename T>
class Searching
{
	private:
	T Arr[5];
	T no;
	
	public:
	bool BinarySearch(T Arr[],T no);
	
};

template<class T>
bool Searching<T>::BinarySearch(T Arr[],T no)
	{
		int start,end,mid;
		
		start = 0;
		end = 5 - 1;
		mid = (start + end) / 2;
		
		while(start <= end)
		{
			if(Arr[mid] == no)
			{
				break;
			}
			else if(no > Arr[mid])
			{
				start = mid + 1;
			}
			else if(no < Arr[mid])
			{
				end =  mid - 1;
			}
			mid = (start + end) / 2;
		}
		if(Arr[mid] == no)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


int main()
{
	Searching <int>iBSobj;
	int iValue = 0;
	
	int Irr[5] = {10,20,30,40,50};
	
	cout<<"Enter the element to search"<<"\n";
	cin>>iValue;
	
	
	bool iret = iBSobj.BinarySearch(Irr,iValue);
	
		if(iret == true)
		{
			cout<<"Element is there"<<"\n";
		}
		else
		{
			cout<<"Element is not there"<<"\n";
		}
		
	
	Searching <float>fBSobj;
	float fValue = 0;
	
	float Frr[5] = {10.5,20.5,30.5,40.5,50.5};
	
	cout<<"Enter the element to search"<<"\n";
	cin>>fValue;
	
	
	bool fret = fBSobj.BinarySearch(Frr,fValue);
	
		if(fret == true)
		{
			cout<<"Element is there"<<"\n";
		}
		else
		{
			cout<<"Element is not there"<<"\n";
		}
		
		
	Searching <char>cBSobj;
	char cValue = '\0';
	
	char Crr[5] = {'A','B','C','D','E'};
	
	cout<<"Enter the element to search"<<"\n";
	cin>>cValue;
	
	
	bool cret = cBSobj.BinarySearch(Crr,cValue);
	
		if(cret == true)
		{
			cout<<"Element is there"<<"\n";
		}
		else
		{
			cout<<"Element is not there"<<"\n";
		}	
}


