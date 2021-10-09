//QUEUE USING LINKEDLIST
//use tail pointer to perform enqueue in O(1)->dont study this study from geeks
#include <stdio.h>
#include<stdlib.h>
// adding at the tail of linkedist is equivalent to linkedlist implementation of queue
struct node
{
    int data;
    struct node* link;
};// never forget this semicolon

struct node * enqueue (struct node *head,int x)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->data=x;
    if(head==NULL) head=temp;
    else 
    {
        struct node* p=head;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    return head;
}

int  dequeue(struct node ** head)
{
    struct node *p=*head;
    int x=p->data;
    *head=p->link;
    free(p);
    return x;
}

int main()
{
    struct node * head=NULL;//NEVER FORGET THIS ->IT CAUSE SEGMENTATION FAULT
    head=enqueue(head,2);
    head=enqueue(head,4);
    head=enqueue(head,6);
    printf("%d\n",dequeue(&head));//here we should pass the address of head to change head
    head=enqueue(head,8);
    printf("%d\n",dequeue(&head));//here we should pass the address of head to change head
    printf("%d\n",dequeue(&head));//here we should pass the address of head to change head
    head=enqueue(head,25);
    printf("%d\n",dequeue(&head));//here we should pass the address of head to change head
}
