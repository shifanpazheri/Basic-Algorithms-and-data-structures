//MAXIMUM SUBARRAY WITH O(n^3) COMPLEXITY
//CHECK MYCODESCHOOL ->coding interiew section
#include<stdio.h>
int main()
{
    int a[]={13,-2,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int n=sizeof(a)/sizeof(int);
   //printf("%d",n);
    int size,startindex,endindex,from,sum=0,count=0,max=a[0];
    for(size=1;size<=n;size++)  //O(n)
    {// size is constant then varing starting position
        for(from=0;from<n;from++)  //O(n)
        {
            if(from+size>n)//This is really important (without this segmentation fault will occur)
            {
                sum=0;
                break;
            }
            for(int i=from;count<size;i++)   //O(n)
            {
                count++;  // COUNT IS USED TO ENSURE i VARIES SIZE(eg:if size=3 and i=4 then i=4,5,6 are the values of i inside loop->sum=a[4]+a[5]+a[6])  
                sum+=a[i];
            }
            if(sum>max)
                max=sum;
            sum=0;
            count=0;
        }
        
    }
    printf("%d",max);
}
