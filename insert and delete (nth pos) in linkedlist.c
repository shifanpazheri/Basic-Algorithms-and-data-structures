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
    if(head==NULL)printf("EMPTY");
    else{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
    }
}

node delete(node head,int pos)
{
    int i=1,n=0;
    node p=head->link,q=head,temp=head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->link;
    }
    if(pos>n)
    {
        printf("ERROR not possible\n");
    }
    else if(pos==1)
    {head=head->link;}
    else
    {
        while(i<n)
        {
            i++;
            if(i==pos)
            {
                q->link=p->link;
                free(p);
                break;
            }
            p=p->link;
            q=q->link;
        }
    }
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
    scanf("%d",&pos);
    head=delete(head,pos);
    print(head);
}

