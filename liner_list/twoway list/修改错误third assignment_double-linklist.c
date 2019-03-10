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
//����ͷ����β���
void creatheadandtail(Linklist *L)
{
    L->head=(DuLNode *)malloc(sizeof(DuLNode));
    L->tail=(DuLNode *)malloc(sizeof(DuLNode));
    L->head->next=L->tail;
    L->head->prior=NULL;
    L->tail->prior=L->head;
    L->tail->next=NULL;
}
//ͷ�巨��������
void headinsert(Linklist *L,int n)
{
    int i,temp;
    DuLNode *p,*s;
    s=L->head;
    printf("���������������������Ԫ��\n");
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
//β�巨��������
void tailinsert(Linklist *L,int n)
{
    int i,temp;
    DuLNode *p,*s;
    s=L->tail;
    printf("���������������������Ԫ��\n");
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
//�������в���һ��Ԫ��
void listinsert(Linklist *L,int pos,int e,int n)
{
    int i;
    DuLNode *p,*s;
    p=(DuLNode *)malloc(sizeof(DuLNode));
    p->data=e;
    s=L->head;
    if(pos>n||pos<0)
    {
        printf("�����λ�ò�����\n");
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
//ɾ��ĳԪ��
void listdelete_element(Linklist*L,int e)
{
    DuLNode *p,*s;
    for(p=L->head->next,s=L->head;p->data!=e;p=p->next,s=s->next)
    {

        if(p->next->next==NULL)
        {
            printf("�������в����ڴ�Ԫ��\n");
            exit(0);
        }
    }
    p->next->prior=s;
    s->next=p->next;
    free(p);
}
//ɾ��ĳλ�õ�Ԫ��
void listdelete_position(Linklist*L,int pos)
{
    int i;
    DuLNode *p,*s;
    p=L->head->next;
    s=L->head;
    if(pos<=0)
    {
        printf("�������в����ڴ�λ��\n");
        exit(0);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            if(p->next->next==NULL)
            {
                printf("�������в����ڴ�λ��\n");
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
//����ĳԪ������λ��
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
        printf("��Ԫ�ز�����\n");
        exit(0);
    }
    return i;
}
//����ĳλ�ö�Ӧ��Ԫ��
int finding_position(Linklist *L,int pos)
{
    int i;
    DuLNode *p;
    p=L->head;
    if(pos<=0)
    {
        printf("��λ�ò�����\n");
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
            printf("��λ�ò�����\n");
            exit(0);
        }
    }
    return p->data;
}
//˳����������и���������
void putlist(Linklist *L)
{
    DuLNode *p;
    for(p=L->head->next;p->next!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
}
//������������и���������
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
    printf("��������Ҫ������˫������ĳ���\n");
    scanf("%d",&n);
    printf("��ѡ������������ķ�ʽ��a.ͷ�巨 b.β�巨\n");
    scanf("\n%c",&choice1);
    if(choice1=='a')
        headinsert(L,n);
    else
        tailinsert(L,n);
    printf("����������Ҫʵ�ֵĲ�����1.���� 2.ɾ��ĳԪ�� 3.ɾ��ĳλ�õ�Ԫ�� 4.����ĳԪ�� 5.����ĳλ�õ�Ԫ��\n");
    scanf("%d",&choice3);
    switch(choice3)
    {
        case 1:printf("�����������������в����Ԫ�ؼ���λ�ã��ڼ������֮��\n");scanf("%d%d",&elem,&position);listinsert(L,position,elem,n);break;
        case 2:printf("��������Ҫɾ����Ԫ��\n");scanf("%d",&elem);listdelete_element(L,elem);break;
        case 3:printf("��������Ҫɾ����Ԫ�����ڵ�λ��\n");scanf("%d",&position);listdelete_position(L,position);break;
        case 4:printf("��������Ҫ���ҵ�Ԫ��\n");scanf("%d",&elem);position=finding_element(L,elem);printf("��Ԫ�ص�λ��Ϊ%d",position);exit(0);
        case 5:printf("��������Ҫ���ҵ�λ��\n");scanf("%d",&position);elem=finding_position(L,position);printf("��λ�ö�Ӧ��Ԫ��Ϊ%d",elem);exit(0);
    }
    printf("��ѡ�����������ķ�ʽ��a.˳����� b.�������\n");
    scanf("\n%c",&choice2);
    if(choice2=='a')
        putlist(L);
    else
        putlistinvert(L);
}


















