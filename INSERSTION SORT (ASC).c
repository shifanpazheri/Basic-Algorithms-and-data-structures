#include <stdio.h>

int main()
{
    int a[]={6,2,8,4,5,8,1,2,0,2,33,6,8,7};
    int n=sizeof(a)/sizeof(a[0]);
    int i,j,key;
    for(j=1;j<n;j++)//CHECK ENTIRE ELEMENTS FROM j=1 to nth ELEMENTS-> in psuedo j=2 to a.length 
    {
        key=a[j];
        i=j-1;
        while(i>=0&&a[i]>key)// never replace key with a[j](since its value changes after for loop execution)
       //don't forget to consider i=0 condition
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;// never replace key with a[j](since its value changes after for loop execution) 
    }
    
    
    for(int i=0;i<n;i++)
      printf("%d ",a[i]);
}
