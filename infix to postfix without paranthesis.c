//WITHOUT PARANTHESIS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int isoperand(char c)
{
    if(c>='0'&&c<='9') return 1;//here greter than equal to is compulsary
    if(c>='a'&&c<='z') return 1;//here greter than equal to is compulsary
    if(c>='A'&&c<='Z') return 1;//here greter than equal to is compulsary
    return 0;
}

int isoperator(char c)
{
    if(c=='^'||c=='/'||c=='*'||c=='+'||c=='-'||c=='('||c==')')
        return 1;
    return 0;
}

int prec(char a)
{
    if(a=='^') return 3;
    if(a=='/'||a=='*') return 2;
    if(a=='+'||a=='-') return 1;
    return 0;
}

int hashigherprec(char a,char b)
{
    if(prec(a)>=prec(b))//here greter than equal to is compulsary
        return 1;
    return 0;
}

void infixtoprefix(char exp[])
{
    struct stack s;
    s.top=-1;
    s.capacity=100;
    char res[100];
    int j=0;
    for(int i=0;i<strlen(exp);i++)
    {
        if(isoperand(exp[i]))//check wheather its a number or not
        {
            res[j]=exp[i];
            j++;
        }
        else if(isoperator(exp[i]))//check wheather its a operator or not
        {
            while(!isempty(s)&&hashigherprec(top(s),exp[i]))
            {
                res[j]=top(s);
                j++;
                pop(&s);
            }
            push(&s,exp[i]);
        }
        //printf("%c\n",s.data[s.top]);
    }
    while(!isempty(s))//transfer remaining elements of stack
    {
        res[j]=top(s);
        j++;
        pop(&s);
    }
    printf("%s",res);
}

int main()
{
    char exp[100];
    scanf("%s",exp);
    infixtoprefix(exp);
}

