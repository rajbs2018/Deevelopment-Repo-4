#include<iostream>
using namespace std;

template<typename T>
class LinearSearch
{
	
	private:
	T Arr[5];
	int iLength;
	T no;
	
	public:
	bool Search(T Arr[],int iLength,T no);
};

template<class T>
bool LinearSearch<T>::Search(T Arr[],int iLength, T no)
{
	int i= 0;
	for(i = 0; i< iLength;i++)
	{
		if(Arr[i] == no)
		{
			break;
		}
	}
	if(i == iLength)
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
	LinearSearch <int>iLSobj;

	int iValue = 0;
	int Irr[5] = {50,40,30,20,10};	
	
	cout<<"Enter Integer to search :"<<"\n";
	cin>>iValue;
	
	bool iret = iLSobj.Search(Irr,5,iValue);;
	if(iret == true)
	{
		cout<<"Element is there"<<"\n";
	}
	else
	{
		cout<<"Element is not there"<<"\n";
	}
	
	
	LinearSearch <float>fLSobj;
	
	float Frr[5] = {50.5,40.5,30.5,20.5,10.5};	
	float fValue = 0.0;
	
	cout<<"Enter Integer to search :"<<"\n";
	cin>>fValue;
	
	bool fret = fLSobj.Search(Frr,5,fValue);;
	if(fret == true)
	{
		cout<<"Element is there"<<"\n";
	}
	else
	{
		cout<<"Element is not there"<<"\n";
	}
	
	
	
	LinearSearch <char>cLSobj;

	char Crr[5] = {'A','B','C','D','E'};	
	char cValue = '\0';
	
	cout<<"Enter Integer to search :"<<"\n";
	cin>>cValue;
	
	bool cret = cLSobj.Search(Crr,5,cValue);;
	if(cret == true)
	{
		cout<<"Element is there"<<"\n";
	}
	else
	{
		cout<<"Element is not there"<<"\n";
	}
	
	return 0;
	
} 