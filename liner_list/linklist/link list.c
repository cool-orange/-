#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<malloc.h>
typedef struct node
{
    int x;
    struct node*next;
}Node;
Node* creathead()
{
    Node *head;
    head=(Node *)malloc(sizeof(struct node));
    head->next=NULL;
    if(head!=NULL)
        return head;
}
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
    printf("\t\t\t\t\t\t|        4.���˳���      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.�˳�����        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
void headcreatlist(Node *head)//ͷ�巨��������
{
    int n,i;
    Node *p,*q;
    printf("����ڵ����:\n");
    scanf("%d",&n);
    p=head;
    for(i=0;i<n;i++)
    {
        q=(Node*)malloc(sizeof(Node));
        scanf("%d",&q->x);
        q->next=p->next;
        p->next=q;
    }
    return ;
}
void tailcreatlist(Node *head)//β�巨��������
{
    int n,i;
    Node *p,*q;
    printf("����ڵ����:\n");
    scanf("%d",&n);
    p=head;
    for(i=0;i<n;i++)
    {
        q=(Node*)malloc(sizeof(Node));
        scanf("%d",&q->x);
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return;
}
void output(Node *head)
{
    Node *p;
    p=head->next;
    while(p!=NULL)
    {
        printf("%d ",p->x);
        p=p->next;
    }
    return ;
}
int lengthlist(Node *head)
{
    int i=0;
    Node *p;
    p=head->next;
    while(p!=NULL)
    {
        i++;
    }
    return i;
}
void Emptylist(Node *head)
{
    if(head->next)
        printf("list is empty");
    else
      return;
}
void inserthead(Node *head)
{
    Node *p;
    p=(Node*)malloc(sizeof(struct node));
    scanf("%d",&p->x);
    p->next=head->next;
    head->next=p;
}
void inserttail(Node *head)
{
    Node *p,*q;
    p=(Node*)malloc(sizeof(struct node));
    scanf("%d",&p->x);
    q=head->next;
    while(q!=NULL)
    {
        if(q->next==NULL)
        {
            q->next=p;
            p->next=NULL;
        }
        q=q->next;
    }
}
void linkinsert(Node *head)//����posλ��ǰ
{
    int pos,m,i=1;
    printf("���������λ�ú�ֵ\n");
    scanf("%d %d",&pos,&m);
    Node*p,*q;
    p=(Node*)malloc(sizeof(Node));
    p->x=m;
    q=head->next;
    while(q&&i<pos-1)
    {
        q=q->next;
        i++;
    }
    if(!q||i>pos-1)
        return ;
    p->next=q->next;
    q->next=p;
    return;
}
void insertlist(Node*head)
{
    int n;
    printf("\n");
    printf("<1>�����ͷ <2>�����β <3>�������\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:inserthead(head);output(head);break;
        case 2:inserttail(head);output(head);break;
        case 3:linkinsert(head);output(head);break;
        default:printf("��������");break;
    }
}
void deletelist(Node *head)//ɾ���ڵ�
{
    int n,i=0,m;
    Node *p,*q;
    printf("<1>ɾ��Ԫ��<2>ɾ��λ�ö�ӦԪ��\n");
    scanf("%d",&n);
    if(n==1)
    {
        Node *pre=head;
        p=pre->next;
        Node* minpre=pre,*minp=p;
        while(p!=NULL)
        {
            if(p->x<minp->x)
            {
                minp=p;
                minpre=pre;
            }
            pre=pre->next;
            p=p->next;

        }
        minpre->next=minp->next;
        free(minp);

        /*printf("������ɾ��Ԫ��\n");
        scanf("%d",&m);
        p=head;
        while(p!=NULL)
        {
            q=p->next;
            if(q->x==m)
           {
             p->next=q->next;
             free(q);
             break;
           }
          else
            p=p->next;*/
    }
    if(n==2)
    {
        printf("������ɾ��λ��\n");
        scanf("%d",&m);
        p=head;
        for(i=1;i<m;i++)
           p=p->next;
        q=p->next;
        p->next=q->next;
        free(q);
    }
    return;
}
void getlist(Node*head)//���ҽڵ�
{
    Node *p;
    int m,n,i=1,j;
    printf("<1>������ҵ�Ԫ�صõ�λ��<2>����λ�õõ�����Ԫ��\n");
    scanf("%d",&m);
    if(m==1)
    {
        printf("���������Ԫ��\n");
        scanf("%d",&n);
        p=head->next;
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
        p=head;
        for(j=1;j<n;j++)
        p=p->next;
        printf("��λ�ö�Ӧ��Ԫ��Ϊ%d",p->x);
    }
    return;
}
int main()
{
    int n,m,pos,s;
    Node *head;
    head=creathead();
    printf("<1>ͷ�巨�������� <2>β�巨��������>\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: headcreatlist(head);output(head);break;
        case 2: tailcreatlist(head);output(head);break;
        default:printf("\n\n\n\n\t\t\t\t\t\t��������!\n");exit(0);
    }
    system("cls");
    s=maininterface();
    switch(s)
    {
        case 1:insertlist(head);break;
        case 2:deletelist(head);output(head);break;
        case 3:getlist(head);break;
        case 4:output(head);break;
        case 0:exit(0);
        default:printf("\n\n\n\n\t\t\t\t\t\t��������!\n");exit(0);
    }
    return 0;
}



/*#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int exp;//ָ��
    int coef;//ϵ��
    struct node *next;
}Node;
Node* creathead()
{
    Node *head;
    head=(Node *)malloc(sizeof(struct node));//һԪ����ʽ���
    head->next=NULL;
    if(head!=NULL)
        return head;
}
void creatlist(Node *head)
{
    int n,i;
    Node *p,*q;
    printf("����ڵ����:\n");
    scanf("%d",&n);
    p=head;
    for(i=0;i<n;i++)
    {
        q=(Node*)malloc(sizeof(Node));
        scanf("%d %d",&q->coef,&q->exp);
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return;;
}
void outputlist(Node *head)
{
    Node *p;
    p=head->next;
    if(p==NULL)
        printf("0");
    while(p!=NULL)
    {
        printf("%d %d ",p->coef,p->exp);
        p=p->next;
    }
    return ;
}
void addpoly(Node *headone,Node *headtwo,Node *headthree)
{
    Node *p,*q,*s,*m,*temp;
    p=headone->next;
    q=headtwo->next;
    s=headthree;
    while(p&&q)
    {
        if(p->exp<q->exp)
        {
            m=(Node*)malloc(sizeof(Node));
            m->exp=p->exp,m->coef=p->coef;
            s->next=m;
            s=m;
            p=p->next;
        }
        else if(p->exp>q->exp)
        {
            m=(Node*)malloc(sizeof(Node));
            m->exp=q->exp,m->coef=q->coef;
            s->next=m;
            s=m;
            q=q->next;
        }
        else
        {
           if(p->coef+q->coef!=0)
           {
               m=(Node*)malloc(sizeof(Node));
               m->exp=q->exp,m->coef=p->coef+q->coef;
               s->next=m;
               s=m;
               p=p->next;
               q=q->next;
           }
           else
           {
               p=p->next;
               q=q->next;
           }

        }
    }
     if(p!=NULL)
            temp=p;
     else
            temp=q;
    while(temp!=NULL)
    {
        m=(Node*)malloc(sizeof(Node));
        m->exp=temp->exp;
        m->coef=temp->coef;
        s->next=m;
        s=m;
        temp=temp->next;
    }
    s->next=NULL;
    outputlist(headthree);
    return;
}
int main()
{
    Node*onehead,*twohead,*threehead;
    onehead=creathead();
    twohead=creathead();
    threehead=creathead();
    creatlist(onehead);
    creatlist(twohead);
    addpoly(onehead,twohead,threehead);
    return 0;
}*/
