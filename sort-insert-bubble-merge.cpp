//
//  main.cpp
//  ex2
//
//  Created by Charles on 14-7-5.
//  Copyright (c) 2014年 Charles. All rights reserved.
//

#include <iostream>
using namespace std;

void Exchange(int &a, int &b)
{
    int iTemp = a;
    a = b;
    b = iTemp;
}
//冒泡排序  bFlag 1：升序 0：降序
void BubbleSort(int* pArray, int iLength, bool bFlag)
{
    for(int i=0; i<=iLength-2; i++)
	{
		for(int j=iLength-1; j>=i+1; j--)
		{
            if (true == bFlag)  //升序
            {
                if(pArray[j] < pArray[j-1])
                {
                    Exchange(pArray[j], pArray[j-1]);
                }
            }
            else    //降序
            {
                if(pArray[j] > pArray[j-1])
                {
                    Exchange(pArray[j], pArray[j-1]);
                }
            }
		}
	}
}
//插入排序
void InsertSort(int* pArray, int iLength)
{
    for(int i=1; i<=iLength-1; i++)
    {
        int iKey = pArray[i];
        int j = i - 1;
        
        while (j>=0 && pArray[j]>iKey)
        {
            pArray[j+1] = pArray[j];
            j--;
        }
        
        pArray[j+1] = iKey;
    }
}
//归并排序——合并子数组
void MergeSubArray(int* pArray, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1+1];
    int* R = new int[n2+1];

    L[n1] = -1e8;
    R[n2] = -1e8;

    for(int i=0; i<n1; i++)
    {
        L[i] = pArray[p + i];
    }
    for(int j=0; j<n2; j++)
    {
        R[j] = pArray[q + j + 1];
    }
    
    int i = 0, j = 0;
    for (int k=p; k<=r; k++)
    {
        if (L[i] >= R[j])
        {
            pArray[k] = L[i++];
        }
        else
        {
            pArray[k] = R[j++];
        }
    }
    
    delete[] L;
    delete[] R;
    L = NULL;
    R = NULL;
}
//归并排序
void MergeSort(int* pArray, int p, int r)
{
    int q = 0;
    if(p < r)
    {
        q = (p + r) / 2;
        MergeSort(pArray, p, q);
        MergeSort(pArray, q+1, r);
        MergeSubArray(pArray, p, q, r);
    }
}
int main(int argc, const char * argv[])
{
    int iArray[15] = {4, 2, 6, 7, 3, 5, 8, 0, 9, 10, 11, 23, 34, 17, 13};
	int iLength = sizeof(iArray) / sizeof(int);
	
	cout<<"原始数组：";
	for(int i=0; i<iLength; i++)
	{
		cout<<iArray[i]<<" ";
	}
	cout<<"\n";
	
	//冒泡排序
    BubbleSort(iArray, iLength, 0);
    cout<<"冒泡排序：";
	for(int i=0; i<iLength; i++)
	{
		cout<<iArray[i]<<" ";
	}
	cout<<"\n";
    
    //插入排序
    InsertSort(iArray, iLength);
    cout<<"插入排序：";
	for(int i=0; i<iLength; i++)
	{
		cout<<iArray[i]<<" ";
	}
	cout<<"\n";
    
    //归并排序
    MergeSort(iArray, 0, iLength-1);
    cout<<"归并排序：";
    for(int i=0; i<iLength; i++)
	{
		cout<<iArray[i]<<" ";
	}
	cout<<"\n";
    
	return 0;
}

