#include<stdio.h>
#include"first assignment_sequence.c"
int main()
{
    int i,temp;
    seq La,Lb,Lc;
    initlist(&La);
    initlist(&Lb);
    printf("��������˳���ĳ���\n");
    scanf("%d%d",&La.length,&Lb.length);
    printf("�������һ��˳���ĸ���Ԫ��\n");
    for(i=0;i<La.length;i++)
    {
        scanf("%d",&temp);
        listinsert(&La,i,temp);
    }
    printf("������ڶ���˳���ĸ���Ԫ��\n");
    for(i=0;i<Lb.length;i++)
    {
        scanf("%d",&temp);
        listinsert(&Lb,i,temp);
    }
    mergelist(&La,&Lb,&Lc);
    putlist(&Lc);
}
