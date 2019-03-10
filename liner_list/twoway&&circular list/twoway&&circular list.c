#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x;
    struct node*prior;
    struct node*next;
}Node;
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
    printf("\t\t\t\t\t\t|        4.���˫��ѭ������|\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.�˳�����        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
int lengthlist(Node *head)
{
    Node*p;
    int i=0;
    p=head->next;
    while(p!=head)
    {
        i++;
        p=p->next;
    }
    return i;
}
void creatlist(Node *head)
{
    int i,n;
    Node *p,*q;
    printf("������ڵ����:\n");
    scanf("%d",&n);
    p=head;
    for(i=0;i<n;i++)
    {
        q=(Node*)malloc(sizeof(Node));
        scanf("%d",&q->x);
        q->next=head;
        q->prior=p;
        p->next=q;
        p=q;
    }
    return;
}
Node* initlist()
{
    Node *head;
    head=(Node*)malloc(sizeof(Node));
    head->next=head;
    head->prior=head;
    if(head!=NULL)
        return head;
}
void insertlist(Node *head)
{
    int pos,length,m,i=0;
    Node*p,*q;
    p=head;
    printf("��������ڵڼ���λ��ǰ�Ͳ���Ԫ��:\n");
    scanf("%d %d",&pos,&m);
    length=lengthlist(head);
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
    q->next=p->next;
    p->next->prior=q;
    q->prior=p;
    p->next=q;
    return;

}
void deletelist(Node* head)
{
    int n,i=0,m;
    Node *p,*q;
    printf("<1>ɾ��Ԫ��<2>ɾ��λ�ö�ӦԪ��\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("������ɾ��Ԫ��\n");
        scanf("%d",&m);
        p=head->next;
        if(p->x==m)
        {
            head->next=p->next;
            free(p);
            return;
        }
        while(p!=head)
        {
            q=p->next;
            if(q->x==m)
           {
             p->next=q->next;
             q->next->prior=p;
             free(q);
             break;
           }
          else
            p=p->next;
      }
      return;
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
        q->next->prior=p;
        free(q);
        return;
    }

}
void getlist(Node*head)
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
        while(p!=head)
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
        p=head->next;
        for(j=1;j<n;j++)
          p=p->next;
        printf("��λ�ö�Ӧ��Ԫ��Ϊ%d",p->x);
    }
    return;;
}
void outputlist(Node*head)
{
    Node *p;
    p=head->next;
    while(p!=head)
    {
        printf("%d ",p->x);
        p=p->next;
    }
    return;

}
int main()
{
    int s,n;
    Node *head;
    head=initlist();
    creatlist(head);
    s=maininterface();
    switch(s)
    {
        case 1:insertlist(head);outputlist(head);break;
        case 2:deletelist(head);outputlist(head);break;
        case 3:getlist(head);break;
        case 4:outputlist(head);break;
        case 0:exit(0);
        default:printf("\n\n\n\n\t\t\t\t\t\t��������!\n");exit(0);
    }
    return 0;
}
