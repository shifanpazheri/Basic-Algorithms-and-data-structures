#include <stdio.h>
void merge(int a[],int p,int q,int r);//TO AVOID WARNING
void mergesort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void merge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1],i,j,max=a[p];
    for(i=0;i<n1;i++)
    {
        L[i]=a[p+i];
        if(L[i]>max)
        max=L[i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[q+1+j];
        if(R[j]>max)
        max=R[j];
    }
    //printf("max=%d\n",max);
    L[n1]=max+1;
    R[n2]=max+1;
    i=0;
    j=0;
    for(int k=p;k<=r;k++)
    {
        //printf("%d %d",L[i],R[j]);
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        //printf(" %d\n",a[k]);
    }
    return;
}
int main()
{
    int a[]={6,2,8,4,5,8,1,2,0,2,33,6,8,7};
    int n=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);
   for(int i=0;i<n;i++)
   printf("%d ",a[i]);
}

