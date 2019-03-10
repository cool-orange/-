//适用于一元多项式相加减
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int coef;//系数
    int index;//指数
    struct LNode *next;
}LNode;
//创建头结点
LNode *createhead()       //如果选择void类型的函数，则应传递二级指针
{
    LNode *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    return head;
}
/*//头插法创建链表
void headinsert(LNode *head,int n)
{
    int i,temp;
    LNode *p,*s;
    s=head;
    printf("请依次输入各结点数据域的元素\n");
    for(i=n;i>0;i--)
    {
        p=(LNode *)malloc(sizeof(LNode));
        scanf("%d",&temp);
        p->data=temp;
        p->next=s->next;
        s->next=p;
    }
}*/
//尾插法创建链表
void tailinsert(LNode *head,int n)
{
    int i,temp1,temp2;
    LNode *p,*s;
    s=head;
    printf("请依次输入各结点数据域的元素,第一个表示系数，第二个表示指数\n");
    for(i=0;i<n;i++)
    {
        p=(LNode *)malloc(sizeof(LNode));
        scanf("%d%d",&temp1,&temp2);
        p->coef=temp1;
        p->index=temp2;
        p->next=s->next;
        s->next=p;
        s=s->next;
    }
}
/*//在链表中插入一个元素
void listinsert(LNode *L,int i,int e,int n)
{
    LNode *p,*s;
    int j;
    p=(LNode *)malloc(sizeof(LNode));
    p->data=e;
    s=L;
    if(i>n||i<0)
    {
        printf("输入的位置不存在\n");
        exit(0);
    }
    else
    {
        for(j=0;j<i;j++)
            s=s->next;
        p->next=s->next;
        s->next=p;
    }
}*/

/*//删除某元素
void listdelete_element(LNode *L,int e)
{
    LNode *p,*s;
    for(p=L->next,s=L;p->data!=e;p=p->next,s=s->next)
    {

        if(p->next==NULL)
        {
            printf("此链表中不存在此元素\n");
            exit(0);
        }
    }
    s->next=p->next;
    free(p);
}*/
/*//删除某位置的元素
void listdelete_position(LNode *L,int pos)
{
    int i;
    LNode *p,*s;
    p=L->next;
    s=L;
    if(pos<=0)
    {
        printf("此链表中不存在此位置\n");
        exit(0);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            if(p->next==NULL)
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
    s->next=p->next;
    free(p);
}*/
/*//查找某元素所在位置
int finding_element(LNode *L,int e)
{
    int i=1;
    LNode *p;
    p=L->next;
    while(p!=NULL)
    {
        if(p->data==e)
          break;
        i++;
        p=p->next;
    }
    if(p==NULL)
    {
        printf("此元素不存在\n");
        exit(0);
    }
    return i;
}*/
/*//查找某位置对应的元素
int finding_position(LNode *L,int pos)
{
    int i;
    LNode *p;
    p=L;
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
        if(p==NULL)
        {
            printf("此位置不存在\n");
            exit(0);
        }
    }
    return p->data;
}*/
//输出链表中各结点的数据
void putlist(LNode *L)
{
    LNode *p;
    for(p=L->next;p!=NULL;p=p->next)
        printf("%d %d\n",p->coef,p->index);
}
