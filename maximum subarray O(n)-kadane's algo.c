//MAXIMUM SUBARRAY PROBLEM-KADANE'S ALGORITHM->O(n)
//REFER mycodeschool->interview questions
#include<stdio.h>
int main()
{
    int a[]={13,-2,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int n=sizeof(a)/sizeof(int);
    int max=0,sum=0;
    for(int i=0;i<n;i++) //O(n)
    {
        sum+=a[i];
     // printf("%d\n",sum); SEE THE ASSIGNMENT OF SUM
        if(sum>max)
           max=sum;
        if(sum<0)//Because of this statement.This code assume atleast 1 positive element in array 
           sum=0; 
    }
    printf("%d",max);
}

