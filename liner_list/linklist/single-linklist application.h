//������һԪ����ʽ��Ӽ�
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int coef;//ϵ��
    int index;//ָ��
    struct LNode *next;
}LNode;
//����ͷ���
LNode *createhead()       //���ѡ��void���͵ĺ�������Ӧ���ݶ���ָ��
{
    LNode *head;
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    return head;
}
/*//ͷ�巨��������
void headinsert(LNode *head,int n)
{
    int i,temp;
    LNode *p,*s;
    s=head;
    printf("���������������������Ԫ��\n");
    for(i=n;i>0;i--)
    {
        p=(LNode *)malloc(sizeof(LNode));
        scanf("%d",&temp);
        p->data=temp;
        p->next=s->next;
        s->next=p;
    }
}*/
//β�巨��������
void tailinsert(LNode *head,int n)
{
    int i,temp1,temp2;
    LNode *p,*s;
    s=head;
    printf("���������������������Ԫ��,��һ����ʾϵ�����ڶ�����ʾָ��\n");
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
/*//�������в���һ��Ԫ��
void listinsert(LNode *L,int i,int e,int n)
{
    LNode *p,*s;
    int j;
    p=(LNode *)malloc(sizeof(LNode));
    p->data=e;
    s=L;
    if(i>n||i<0)
    {
        printf("�����λ�ò�����\n");
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

/*//ɾ��ĳԪ��
void listdelete_element(LNode *L,int e)
{
    LNode *p,*s;
    for(p=L->next,s=L;p->data!=e;p=p->next,s=s->next)
    {

        if(p->next==NULL)
        {
            printf("�������в����ڴ�Ԫ��\n");
            exit(0);
        }
    }
    s->next=p->next;
    free(p);
}*/
/*//ɾ��ĳλ�õ�Ԫ��
void listdelete_position(LNode *L,int pos)
{
    int i;
    LNode *p,*s;
    p=L->next;
    s=L;
    if(pos<=0)
    {
        printf("�������в����ڴ�λ��\n");
        exit(0);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            if(p->next==NULL)
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
    s->next=p->next;
    free(p);
}*/
/*//����ĳԪ������λ��
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
        printf("��Ԫ�ز�����\n");
        exit(0);
    }
    return i;
}*/
/*//����ĳλ�ö�Ӧ��Ԫ��
int finding_position(LNode *L,int pos)
{
    int i;
    LNode *p;
    p=L;
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
        if(p==NULL)
        {
            printf("��λ�ò�����\n");
            exit(0);
        }
    }
    return p->data;
}*/
//��������и���������
void putlist(LNode *L)
{
    LNode *p;
    for(p=L->next;p!=NULL;p=p->next)
        printf("%d %d\n",p->coef,p->index);
}
