/*#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct node
{
    int x;
    struct node *next;
}Node;
int maininterface()
{
    int n;
    printf("\t\t\t\t\t\t|--------------------------|\n");
	printf("\t\t\t\t\t\t|        1.插入节点        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        2.删除节点        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        3.查找结点        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        4.输出循环链表    |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.退出程序        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
Node* creathead()
{
    Node *head;
    head=(Node *)malloc(sizeof(struct node));
    head->next=head;
    if(head!=NULL)
        return head;
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
void creatlist(Node *head,int n)
{
    int i;
    Node *tail,*q;
    tail=head;
    for(i=0;i<n;i++)
    {
        q=(Node*)malloc(sizeof(Node));
        scanf("%d",&q->x);
        q->next=head;
        tail->next=q;
        tail=q;
    }
    return ;
}
void insertlist(Node*head)
{
    int pos,length,m,i=0;
    Node*p,*q;
    p=head;
    printf("请输入插在第几个位置前和插入元素:\n");
    scanf("%d %d",&pos,&m);
    length=lengthlist(head);
    if(pos<0||pos>length+1)
    {
        printf("输入有误!");
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
    p->next=q;
    return;
}
void deletelist(Node *head)
{
    int n,i=0,m;
    Node *p,*q;
    printf("<1>删除元素<2>删除位置对应元素\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("请输入删除元素\n");
        scanf("%d",&m);
        p=head->next;
        if(m==p->x)
        {
            head->next=p->next;
            free(p);
            return;
        }
        else
        {
         while(p!=head)
         {
             q=p->next;
             if(q->x==m)
            {
              p->next=q->next;
              free(q);
              break;
            }
          else
            p=p->next;
         }
      }
    }
    if(n==2)
    {
        printf("请输入删除位置\n");
        scanf("%d",&m);
        p=head;
        for(i=1;i<m;i++)
           p=p->next;
        q=p->next;
        p->next=q->next;
        free(q);
        return;
    }

}
void getlist(Node *head)
{
    Node *p;
    int m,n,i=1,j;
    printf("<1>输入查找的元素得到位置<2>输入位置得到查找元素\n");
    scanf("%d",&m);
    if(m==1)
    {
        printf("请输入查找元素\n");
        scanf("%d",&n);
        p=head->next;
        while(p!=head)
        {
            if(p->x==n)
            {
                printf("该元素位于链表第%d个位置\n",i);
                break;
            }
            else
            p=p->next;
            i++;
        }
    }
    if(m==2)
    {
        printf("请输入位置\n");
        scanf("%d",&n);
        p=head->next;
        for(j=1;j<n;j++)
          p=p->next;
        printf("该位置对应的元素为%d",p->x);
    }
    return;
}
void outputlist(Node *head)
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
    int n,s;
    Node*head;
    head=creathead();
    printf("请输入节点个数:\n");
    scanf("%d",&n);
    creatlist(head,n);
    s=maininterface();
    switch(s)
    {
        case 1:insertlist(head);outputlist(head);break;
        case 2:deletelist(head);outputlist(head);break;
        case 3:getlist(head);break;
        case 4:outputlist(head);break;
        case 0:exit(0);
        default:printf("\n\n\n\n\t\t\t\t\t\t输入有误!\n");exit(0);
    }
}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int x;
    struct node *next;
}Node;
Node* creathead()
{
    Node *head;
    head=(Node *)malloc(sizeof(struct node));//约瑟环问题
    head->next=head;
    head->x=1;
    if(head!=NULL)
        return head;
}
void creatlist(Node *head,int n)
{
    int i,j=2;
    Node *tail,*q;
    tail=head;
    for(i=1;i<n;i++)
    {
        q=(Node*)malloc(sizeof(Node));
        q->x=j;
        q->next=head;
        tail->next=q;
        tail=q;
        j++;
    }
    return ;
}
void josph(Node*head,int n,int m,int q)
{
    Node*p,*s;
    int i,j=0,amount;
    int a[30];
    amount=n;
    memset(a,30*sizeof(int),0);
    p=head;
    for(i=0;i<q-1;i++)
        p=p->next;
    while(n>0)
    {
        for(i=1;i<m-1;i++)
            p=p->next;
        s=p->next;
        p->next=s->next;
        a[j]=s->x;
        j++;
        free(s);
        n--;
        p=p->next;
    }
    for(i=0;i<amount;i++)
        printf("%d ",a[i]);
    return ;
}
void outputlist(Node *head)
{
    Node *p;
    p=head;
    printf("%d ",head->x);
    p=p->next;
    while(p!=head)
    {
        printf("%d ",p->x);
        p=p->next;
    }
    return;
}
int main()
{
    int n,m,q;
    Node*head;
    head=creathead();
    scanf("%d %d %d",&n,&m,&q);
    creatlist(head,n);
    josph(head,n,m,q);
}
