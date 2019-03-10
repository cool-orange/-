    #include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
        return ;
    Q->elem[Q->rear]=e;
    Q->rear=(Q->rear+1)%Maxsize;
    return ;
}
void dequeue(queue*Q,CsTree *e)
{
    if(Q->front==Q->rear)
      return ;
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
void creaTtree(CsTree *T)//����n����
{
     char c[20];
     CsTree p,p1;
     queue q;
     int i,l;
     initqueue(&q);
     *T=(CsTree)malloc(sizeof(CsNode));
     printf("��������ڵ�:\n");
     scanf("%c",&c[0]);
     getchar();
     if(c[0])
     {
      (*T)->data=c[0];
      (*T)->nextsibling=NULL;
      enqueue(&q,*T);
      while(!queueEmpty(q))
      {
         dequeue(&q,&p);
         printf("����������������%c�ĺ���:\n",p->data);
         //getchar();
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
      return;
}
void preordertraverse(CsTree T)//ֱ�ӷ��������
{
    if(T==NULL)
        return;
    printf("%c ",T->data);
    preordertraverse(T->firstchild);
    preordertraverse(T->nextsibling);
}
void posordertraverse(CsTree T)//ֱ�ӷ��������
{
    CsTree p;
    if(T)
    {
     if(T->firstchild)
     {
        posordertraverse(T->firstchild);
        p=T->firstchild->nextsibling;
        while(p)
        {
            posordertraverse(p);
            p=p->nextsibling;
        }
     }
    printf("%c ",T->data);
    }
}
void bfs(CsTree T)//������ȱ���
{
    CsTree p;
    queue q;
    initqueue(&q);
    if(T)
    {
        printf("%c ",T->data);
        enqueue(&q,T);
        while(!queueEmpty(q))
        {
            dequeue(&q,&p);
            if(p->firstchild)
            {
                p=p->firstchild;
                printf("%c ",p->data);
                enqueue(&q,p);
                while(p->nextsibling)
                {
                    p=p->nextsibling;
                    printf("%c ",p->data);
                    enqueue(&q,p);
                }
            }

        }
    }
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
void postordertraverse(bitree T)
{
    if(T==NULL)
        return;
    postordertraverse(T->lchild);
    postordertraverse(T->rchild);
    printf("%c ",T->data);
}
int main()
{
    bitree root;
    CsTree T;
    creaTtree(&T);
    printf("������������n����:\n");
    preordertraverse(T);
    printf("\n");
    printf("������������n����:\n");
    posordertraverse(T);
    printf("\n");
    printf("������������n����:\n");
    bfs(T);
    printf("\n");
    root=transform(T);
    printf("�����������Ķ��������������:\n");
    traverse(root);
    printf("\n");
    printf("�����������Ķ������ĺ������:\n");
    postordertraverse(root);
    return 0;
}


