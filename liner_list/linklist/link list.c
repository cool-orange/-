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
	printf("\t\t\t\t\t\t|        1.插入节点        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        2.删除节点        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        3.查找结点        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        4.输出顺序表      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.退出程序        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
void headcreatlist(Node *head)//头插法创建链表
{
    int n,i;
    Node *p,*q;
    printf("输入节点个数:\n");
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
void tailcreatlist(Node *head)//尾插法创建链表
{
    int n,i;
    Node *p,*q;
    printf("输入节点个数:\n");
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
void linkinsert(Node *head)//插入pos位置前
{
    int pos,m,i=1;
    printf("请输入插入位置和值\n");
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
    printf("<1>插入表头 <2>插入表尾 <3>插入表中\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:inserthead(head);output(head);break;
        case 2:inserttail(head);output(head);break;
        case 3:linkinsert(head);output(head);break;
        default:printf("输入有误！");break;
    }
}
void deletelist(Node *head)//删除节点
{
    int n,i=0,m;
    Node *p,*q;
    printf("<1>删除元素<2>删除位置对应元素\n");
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

        /*printf("请输入删除元素\n");
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
        printf("请输入删除位置\n");
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
void getlist(Node*head)//查找节点
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
        while(p!=NULL)
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
        p=head;
        for(j=1;j<n;j++)
        p=p->next;
        printf("该位置对应的元素为%d",p->x);
    }
    return;
}
int main()
{
    int n,m,pos,s;
    Node *head;
    head=creathead();
    printf("<1>头插法创建链表 <2>尾插法创建链表>\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: headcreatlist(head);output(head);break;
        case 2: tailcreatlist(head);output(head);break;
        default:printf("\n\n\n\n\t\t\t\t\t\t输入有误!\n");exit(0);
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
        default:printf("\n\n\n\n\t\t\t\t\t\t输入有误!\n");exit(0);
    }
    return 0;
}



/*#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int exp;//指数
    int coef;//系数
    struct node *next;
}Node;
Node* creathead()
{
    Node *head;
    head=(Node *)malloc(sizeof(struct node));//一元多项式求和
    head->next=NULL;
    if(head!=NULL)
        return head;
}
void creatlist(Node *head)
{
    int n,i;
    Node *p,*q;
    printf("输入节点个数:\n");
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
