//IMPLEMENTING USING MAX-HEAP
#include <stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

struct priorityqueue 
{
    int a[100];
    int heapsize;
    int capacity;// use if needed
};

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return 2*i+1;
}

int right(int i)
{
    return 2*i+2;
}

void maxheapify(int a[],int i,int n)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest;
    if(l<n&&a[l]>a[i])
       largest=l;
    else
       largest=i;
    if(r<n&&a[r]>a[largest])//here it a[largest]<-DONT FORGET THIS
       largest=r;
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        maxheapify(a,largest,n);
    }
}

void heapincreasekey(struct priorityqueue* p,int i,int key)
{
    if(key<p->a[i])//This code will only work if key is greater( since we swap with parent int the while loop) 
    {
        printf("NEW KEY IS SMALLER\n");
        return;
    }
    p->a[i]=key;
    while(i>0&&p->a[parent(i)]<p->a[i])//we use i>0-since parent of index "i=1" is "0" and we can stop checking their
    {
        swap(&p->a[i],&p->a[parent(i)]);
        i=parent(i);
    }
}

void maxheapinsert(struct priorityqueue *p,int key)//accepting struct priorityqueue * since we need to change heapsize
{
    //printf("%d\n",p->heapsize);
    p->heapsize+=1;
    p->a[p->heapsize-1]=-65321;//assign sentinal value to last index
    heapincreasekey(p,p->heapsize-1,key);//here p is a struct priorityqueue *
}

int heapmax(struct priorityqueue p)
{
    if(p.heapsize>1)
    return p.a[0];//maximum value at "index 0"
    return -999;
}

int heapextractmax(struct priorityqueue *p)//if change only for array then no need of calling by reference but here we change heapsize also
{
    if(p->heapsize<1)
    { 
        printf("Heap Underflow");
        return-999;
    }
    int max=p->a[0];//maximum value at "index 0"
    p->a[0]=p->a[p->heapsize-1];//maximum value is assigned to last index
    p->heapsize-=1;
    maxheapify(p->a,0,p->heapsize);//we are passing array to maxheapify
    return max;
}

int main()
{
    struct priorityqueue p;
    p.heapsize=0;
  //  p.capacity=10;->if needed
    printf("heapextractmax=%d\n",heapextractmax(&p));
    printf("heapmax=%d\n",heapmax(p));
    maxheapinsert(&p,5);// passing the address of struct ->since it is a call by reference changing heapsize
    maxheapinsert(&p,10);
    maxheapinsert(&p,15);
    printf("heapmax=%d\n",heapmax(p));
    maxheapinsert(&p,25);
    maxheapinsert(&p,25);
    printf("heapmax=%d\n",heapmax(p));
    printf("heapextractmax=%d\n",heapextractmax(&p));// passing the address of struct ->since it is a call by reference changing heapsize
    printf("heapextractmax=%d\n",heapextractmax(&p));
    printf("heapextractmax=%d\n",heapextractmax(&p));
    maxheapinsert(&p,15);
    maxheapinsert(&p,11);
    printf("heapmax=%d\n",heapmax(p));//call by value
}


