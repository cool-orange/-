#include<stdio.h>
#include"first assignment_sequence.c"
int main()
{
    int i,temp;
    seq La,Lb,Lc;
    initlist(&La);
    initlist(&Lb);
    printf("请输入两顺序表的长度\n");
    scanf("%d%d",&La.length,&Lb.length);
    printf("请输入第一个顺序表的各个元素\n");
    for(i=0;i<La.length;i++)
    {
        scanf("%d",&temp);
        listinsert(&La,i,temp);
    }
    printf("请输入第二个顺序表的各个元素\n");
    for(i=0;i<Lb.length;i++)
    {
        scanf("%d",&temp);
        listinsert(&Lb,i,temp);
    }
    mergelist(&La,&Lb,&Lc);
    putlist(&Lc);
}
