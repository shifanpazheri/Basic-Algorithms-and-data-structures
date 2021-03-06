#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

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

int value(char *c,int f,int l)
{
    if(f>l) return -999;
    int len=l-f;
    int no=0;
//    if(strlen(c)==0) return -999;
    for(int i=f;i<=l;i++)
    {
 //       printf("len=%d\n",len);
   //     printf("c[i]=%d\n",c[i]-'0');
        no=no+pow(10,len)*(c[i]-'0');
     //   printf("no=%d\n",no);
        len--;
    }
    return no;
}

int findIndex(char c[],int f,int l)
{
    if(f>l) return -1;
    struct stack s;
    s.top=-1;
    s.capacity=99999;
    for(int i=f;i<=l;i++)
    {
        if(c[i]=='(')
        {
            push(&s,c[i]);
        }
        if(c[i]==')')
        {
            if(top(s)=='(')
               pop(&s);
        }
        if(isempty(s)) return i;
    }
    return -1;
}

struct node* getnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

struct node* treeFromString(char str[], int si, int ei)
{
    // Base case
    if (si > ei)
        return NULL;
    int val;
    int i=si;
    while(str[i]!='(')
    {
        i++;
    }
 //   printf("%c\n",str[i]);
    val=value(str,si,i-1);
    // new root
//    printf("%d\n",val);
    struct node* head = getnode(val);
    int index = -1;
   // printf("str[i]=%c\n",str[i]);
    //printf("i=%d,ei=%d\n",i,ei);
    if (i <= ei && str[i] == '(')
        {
            //printf("check");
            index = findIndex(str, i , ei);// if next char is '(' find the index of its complement ')'
        }
    //printf("index=%d\n",index);
    // if index found
    if (index != -1) {
        head->left = treeFromString(str, i + 1, index - 1);// recursive call for left subtree->it exclude start and end parenthesis
        head->right = treeFromString(str, index + 2, ei-1);// recursive call for right subtree->it exclude start and end parenthesis
    }
    return head;
}

void preOrder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    char str[] = "(4(2(5()())())(3(9()())()))";
    struct node* head=NULL;
    head=treeFromString(str, 1, strlen(str) - 2);
    preOrder(head);
  //  printf("%d",value("589654",3,2));
}
