//
//  ex1.cpp
//  exercise1
//
//  Created by charlesfuture on 14-7-5.
//
//

#include "ex1.h"
#include <iostream>
using namespace std;

int main()
{
	//cout<<"hello world!";
	int iArray[10] = {4, 2, 6, 7, 3, 1, 5, 8, 0, 9};
	
	int iLength = sizeof(iArray) / sizeof(int);
	
	cout<<"原始数组：";
	for(int i=0; i<iLength; i++)
	{
		cout<<iArray[i]<<" ";
	}
	cout<<"\n";
	
	//冒泡排序
	for(int i=0; i<iLength-2; i++)
	{
		for(int j=iLength-1; j<i+1; j--)
		{
			if(iArray[j] < iArray[j-1])
			{
				int iTemp = iArray[j];
				iArray[j] = iArray[j-1];
				iArray[j-1] = iTemp;
			}
		}
	}
	cout<<"冒泡排序：";
	for(int i=0; i<iLength; i++)
	{
		cout<<iArray[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}