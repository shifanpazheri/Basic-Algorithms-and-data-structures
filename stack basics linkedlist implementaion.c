#include<stdio.h>
#include<stdlib.h>

struct linkedlist
{
    struct linkedlist* link;
    int data;
};

struct linkedlist* createnode()
{
    struct linkedlist* temp=(struct linkedlist*) malloc(sizeof(struct linkedlist));
    temp->link=NULL;
    return temp;
}

struct linkedlist * push(struct linkedlist *head,int x)//Inserting at the head then only it will act as stack
{
    struct linkedlist* temp=createnode();
    temp->data=x;
    temp->link=head;
    head=temp;
    return head;
}

int isempty(struct linkedlist *head)
{
    if(head==NULL)
    return 1;
    return 0;
}

int peak(struct linkedlist *head)//To get the top value in stack
{
    if(isempty(head))
        return -999;
    else
        return head->data;
}

struct linkedlist * pop(struct linkedlist *head)
{
    struct linkedlist * temp=head;
    if(isempty(head))
        printf("EMPTY");
    else
    {
        head=temp->link;//assign value to head  
        free(temp);//i.e,dont do "temp=temp->link"since temp is local variable
                   //therefore their will not have any impact on head 
    }
    return head;
}

int main()
{
    struct linkedlist *top=NULL;
    printf("%d\n",isempty(top));//if empty it print 1 and print 0 otherwise
    printf("%d\n",peak(top));//if empty it print -999
    top=push(top,11);
    top=push(top,22);
    top=push(top,33);
    top=push(top,44);
    printf("%d\n",isempty(top));
    printf("%d\n",peak(top));
    top=pop(top);
    printf("%d\n",isempty(top));
    printf("%d\n",peak(top));
    top=pop(top);
    printf("%d\n",isempty(top));
    printf("%d\n",peak(top));
    top=pop(top);
    printf("%d\n",isempty(top));
    printf("%d\n",peak(top));
    top=pop(top);
    printf("%d\n",isempty(top));
    printf("%d\n",peak(top));
}

