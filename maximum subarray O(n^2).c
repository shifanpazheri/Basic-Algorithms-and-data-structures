//MAXIMUM SUBARRAY WITH O(n^2) COMPLEXITY 
//CHECK MYCODESCHOOL ->coding interiew section
#include<stdio.h>
int main()
{
    int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int n=sizeof(a)/sizeof(int);
    //printf("%d",n);
    int size,startindex,endindex,from,sum=0,count=0,max=a[0];
           
    for(from=0;from<n;from++)     //O(n)
	{//starting position is constant then varing size
       for(size=1;size<=n;size++)  //O(n)
        {
            if(from+size>n)//This is really important (without this segmentation fault will occur)
            {
                sum=0;
                break;
            }
            sum+=a[from+size-1];//SUM WILL BE ASSIGNED a[0]->a[0]+a[1]->a[0]+a[1]+a[2]->etc........
            //i.e. starting from a given node i am finding the possible sums (by varing size)
            //eg:if my starting node is p then sum values are a[p]->a[p]+a[p+1]->a[p]+a[p+1]->etc.....
            if(sum>max)
                max=sum;
          //printf("%d\n",sum);//USE THIS TO UNDERSTAND ASSIGNMENT OF SUM
        }
            sum=0;
    }
    printf("%d",max);
}
