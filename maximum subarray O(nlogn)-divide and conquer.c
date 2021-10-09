//MAXIMUM SUBARRAY WITH DIVIDE AND CONQUER APPROACH O(nlogn) COMPLEXITY 
//CHECK MYCODESCHOOL ->coding interiew section
#include <stdio.h>

int crosssum(int a[],int p,int mid,int q)
{
    int maxleft=a[p];//assigning sentinel value
    int sum=0,i;
    for(i=mid;i>=p;i--)//it is important to start from mid
    {
        sum+=a[i];
        if(sum>maxleft)
            maxleft=sum;
    }
    int maxright=a[mid+1];//assigning sentinel value
    sum=0;
    for(i=mid+1;i<=q;i++)//it is important to start from mid
    {
        sum+=a[i];
        if(sum>maxright)
            maxright=sum;
    }
    return maxleft+maxright;
}

int maxsubarray(int a[],int p,int q)
{
    if(p==q)
        return a[p];
    int mid=(p+q)/2;//else is not needed
    int l=maxsubarray(a,p,mid);
    int r=maxsubarray(a,mid+1,q);
    int c=crosssum(a,p,mid,q);
    if(l>=r&&l>=c)//greater than or equal to is important
        return l;
    else if(r>=l&&r>=c)//greater than or equal to is important
        return r;
    else
        return c;
}

int main()
{
    int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int n=sizeof(a)/sizeof(int);
    printf("%d",maxsubarray(a,0,n-1));
}

