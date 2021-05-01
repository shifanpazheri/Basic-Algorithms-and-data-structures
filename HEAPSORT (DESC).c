#include <stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void minheapify(int a[],int i,int n)//just change manheapify to minheapify "onlyonly" to make into descending order
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest;
    if(l<n&&a[l]<a[i])
       smallest=l;
    else
       smallest=i;
    if(r<n&&a[r]<a[smallest])//here it a[smallest]<-DONT FORGET THIS
       smallest=r;
    if(smallest!=i)
    {
        swap(&a[i],&a[smallest]);
        minheapify(a,smallest,n);
    }
}

void bulidheap(int a[],int n)
{
    for(int i=n/2;i>=0;i--)
       minheapify(a,i,n);
}

void heapsort(int *a,int n)
{
    int heapsize=n;
    bulidheap(a,n);
    for(int i=n-1;i>=1;i--)// till 1 is enough because last element is the smallest element 
    {
        swap(&a[i],&a[0]);
        heapsize-=1;//new heapsize is reduced by 1 
        minheapify(a,0,heapsize);//index to be maxheapified is "0" 
    }
}

int main()
{
    int a[]={6,2,8,4,5,8,1,2,0,2,33,6,8,7};
    int n=sizeof(a)/sizeof(a[0]);
    heapsort(a,n);
    for(int i=0;i<n;i++)
      printf("%d ",a[i]);
}
