//����ת��
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"D:\�μ�\��һ��\רҵ��\own library\sequence-stack operation.h"
//ʮ����ת��Ϊ��������
void tentoother(SqStack S)
{
    int n,a;
    printf("������Ŀ�����\n");
    scanf("%d",&n);
    printf("����������ԭʼ����\n");
    scanf("%d",&a);
    while(a)
    {
        Push(&S,a%n);
        a=a/n;
    }
    while(StackEmpty(S))
    {
        Pop(&S,S.top);
        printf("%d ",*(S.top));
    }
}
//��������ת��Ϊʮ����
void othertoten(SqStack S)
{
    int n,sum=0,i=0;
    char c,b='0';
    printf("�����뵱ǰ����\n");
    scanf("%d",&n);
    printf("����������ԭʼ����\n");
    c=getchar();
    while(b!='\n')
    {
        b=getchar();
        Push(&S,b);
    }
    Pop(&S,S.top);
    while(StackEmpty(S))
    {
        Pop(&S,S.top);
        b=*(S.top);
        if(b>='0'&&b<='9')
        {
            sum+=(b-48)*pow(n,i);
            i++;
        }
        else
        {
            sum+=(b-'A'+10)*pow(n,i);
            i++;
        }
    }
    printf("ת��Ϊʮ����Ϊ%d",sum);
}
//������ת��Ϊ�˽��ƻ�ʮ������
void twotoother(SqStack S,SqStack L)
{
    int n,m,sum,i;
    char b='0',c;
    printf("������Ŀ�����\n");
    scanf("%d",&n);
    if(n=8)
        m=3;
    else
        m=4;
    printf("����������ԭʼ����\n");
    c=getchar();
    while(b!='\n')
    {
        b=getchar();
        Push(&S,b);
    }
    Pop(&S,S.top);
    while(S.top!=S.base)
    {
        i=0,sum=0;
        while((i<m)&&(S.top!=S.base))
        {
            Pop(&S,S.top);
            b=*(S.top);
            sum+=(b-48)*pow(2,i);
            i++;
        }
        Push(&L,sum);
    }
    while(L.top!=L.base)
    {
        Pop(&L,&sum);
        if(sum>=10)
        {
            b=sum+55;
            printf("%c",b);
        }
        else
            printf("%d",sum);
    }
}
int main()
{
    int choice1,n,a,t,sum=0,i=0,m;
    char b='0',c;
    SqStack S,L;
    InitStack(&S);
    InitStack(&L);
    printf("��ѡ�����ת���ķ�ʽ��1.ʮ����ת��Ϊ�������� 2.��������ת��Ϊʮ���� 3.������ת�˽��ƻ�ʮ������ 4.�˽��ƻ�ʮ������ת������\n");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:tentoother(S);break;
        case 2:othertoten(S);break;
        case 3:twotoother(S,L);break;
    }
    return 0;
}

















