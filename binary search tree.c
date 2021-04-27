#include<stdio.h>
#include<stdlib.h>

struct binarysearchtree
{
  int key;
  struct binarysearchtree *p;	//p stands for parent
  struct binarysearchtree *left;
  struct binarysearchtree *right;
};

struct queue//used for level order tranversal
{
  int head;
  int tail;
  int capacity;
  int data[100];
};
int isempty(struct queue q)
{
    if(q.head==q.tail) return 1;
    else return 0;
}

int isfull(struct queue q)
{
    if(q.head==q.tail+1||(q.head==0&&q.tail==q.capacity-1)) return 1;
    else return 0;
}

void enqueue(struct queue *q,int x)
{
    if(!isfull(*q))
    {
        q->data[q->tail]=x;
        if(q->tail==q->capacity-1) q->tail=0;
        else q->tail++;
    }
    else
    printf("overflow\n");
}

int dequeue(struct queue *q)
{
    if(!isempty(*q))
    {
        int x=q->data[q->head];
        if(q->head==q->capacity-1) q->head=0;
        else q->head++;
        return x;
    }
    else return -999;
}

int max(int a,int b)
{
    if(a>=b)return a;
    return b;
}

struct binarysearchtree* getnode (int x)
{
  struct binarysearchtree* temp = (struct binarysearchtree*) malloc (sizeof (struct binarysearchtree));
  temp->key = x;
  temp->p = NULL;		
  temp->left = NULL;	
  temp->right = NULL;
  return temp;
}

struct binarysearchtree* treeinsert (struct binarysearchtree* root, int value)
{
  struct binarysearchtree* z = getnode(value);
  struct binarysearchtree* y = NULL;
  struct binarysearchtree* x = root;
  while (x != NULL)
    {
      y = x;
      if (z->key < x->key)
	x = x->left;
      else
	x = x->right;
    }
  z->p = y;
  if (y == NULL)
    root = z;			//case when tree is empty
  else if (z->key < y->key)//i think duplicate values will come in right tree
    y->left = z;
  else
    y->right = z;
  return root;//it is important to return root
}

void inorderprint(struct binarysearchtree* root)
{
    if(root==NULL) return;
    inorderprint(root->left);//here root is local so it will not change the original root value
    printf("%d\n",root->key);
    inorderprint(root->right);//here root is local so it will not change the original root value
}

int maximumiterative(struct binarysearchtree* root)
{
  if(root==NULL) return -999;
  while(root->right!=NULL)
  {
      root=root->right;
  }
  return root->key;
}

int maximumrec(struct binarysearchtree* root)
{
    if(root==NULL) return-999;
    if(root->right!=NULL)
        return maximumrec(root->right);
    return root->key;
}

int minimumrec(struct binarysearchtree* root)
{
    if(root==NULL)return-999;
    else if(root->left==NULL)return root->key;
    else return minimumrec(root->left);
}

int minimumiterative(struct binarysearchtree* root)
{
    if(root==NULL) return-999;
    while(root->left!=NULL)
        root=root->left;
    return root->key;
}

int searchrec(struct binarysearchtree* root,int k)
{
    if(root==NULL) return 0;
    else if(root->key==k) return 1; 
    else if (root->key>k) return searchrec(root->left,k);
    else return searchrec(root->right,k);
}

int searchiterative(struct binarysearchtree* root,int k)
{
    if(root==NULL) return 0;
    while(root!=NULL)
    {
        if(root->key==k) return 1;
        else if (root->key>k) root=root->left;
        else root=root->right;
    }
    return 0;
}

int treesucessor(struct binarysearchtree* root,int k)// assuming "k" is present in tree and tree is not empty but next treepredecessor corrects it.
{//This wil be very difficut if parent is not their in structure declration
    struct binarysearchtree* x=root;
    while(x!=NULL)//This while is used to locate the pointer to whose  key value is "k" 
    {
        if(x->key==k) break;
        else if (x->key>k) x=x->left;
        else x=x->right;
    }
    if(x->right!=NULL)
        return minimumrec(x->right);
    struct binarysearchtree* y=x->p;
    while(y!=NULL&&x!=y->left)
    {
        x=y;
        y=y->p;
    }
    if(y!=NULL) return y->key;
    return -999;
}

int treepredecessor(struct binarysearchtree* root,int k)//return -999 if k is not present  or if it don't have treepredecessor
{//This wil be very difficut if parent is not their in structure declration
    struct binarysearchtree* x=root;
    if(root ==NULL) return-999;
    while(x!=NULL)// instead of while use findpointerwithvalue efficently
    {
        if(x->key==k) break;
        else if(x->key>k) x=x->left;
        else x=x->right;
    }
    if(x==NULL) return-999;
    //printf("hello");
    if(x->left!=NULL) return maximumiterative(x->left);
    struct binarysearchtree* y=x->p;
    while(y!=NULL&&x!=y->right)
    {
        x=y;
        y=y->p;
    }
    if(y!=NULL) return y->key;
    return-999;
}

struct binarysearchtree * findpointerwithvalue(struct binarysearchtree *root,int k)//return NULL if k is not present
{
    struct binarysearchtree* x=root;
    if(root ==NULL) return NULL;
    while(x!=NULL)
    {
        if(x->key==k) return x;
        else if(x->key>k) x=x->left;
        else x=x->right;
    }
    return NULL;
}

int heightbst(struct binarysearchtree * root)
{
    if (root==NULL) return -1;
    return max(heightbst(root->left),heightbst(root->right))+1;
}

void preorderprint(struct binarysearchtree* root)
{
    if(root==NULL) return;
    printf("%d\n",root->key);
    preorderprint(root->left);
    preorderprint(root->right);
}

void postorderprint(struct binarysearchtree* root)
{
    if(root==NULL) return;
    postorderprint(root->left);
    postorderprint(root->right);
    printf("%d\n",root->key);
}

int issubtreelesser(struct binarysearchtree* root,int data)
{
    if(root==NULL) return 1;
    if(root->key<data&&issubtreelesser(root->left,data)&&issubtreelesser(root->right,data))
        return 1;
    return 0;
}

int issubtreegreater(struct binarysearchtree* root,int data)
{
    if(root==NULL) return 1;
    if(root->key>=data&&issubtreegreater(root->left,data)&&issubtreegreater(root->right,data))
        return 1;
    return 0;
}

int isbinarytree(struct binarysearchtree* root)
{
    if(root==NULL) return 1;
    if(isbinarytree(root->left)&&isbinarytree(root->right)&&issubtreelesser(root->left,root->key)&&issubtreegreater(root->right,root->key))
        return 1; //As I am keeping my duplicate values in right subtree
    return 0;
}

int main ()
{
  struct binarysearchtree * root=NULL;//its important to initialise to NULL
  root = treeinsert (root, 5);	//modifying operation
  root = treeinsert (root, 3);	//modifying operation
  root = treeinsert (root, 3);	//modifying operation
  root = treeinsert (root, 6);	//modifying operation
  root = treeinsert (root, 2);	//modifying operation
  root = treeinsert (root, 12);	//modifying operation
  root = treeinsert (root, 12);	//modifying operation
  root = treeinsert (root, 11);	//modifying operation
  root = treeinsert (root, 21);	//modifying operation
  root = treeinsert (root, 4);	//modifying operation
  root = treeinsert (root, 32);	//modifying operation
  root = treeinsert (root, 7);	//modifying operation
  printf("max=%d\n",maximumiterative(root));//quering operation
  printf("max=%d\n",maximumrec(root));//quering operation
  printf("min=%d\n",minimumiterative(root));//quering operation
  printf("min=%d\n",minimumrec(root));//quering operation
  printf("found=%d\n",searchrec(root,5));//quering operation
  printf("found=%d\n",searchiterative(root,2));//quering operation
  printf("treesucessor=%d\n",treesucessor(root,3));//quering operation
  printf("treepredecessor=%d\n",treepredecessor(root,5));//quering operation
  struct binarysearchtree * nodepointer=findpointerwithvalue(root,3);//find pointer of the node with given value
  if(nodepointer!=NULL) printf("value=%d\n",nodepointer->key);
  else printf("invalid number\n");
  printf("heightbst=%d\n",heightbst(root));
  printf("inorderprint:\n");
  inorderprint(root);
  printf("preorderprint:\n");
  preorderprint(root);
  printf("postorderprint:\n");
  postorderprint(root);
  printf("isbinarytree=%d\n",isbinarytree(root));
  struct binarysearchtree * check=NULL;//its important to initialise to NULL
  check=getnode(10);// To check whether isbinarytree function works if its not a bst case->it works as expected
  check->right=getnode(2);
  check->left=getnode(-12);
  printf("isbinarytree=%d\n",isbinarytree(check));
}
