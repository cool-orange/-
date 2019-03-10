#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x;
    struct node *prior;
    struct node *next;
}Node;
typedef struct
{
    Node *head,*tail;
}linklist;
int maininterface()
{
    int n;
    printf("\t\t\t\t\t\t|--------------------------|\n");
	printf("\t\t\t\t\t\t|        1.����ڵ�        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        2.ɾ���ڵ�        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        3.���ҽ��        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        4.���˫������    |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.�˳�����        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
int lengthlist(linklist *L)
{
    Node *p;
    int i=0;
    p=L->head->next;
    while(p!=L->tail)
    {
        i++;
        p=p->next;
    }
    return i;
}
void creatlist(linklist *L)
{

    int i;
    Node*p,*q;
    L->head=(Node*)malloc(sizeof(Node));
    L->tail=(Node*)malloc(sizeof(Node));
    L->head->prior=NULL;
    L->head->next=L->tail;
    L->tail->prior=L->head;
    L->tail->next=NULL;
    p=L->head;
    int n;
    printf("������ڵ����:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        q=(Node*)malloc(s  izeof(Node));
        scanf("%d",&q->x);
        q->next=L->tail;
        L->tail->prior=q;
        q->prior=p;
        p->next=q;
        p=q;
    }
    return;
}
void insertlist(linklist *L)
{
    int pos,m,i=0,length;
    Node *p,*q;
    printf("���������λ�ú�Ԫ��:\n");
    scanf("%d %d",&pos,&m);
    p=L->head;
    length=lengthlist(L);
    if(pos<0||pos>length+1)
    {
        printf("��������!");
        exit(0);
    }

    while(i<pos-1)
    {
        p=p->next;
        i++;
    }

    q=(Node*)malloc(sizeof(Node));
    q->x=m;
    q->prior=p;
    q->next=p->next;
    p->next->prior=q;
    p->next=q;
    return;
}
void deletelist(linklist *L)
{
    int n,i=0,m;
    Node *p,*q;
    printf("<1>ɾ��Ԫ��<2>ɾ��λ�ö�ӦԪ��\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("������ɾ��Ԫ��\n");
        scanf("%d",&m);
        p=L->head;
        while(p!=NULL)
        {
            q=p->next;
            if(q->x==m)
           {
             q->prior->next=q->next;
             q->next->prior=q->prior;
             free(q);
             break;
           }
          else
            p=p->next;
      }
    }
    if(n==2)
    {
        printf("������ɾ��λ��\n");
        scanf("%d",&m);
        p=L->head;
        for(i=1;i<m;i++)
           p=p->next;
        q=p->next;
        q->prior->next=q->next;
        q->next->prior=q->prior;
        free(q);
    }
    return;;
}
void getlist(linklist L)
{
    Node *p;
    int m,n,i=1,j;
    printf("<1>������ҵ�Ԫ�صõ�λ��<2>����λ�õõ�����Ԫ��\n");
    scanf("%d",&m);
    if(m==1)
    {
        printf("���������Ԫ��\n");
        scanf("%d",&n);
        p=L.head->next;
        while(p!=NULL)
        {
            if(p->x==n)
            {
                printf("��Ԫ��λ�������%d��λ��\n",i);
                break;
            }
            else
            p=p->next;
            i++;
        }
    }
    if(m==2)
    {
        printf("������λ��\n");
        scanf("%d",&n);
        p=L.head->next;
        for(j=1;j<n;j++)
        p=p->next;
        printf("��λ�ö�Ӧ��Ԫ��Ϊ%d",p->x);
    }
    return;;
}
void outputlist(linklist L)
{
    Node *p;
    int n;
    printf("<1>����������� <2>�����������\n");
    scanf("%d",&n);
    if(n==1)
    {
      p=L.head->next;
      while(p!=L.tail)
     {
        printf("%d ",p->x);
        p=p->next;
     }
     return;
    }
    if(n==2)
    {
        p=L.tail->prior;
        while(p!=L.head)
        {
            printf("%d ",p->x);
            p=p->prior;
        }
        return;
    }

}
int main()
{
    int s;
    linklist L;
    creatlist(&L);
    s=maininterface();
    switch(s)
    {
        case 1:insertlist(&L);outputlist(L);break;
        case 2:deletelist(&L);outputlist(L);break;
        case 3:getlist(L);break;
        case 4:outputlist(L);break;
        case 0:exit(0);
        default:printf("\n\n\n\n\t\t\t\t\t\t��������!\n");exit(0);
    }
    return 0;
}
