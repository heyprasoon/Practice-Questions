#include <stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int A[],int n)
{
    int flag;
 for(int i=0;i<n-1;i++)
 {   flag=0;
     for(int j=0;j<n-1-i;j++)
     {
         if(A[j]>A[j+1])
         {
            swap(A[j],A[j+1]);
            flag=1;
         }
     }
     if(flag==0)  // flag=0 means no comparsion done at 1st pass
            break;
 }
}
void insertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)//starting from index 1
    {
        int j=i-1;
        int x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
void selectionSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)//starting from index 1
    {   int j,k;
        for(j=k=i;j<n;j++)
        {
            if(A[k]>A[j])
            {
                k=j;
            }
        }
        swap(A[i],A[k]);
    }
}


int main()
{
     int A[]={5,4,2,9,1};
     int n=sizeof(A)/sizeof(A[0]);
     selectionSort(A,n);
     for(int i=0;i<n;i++)
     {
         cout<<A[i]<<" ";
     }

 return 0;
}
