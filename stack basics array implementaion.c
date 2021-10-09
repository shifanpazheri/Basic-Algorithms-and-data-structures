#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int data[100];
    int capacity;
};

void push(struct stack *s,int x)
{
    (s->top)++;
    if(s->top>=s->capacity)
    {
    	(s->top)--;
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

int main()
{
    struct stack s;
    s.top=-1;
    s.capacity=5;
    printf("%d\n",isempty(s));
    printf("%d\n",top(s));
    push(&s,2);
    printf("%d\n",top(s));
    printf("%d\n",isempty(s));
    push(&s,4);
    push(&s,28);
    push(&s,22);
    push(&s,42);
    push(&s,2);
    pop(&s);
    printf("%d\n",top(s));
    pop(&s);
    printf("%d\n",isempty(s));
}

