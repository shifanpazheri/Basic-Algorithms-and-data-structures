#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};// never forget this semicolon

struct node * insert (struct node *head,int x)
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

void print(struct node * head)
{
    struct node *p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->link;
    }
}

int main()
{
    struct node * head=NULL;//NEVER FORGET THIS ->IT CAUSE SEGMENTATION FAULT
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        head=insert(head,x);
    }
    print(head);
}
