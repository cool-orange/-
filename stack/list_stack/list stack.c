/* #include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}sqtack;
sqtack* initstack()
{
    sqtack *top;
    top=(sqtack*)malloc(sizeof(sqtack));
    top->next=NULL;
    return top;
}
void emptysqtack(sqtack *s)
{
    if(s->next=NULL)
        return 1;
    else
        return 0;
}
void creatstack(sqtack *s,int n)
{
    int i;
    sqtack *q;
    for(i=0;i<n;i++)
    {
      q=(sqtack*)malloc(sizeof(sqtack));
      scanf("%d",&q->data);
      q->next=s->next;
      s->next=q;
    }
    return;
}
int stacklength(sqtack*s)
{
    int i=0;
    sqtack *p;
    p=s->next;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;

}
void push(sqtack *s,int e)
{
    sqtack*q;
    q=(sqtack*)malloc(sizeof(sqtack));
    if(q!=NULL)
    {
     q->data=e;
     q->next=s->next;
     s->next=q;
    }
    else
        printf("error\n");
    return;
}
int gettopstack(sqtack*s)
{
    return s->next->data;
}
void pop(sqtack *s)
{
    sqtack*p;
    p=s->next;
    s->next=p->next;
    printf("%d ",p->data);
    p->next=NULL;
    free(p);
}
void searchstack(sqtack*s)
{
    int i,m;
    i=1;
    sqtack *p;
    p=s->next;
    printf("���������Ԫ��:\n");
    scanf("%d",&m);
    while(p)
    {
        if(p->data==m)
        {
            printf("����Ԫ��λ��ջ����������%d��\n",i);
            break;
        }
        else
        {
            i++;
            p=p->next;
        }
    }
    if(p==NULL)
        printf("error\n");

}
void outputstack(sqtack*s)
{
    sqtack *p;
    p=s->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return;
}
void clearstack(sqtack**s)
{
    (*s)->next=NULL;
}
void destorystack(sqtack **s)
{
    sqtack *q;
    while((*s)->next!=NULL)
    {
        q=(*s)->next;
        free(s);
        *s=q;
    }
    if((*s)->next=NULL)
        free(*s);
    return;
}
int main()
{
    int i;
    sqtack *top;
    int n,length;
    top=initstack();
    printf("������ڵ����:\n");
    scanf("%d",&n);
    creatstack(top,n);
    length=stacklength(top);
    printf("������˳��ջ�ĳ���Ϊ%d\n",length);
    printf("ջ��Ԫ����%d\n",gettopstack(top));
    printf("�������ջ����ջ�׵�Ԫ��\n");
    outputstack(top);
    searchstack(top);
    printf("��Ԫ�����γ�ջ:\n");
    for(i=0;i<n;i++)
        pop(top);
    clearstack(&top);
    destorystack(&top);
    return ;
}*/

