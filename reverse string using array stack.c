#include <stdio.h>
#include <string.h>
struct stack
{
    int top;
    char data[100];
    int capacity;//if you use we should define it as large value or dont use it
};

void push(struct stack *s,int x)
{
    (s->top)++;
    if(s->top>=s->capacity)
    {
        printf("OVERFLOW\n");
    }
    else
    s->data[s->top]=x;
}

int isempty(struct stack s)
{
    if(s.top==-1)
    return 1;
    return 0;
}

int top(struct stack s)
{
    if(isempty(s))
        return -999;
    else
        return s.data[s.top];
}

void pop(struct stack*s)
{
    if(isempty(*s))
        printf("EMPTY\n");
    else
    {
        s->top--;
    }
}

void reverse(char *string,int n)
{
    struct stack s;
    s.top=-1;
    s.capacity=100;//it is compulsary to initialise it
    for(int i=0;i<n;i++)
        push(&s,string[i]);
    for(int i=0;i<n;i++)
    {
        string[i]=top(s);
        pop(&s);
    }
}

int main()
{
    char string[100];
    scanf("%s",string);
    reverse(string,strlen(string));
    printf("%s",string);
}
