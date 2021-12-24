//Header File
#include<stdio.h>

//Function Declaration
void Display(int);

// Entry point function
int main()
{
	int iValue = 0;
	int iRet = 0;
	printf("Enter Number\n");
	scanf("%d",&iValue);
	Display(iValue);   // Function call
	iRet=iSum;
	printf("Sum of the Digits");
	return 0;
}

// Function defination
void Display(int iNo)
{
	// Local variables
	int iDigit = 0;
	int iSum = 0;
	
	while(iNo > 0)
	{
	iDigit = iNo % 10;
	iSum=iSum+iDigit;
	iNo = iNo / 10;          //752
	}
	
}