#include <stdio.h>
#include <stdlib.h>
typedef struct doublelinkedlist *node;

struct doublelinkedlist
{
    int data;
    struct doublelinkedlist * prev;
    struct doublelinkedlist * next;
};

node createnode()
{
    node temp=(node)malloc(sizeof(struct doublelinkedlist));
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
//we should allocate memory in heap(using malloc)->using pointer(like this).i e. node ->is a  pointer
//caution don't allocate in stack (without using pointer)->because stack memory will be cleared after finishing getnode function call
}

node insertathead(node head,int x)
{
    node temp=createnode();
    temp->data=x;
    if(head==NULL) head=temp;//very important dont forget it! withouut this use of "head->prev=temp" gives segmentation fault
    else{
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
    return head;
}

node insertatend(node head,int x)
{
    node temp=createnode();
    temp->data=x;
    if(head==NULL) head=temp;
    else
    {
        node p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
    return head;
}

void print(node head)
{
    node p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
     printf("\n");
}

void printrev(node head)
{
    node p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
    printf("\n");
}

int main()
{
    node head=NULL;
    int n1,n2,x;
    scanf("%d",&n1);// no.of elements to be inserted at head 
    scanf("%d",&n2);// no.of elements to be inserted at end
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&x);
        head=insertathead(head,x);
    }
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&x);
        head=insertatend(head,x);
    }
    print(head);
    printrev(head);
}
