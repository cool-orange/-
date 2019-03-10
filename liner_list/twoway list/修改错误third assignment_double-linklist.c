#include<stdio.h>
#include<stdlib.h>
typedef struct DuLNode
{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode;
typedef struct
{
    DuLNode *head,*tail;
}Linklist;
//创建头结点和尾结点
void creatheadandtail(Linklist *L)
{
    L->head=(DuLNode *)malloc(sizeof(DuLNode));
    L->tail=(DuLNode *)malloc(sizeof(DuLNode));
    L->head->next=L->tail;
    L->head->prior=NULL;
    L->tail->prior=L->head;
    L->tail->next=NULL;
}
//头插法创建链表
void headinsert(Linklist *L,int n)
{
    int i,temp;
    DuLNode *p,*s;
    s=L->head;
    printf("请依次输入各结点数据域的元素\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        p=(DuLNode *)malloc(sizeof(DuLNode));
        p->data=temp;
        p->next=s->next;
        p->prior=s;
        s->next=p;
        p->next->prior=p;
    }
}
//尾插法创建链表
void tailinsert(Linklist *L,int n)
{
    int i,temp;
    DuLNode *p,*s;
    s=L->tail;
    printf("请依次输入各结点数据域的元素\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        p=(DuLNode *)malloc(sizeof(DuLNode));
        p->data=temp;
        p->prior=s->prior;
        p->next=s;
        s->prior=p;
        p->prior->next=p;
    }
}
//在链表中插入一个元素
void listinsert(Linklist *L,int pos,int e,int n)
{
    int i;
    DuLNode *p,*s;
    p=(DuLNode *)malloc(sizeof(DuLNode));
    p->data=e;
    s=L->head;
    if(pos>n||pos<0)
    {
        printf("输入的位置不存在\n");
        exit(0);
    }
    else
    {
        for(i=0;i<pos;i++)
            s=s->next;
        p->next=s->next;
        p->prior=s;
        s->next=p;
        p->next->prior=p;
    }
}
//删除某元素
void listdelete_element(Linklist*L,int e)
{
    DuLNode *p,*s;
    for(p=L->head->next,s=L->head;p->data!=e;p=p->next,s=s->next)
    {

        if(p->next->next==NULL)
        {
            printf("此链表中不存在此元素\n");
            exit(0);
        }
    }
    p->next->prior=s;
    s->next=p->next;
    free(p);
}
//删除某位置的元素
void listdelete_position(Linklist*L,int pos)
{
    int i;
    DuLNode *p,*s;
    p=L->head->next;
    s=L->head;
    if(pos<=0)
    {
        printf("此链表中不存在此位置\n");
        exit(0);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            if(p->next->next==NULL)
            {
                printf("此链表中不存在此位置\n");
                exit(0);
            }
            else
            {
                s=s->next;
                p=p->next;
            }
        }
    }
    p->next->prior=s;
    s->next=p->next;
    free(p);
}
//查找某元素所在位置
int finding_element(Linklist *L,int e)
{
    int i=1;
    DuLNode *p;
    p=L->head->next;
    while(p->next!=NULL)
    {
        if(p->data==e)
          break;
        i++;
        p=p->next;
    }
    if(p->next==NULL)
    {
        printf("此元素不存在\n");
        exit(0);
    }
    return i;
}
//查找某位置对应的元素
int finding_position(Linklist *L,int pos)
{
    int i;
    DuLNode *p;
    p=L->head;
    if(pos<=0)
    {
        printf("此位置不存在\n");
        exit(0);
    }
    else
    {
        for(i=0;i<pos;i++)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
            printf("此位置不存在\n");
            exit(0);
        }
    }
    return p->data;
}
//顺序输出链表中各结点的数据
void putlist(Linklist *L)
{
    DuLNode *p;
    for(p=L->head->next;p->next!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
}
//逆序输出链表中各结点的数据
void putlistinvert(Linklist *L)
{
    DuLNode *p;
    for(p=L->tail->prior;p->prior!=NULL;p=p->prior)
    {
        printf("%d ",p->data);
    }
}
int main()
{
    int i,n,choice3,elem,position;
    char choice1,choice2;
    Linklist *L;
    creatheadandtail(L);
    printf("请输入需要创建的双向链表的长度\n");
    scanf("%d",&n);
    printf("请选择您创建链表的方式：a.头插法 b.尾插法\n");
    scanf("\n%c",&choice1);
    if(choice1=='a')
        headinsert(L,n);
    else
        tailinsert(L,n);
    printf("请输入你想要实现的操作：1.插入 2.删除某元素 3.删除某位置的元素 4.查找某元素 5.查找某位置的元素\n");
    scanf("%d",&choice3);
    switch(choice3)
    {
        case 1:printf("请输入您想在链表中插入的元素及其位置（第几个结点之后）\n");scanf("%d%d",&elem,&position);listinsert(L,position,elem,n);break;
        case 2:printf("请输入需要删除的元素\n");scanf("%d",&elem);listdelete_element(L,elem);break;
        case 3:printf("请输入需要删除的元素所在的位置\n");scanf("%d",&position);listdelete_position(L,position);break;
        case 4:printf("请输入需要查找的元素\n");scanf("%d",&elem);position=finding_element(L,elem);printf("此元素的位置为%d",position);exit(0);
        case 5:printf("请输入需要查找的位置\n");scanf("%d",&position);elem=finding_position(L,position);printf("此位置对应的元素为%d",elem);exit(0);
    }
    printf("请选择您输出链表的方式：a.顺序输出 b.逆序输出\n");
    scanf("\n%c",&choice2);
    if(choice2=='a')
        putlist(L);
    else
        putlistinvert(L);
}


















