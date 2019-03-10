//一元多项式的相加减
#include<stdio.h>
#include<stdlib.h>
#include"single-linklist application.h"
int main()
{
    int m,n;
    LNode *L1,*L2,*L3,*p1,*p2,*p3,*p;
    L1=createhead();
    L2=createhead();
    L3=createhead();
    printf("请依次输入两多项式的项数\n");
    scanf("%d%d",&m,&n);
    tailinsert(L1,m);
    tailinsert(L2,n);
    p1=L1->next;
    p2=L2->next;
    p3=L3;
    while(p1&&p2)
    {
        if(p1->index>p2->index)
        {
            p=(LNode *)malloc(sizeof(LNode));
            p->coef=p1->coef;
            p->index=p1->index;
            p->next=p3->next;
            p3->next=p;
            p1=p1->next;
        }
        else if(p1->index<p2->index)
        {
            p=(LNode *)malloc(sizeof(LNode));
            p->coef=p2->coef;
            p->index=p2->index;
            p->next=p3->next;
            p3->next=p;
            p2=p2->next;
        }
        else
        {
            p=(LNode *)malloc(sizeof(LNode));
            p->coef=p1->coef+p2->coef;
            p->index=p1->index;
            p->next=p3->next;
            p3->next=p;
            p1=p1->next;
            p2=p2->next;
        }

    }
    if(p1==NULL)
    {
        while(p2)
        {
            p=(LNode *)malloc(sizeof(LNode));
            p->coef=p2->coef;
            p->index=p2->index;
            p->next=p3->next;
            p3->next=p;
            p2=p2->next;
        }
    }
    else
    {
        while(p1)
        {
            p=(LNode *)malloc(sizeof(LNode));
            p->coef=p1->coef;
            p->index=p1->index;
            p->next=p3->next;
            p3->next=p;
            p1=p1->next;
        }
    }
    putlist(L3);
}
