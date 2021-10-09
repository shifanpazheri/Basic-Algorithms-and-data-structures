#include <stdio.h>
#include <string.h>
#include <ctype.h>//to use isdigit()
struct stack
{
    int top;
    int data[100];
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

void postfixevaluate(char *string)
{
    int n=strlen(string);
    struct stack s;
    s.top=-1;
    s.capacity=100;//it is compulsary to initialise it
    for(int i=0;i<n;i++)
    {
        if(isdigit(string[i]))//use <ctype.h>library
        {
            push(&s,(int)string[i]-48);//it is necessary to subtract 48 to convert to number
        }
        else
        {
            int op2=top(s);pop(&s);
            int op1=top(s);pop(&s);
            switch(string[i])
            {
                case '+':push(&s,op1+op2);
                         break;
                case '-':push(&s,op1-op2);
                         break;
                case '*':push(&s,op1*op2);
                         break;
                case '/':push(&s,op1/op2);
                         break;
            }
        }
    }
    printf("%d",top(s));
}

int main()
{
    char string[100];
    scanf("%s",string);
    postfixevaluate(string);
}
