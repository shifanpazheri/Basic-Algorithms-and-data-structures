#include <stdio.h>
#include <stdlib.h>
 
typedef struct linkedlist * node;

struct linkedlist
{
    int data;
    struct linkedlist * link;
};// never forget this semicolon
node insert(node head,int x)
{
  node temp=(node)malloc(sizeof(struct linkedlist));
  temp->data=x;
  temp->link=NULL;
  if(head==NULL)
  {
      head=temp;
  }
  else
  {
      node p=head;
      while(p->link!=NULL)
      {
          p=p->link;
      }
      p->link=temp;
  }
  return head;
}

void print(node head)
{
    node p=head;
    if(head==NULL)printf("EMPTY\n");
    else{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
    }
}

node reverse(node head)
{
    node p=head,prev=NULL,next=head;
    while(p!=NULL)
    {
       // printf("initial(%d,%d)->",p->data,p->link);
       next=next->link;
        p->link=prev;
        prev=p;
        p=next;
    }
    head=prev;
    return head;
}

int main()
{
    node head=NULL;//NEVER FORGET THIS ->IT CAUSE SEGMENTATION FAULT
    int n,pos,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        head=insert(head,x);
    }
   print(head);
   head=reverse(head);
   print(head);
}

