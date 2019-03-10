#include<stdio.h>
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
    head=(Node *)malloc(sizeof(struct node));
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
            m->exp=p->exp,m->coef=p->coef;//m->next=NULL;
            s->next=m;
            s=m;
            p=p->next;
        }
        else if(p->exp>q->exp)
        {
            m=(Node*)malloc(sizeof(Node));
            m->exp=q->exp,m->coef=q->coef;//m->next=NULL;
            s->next=m;
            s=m;
            q=q->next;
        }
        else
        {
           if(p->coef+q->coef!=0)
           {
               m=(Node*)malloc(sizeof(Node));
               m->exp=q->exp,m->coef=p->coef+q->coef;//m->next=NULL;
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
        //m->next=NULL;
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
}
/*void addpoly(Node **headone,Node **headtwo)
{
    Node *p,*q,*s,*m,*temp;
    p=(*headone)->next;
    q=(*headtwo)->next;
    s=*headone;
    m=*headtwo;
    while(p!=NULL&&q!=NULL)
    {
        if(p->exp<q->exp)
        {
            s=s->
            p=p->next;
            s=s->next;
        }
        else if(p->exp==q->exp)
        {
            if(p->coef+q->coef==0)
            {
                temp=p->next;s->next=p->next;free(p);p=temp;
                temp=q->next;m->next=q->next;free(q);q=temp;
            }
            else
            {
                p->coef+=q->coef;
                s->next=p;s=s->next;p=p->next;
                temp=q;m->next=q->next;q=q->next;free(temp);
            }
        }
        else
        {
            s->next=q;
            q=q->next;
            m=m->next;
        }
    }
    if(p!=NULL)
        s->next=p;
    else
        s->next=q;
}*/
