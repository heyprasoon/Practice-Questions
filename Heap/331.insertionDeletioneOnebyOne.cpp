#include<iostream>
using namespace std;
int Delete(int *A,int n)
{
    int val=A[0];   //we can delete only root value, which is in A[0]
    A[0]=A[n];
    A[n]=val;
    int i=0;
    int j=2*i+1;

    while(j<n-1)
    {
        if(A[j+1] > A[j])  //checking left node with right node
            j=j+1;
        if(A[i]<A[j])  //compare with parent node
        {
            swap(A[i],A[j]);
            i=j;
            j=2*i+1; //left child of next parent
            }
        else
            break;
    }
return val;
}
void insert(int *A,int n)
{
    int i=n;
    int temp=A[i];
    while(i>0 && temp>A[(i-1)/2])  //TEMP IS COMPARED WITH PARENT ALL THE TIME
    {
        A[i]=A[(i-1)/2];
        i=(i-1)/2;
    }
    A[i]=temp;
}
void createHeap(int *A,int n)
{
    for(int i=1;i<n;i++)  //we started from second element,
    {
        insert(A,i);
    }
}
int main()
{
    int A[]={14,14,5,20,3,8,40};
    int n=sizeof(A)/sizeof(A[0]);
    createHeap(A,n);
    for( int i=n-1;i>0;i--)
    Delete(A,i);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    return 0;
}
