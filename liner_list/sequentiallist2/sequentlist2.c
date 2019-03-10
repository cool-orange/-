#include<stdio.h>
#include<stdlib.h>
#include "sequential list.h"
void pop(sqlist*L)
{
    int i,j,temp;
    for(i=0;i<L->length;i++)
    {
        for(j=i+1;j<=L->length;j++)
        {
            if(L->elem[i]>L->elem[j])
            {
                temp=L->elem[i];
                L->elem[i]=L->elem[j];
                L->elem[j]=temp;
            }
        }
    }

}
void mergelist (sqlist La,sqlist Lb,sqlist *Lc)
{
    int i=0,j=0,k=0;
    Lc->listsize=La.length+Lb.length;
    Lc->length=0;
    Lc->elem=(int *)malloc(Lc->listsize*sizeof(int));
    if(!Lc->elem)
        exit(0);
    while(i<La.length&&j<Lb.length)
    {
        if(La.elem[i]<=Lb.elem[j])
        {
            Lc->elem[k]=La.elem[i];
            i++;
            k++;
            Lc->length++;
        }
        else
        {
            Lc->elem[k]=Lb.elem[j];
            j++;
            k++;
            Lc->length++;
        }
    }
    while(i<La.length)
    {
        Lc->elem[k]=La.elem[i];
        k++;
        i++;
        Lc->length++;
    }
    while(j<Lb.length)
    {
        Lc->elem[k]=Lb.elem[j];
        k++;
        j++;
        Lc->length++;
    }
    return;
}
void list_intersection(sqlist La,sqlist Lb,sqlist*Lc)
{
    initlist(Lc);
    int i,j;
    for(i=0;i<La.length;i++)
    {
        for(j=0;j<Lb.length;j++)
        {
            if(La.elem[i]==Lb.elem[j])
            {
                Lc->elem[Lc->length]=La.elem[i];
                Lc->length++;
            }
        }
    }
    return ;
}

int main()
{
    int i,j;
    sqlist La,Lb,Lc;
    initlist(&La);
    initlist(&Lb);
    initlist(&Lc);
    printf("�����뼯��A�ĳ��ȣ�\n");
    scanf("%d",&La.length);
    printf("<Ԫ��>:\n");
    for(i=0;i<La.length;i++)
        scanf("%d",&La.elem[i]);
    pop(&La);
    printf("�����뼯��B�ĳ���:\n");
    scanf("%d",&Lb.length);
    printf("<Ԫ��>:\n");
    for(i=0;i<Lb.length;i++)
        scanf("%d",&Lb.elem[i]);
    pop(&Lb);
    printf("A��B�Ĳ�����\n");
    mergelist(La,Lb,&Lc);
    outputlist(&Lc);
    destroylist(&Lc);
    printf("\n");
    printf("A��B�Ľ�����\n");
    list_intersection(La,Lb,&Lc);
    outputlist(&Lc);
    return 0;
}
