#include<stdio.h>
#include<stdlib.h>
#include"single-circular linklist operation.h"
int main()
{
    int n,m,q,i;
    LNode *L,*p,*s;
    L=createhead();
    printf("请输入一个正整数n，表示小朋友的个数\n");
    scanf("%d",&n);
    tailinsert_application(L,n);
    p=L->next;
    s=L;
    //  putlists(L);
    printf("请输入开始报数的小朋友的编号m，以及输入一个正整数q，表示报数到q的同学出列\n");
    scanf("%d %d",&m,&q);
    for(i=1;i<m;i++)
    {
        p=p->next;
        s=s->next;
    }
    while(p!=p->next)
    {
        for(i=1;i<q;i++)
        {
            s=s->next;
            p=p->next;
        }
        s->next=p->next;
        printf("%d ",p->data);
        free(p);
        p=s->next;
    }
    printf("%d",p->data);
    return 0;
}
