#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100
#define stackincrement 10
typedef struct bitnode
{
    char data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;
typedef struct stacknode
{
    bitree *top;
    bitree *base;
    int stacksize;
}stacknode;
int i=0;
void initstack(stacknode *s)
{
    s->base=(bitree*)malloc(stack_init_size*sizeof(bitree));
    if(!s->base)
    exit(0);
    s->top=s->base;
    s->stacksize=stack_init_size;
    return;
}
int stackempty(stacknode s )
{
    if(s.base==s.top)
        return 1;
    else
        return 0;
}
void pushopnd(stacknode*s,bitree e)
{
    if(s->top-s->base==s->stacksize)
    {
        s->base=(bitree*)realloc(s->base,(s->stacksize+stackincrement)*sizeof(bitree));
        if(!s->base)
            exit(0);
        s->top=s->base+s->stacksize;
        s->stacksize+=stackincrement;
    }
    *s->top++=e;
    return;
}
void popopnd (stacknode*s,bitree *x)
{
    int e;
    if(s->top==s->base)
        return;
    else
        *x=*(--s->top);
}
void creatbitree(bitree *T,char ch[])//前序遍历创建树
{
     if(ch[i]=='#')
    {
        *T=NULL;
        if(i==0)
            return;
        i++;
    }
    else
    {
      *T=(bitree)malloc(sizeof(struct bitnode));
      (*T)->data=ch[i];
      i++;
      creatbitree(&(*T)->lchild,ch);
      creatbitree(&(*T)->rchild,ch);
    }
}
void gettop_opnd(stacknode *s,bitree *e)
{
    if(s->base==s->top)
        return 0;
    *e=*(s->top-1);
    return;
}
void preordertraverse(bitree T)
{
    stacknode s;
    bitree p;
    initstack(&s);
    pushopnd(&s,T);
    while(!stackempty(s))
    {
        gettop_opnd(&s,&p);
        while(p!=NULL)
        {
            printf("%c",p->data);
            pushopnd(&s,p->lchild);
            p=p->lchild;
        }
        popopnd(&s,&p);
        if(!stackempty(s))
        {
            popopnd(&s,&p);
            pushopnd(&s,p->rchild);
        }
    }
}
void inordertraverse(bitree T)
{
    stacknode s;
    bitree p;
    initstack(&s);
    pushopnd(&s,T);
    while(!stackempty(s))
    {
        gettop_opnd(&s,&p);
        while(p!=NULL)
        {
            pushopnd(&s,p->lchild);
            p=p->lchild;
        }
        popopnd(&s,&p);
        if(!stackempty(s))
        {
            popopnd(&s,&p);
            printf("%c",p->data);
            pushopnd(&s,p->rchild);
        }

    }
    return;
}
void posordertraverse(bitree T)
{
    stacknode s;
    bitree p,pre=NULL;
    initstack(&s);
    pushopnd(&s,T);
    while(!stackempty(s))
    {
        gettop_opnd(&s,&p);
        if((p->lchild==NULL&&p->rchild==NULL)||(pre!=NULL&&(pre==p->rchild||pre==p->lchild)))
        {
            printf("%c",p->data);
            popopnd(&s,&p);
            pre=p;
        }
        else
        {
            if(p->rchild!=NULL)
                pushopnd(&s,p->rchild);
            if(p->lchild!=NULL)
                pushopnd(&s,p->lchild);
        }
    }
    return;
}
void bfs(bitree T)
{
    bitree q[100];
    bitree p;
    int front=-1,rear=0;
    q[rear]=T;
    while(front!=rear)
    {
        front=(front+1)%100;
        p=q[front];
        printf("%c",p->data);
        if(p->lchild)
        {
           rear=(rear+1)%100;
           q[rear]=p->lchild;
        }
        if(p->rchild)
        {
            rear=(rear+1)%100;
            q[rear]=p->rchild;
        }
    }

}
int main()
{
    bitree T;
    char ch[100];
    gets(ch);
    creatbitree(&T,ch);
    printf("请输出前序遍历:\n");
    preordertraverse(T);
    printf("\n");
    printf("请输出中序遍历:\n");
    inordertraverse(T);
    printf("\n");
    printf("请输出后序遍历:\n");
    posordertraverse(T);
    printf("请输出广度优先遍历(层次遍历):\n");
    bfs(T);
    return 0;
}
