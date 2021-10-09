//QUEUE USING ARRAY
#include <stdio.h>
//according to this code given in CLRS only (capacity-1) element can be inserted
struct queue
{
  int head;
  int tail;
  int capacity;
  int data[100];
};
int isempty(struct queue q)
{
    if(q.head==q.tail) return 1;
    else return 0;
}

int isfull(struct queue q)
{
    if(q.head==q.tail+1||(q.head==0&&q.tail==q.capacity-1)) return 1;
    else return 0;
}

void enqueue(struct queue *q,int x)
{
    if(!isfull(*q))
    {
        q->data[q->tail]=x;
        if(q->tail==q->capacity-1) q->tail=0;
        else q->tail++;
    }
    else
    printf("overflow\n");
}

int dequeue(struct queue *q)
{
    if(!isempty(*q))
    {
        int x=q->data[q->head];
        if(q->head==q->capacity-1) q->head=0;
        else q->head++;
        return x;
    }
    else return -999;
}

int main() {
    struct queue q;
    q.head=0;
    q.tail=0;
    q.capacity=7;
    printf("%d\n",isempty(q));
    printf("%d\n",isfull(q));
    enqueue(&q,8);
    printf("%d\n",isempty(q));
    enqueue(&q,81);
    enqueue(&q,18);
    enqueue(&q,88);
    enqueue(&q,28);
    enqueue(&q,12);
   // printf("%d\n",dequeue(&q));
    enqueue(&q,8);
   // printf("%d\n",dequeue(&q));
    printf("%d\n",isempty(q));
    printf("%d\n",isfull(q));
}
