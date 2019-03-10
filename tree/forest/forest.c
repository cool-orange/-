#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
typedef struct CsNode
{
     char data;
     struct CsNode *firstchild,*nextsibling;
}CsNode,*CsTree;
typedef struct bitnode
{
    char data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;
typedef struct node
{
    CsTree *elem;
    int front;
    int rear;
}queue;
void initqueue(queue *Q)
{
    Q->elem=(CsTree*)malloc(Maxsize*sizeof(CsTree));
    if(!Q->elem)
      exit(0);
    Q->front=Q->rear=0;
    return;
}
void enqueue(queue *Q,CsTree e)
{
    if((Q->rear+1)%Maxsize==Q->front)
        return 0;
    Q->elem[Q->rear]=e;
    Q->rear=(Q->rear+1)%Maxsize;
    return ;
}
void dequeue(queue*Q,CsTree *e)
{
    if(Q->front==Q->rear)
      return 0;
    *e=Q->elem[Q->front];
    Q->front=(Q->front+1)%Maxsize;
    return ;
}
int queueEmpty(queue Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}
void destroyqueue(queue *Q)
{
    if(Q->elem)
        free(Q->elem);
    Q->elem=NULL;
    Q->front=Q->rear=0;
    return;
}
void clearqueue(queue *Q)
{
    Q->front=Q->rear=0;
    return;
}
void creaTtree(CsTree *T)//创建n叉树
{
     char c[20],m;
     CsTree p,p1;
     queue q;
     int i,l;
     initqueue(&q);
     *T=(CsTree)malloc(sizeof(CsNode));
     printf("请输入根节点:\n");
     scanf("%c",&c[0]);
     if(c[0])
     {
      (*T)->data=c[0];
      (*T)->nextsibling=NULL;
      enqueue(&q,*T);
      while(!queueEmpty(q))
      {
         dequeue(&q,&p);
         //printf("%c",p->data);
         printf("按从左至右输入结点%c的孩子:\n",p->data);
         getchar();
         gets(c);
         l=strlen(c);
         if(l>0&&c[0]!='#')
         {
             //printf("1");
             p1=p->firstchild=(CsTree)malloc(sizeof(CsNode));
             p1->data=c[0];
             for(i=1;i<l;i++)
             {
                 p1->nextsibling=(CsTree)malloc(sizeof(CsNode));
                 enqueue(&q,p1);
                 p1=p1->nextsibling;
                 p1->data=c[i];
             }
             p1->nextsibling=NULL;
             enqueue(&q,p1);
         }
         else
            p->firstchild=NULL;
      }
     }
      else
         *T=NULL;
      clearqueue(&q);
      destroyqueue(&q);
      return;
}
bitree transform(CsTree T)
{
    CsTree p;
    int num=0,i;
    if(T==NULL)
        return NULL;
    bitree root=(bitree)malloc(sizeof(bitnode));
    root->lchild=root->rchild=NULL;
    root->data=T->data;
    root->lchild=transform(T->firstchild);
    bitree brother=root->lchild;
    p=T->firstchild;
    while(p)
    {
        p=p->nextsibling;
        num++;
    }
    p=T->firstchild;
    for(i=1;i<num;i++)
    {
        brother->rchild=transform(p->nextsibling);
        brother=brother->rchild;
        p=p->nextsibling;
    }
    return root;
}
void traverse (bitree T)
{
    if(T==NULL)
        return;
    printf("%c ",T->data);
    traverse(T->lchild);
    traverse(T->rchild);
}
int main()
{
    int n,i=0;
    printf("请输入n叉树的个数:\n");
    scanf("%d",&n);
    getchar();
    CsTree T[100];
    bitree t[100];
    for(i=0;i<n;i++)
        creaTtree(&T[i]);
    for(i=0;i<n;i++)
        t[i]=transform(T[i]);
    for(i=0;i<n-1;i++)
        t[i]->rchild=t[i+1];
    traverse(t[0]);
    return 0;
}



