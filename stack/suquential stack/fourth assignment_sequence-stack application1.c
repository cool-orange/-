//进制转换
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"D:\课件\大一下\专业课\own library\sequence-stack operation.h"
//十进制转换为其他进制
void tentoother(SqStack S)
{
    int n,a;
    printf("请输入目标进制\n");
    scanf("%d",&n);
    printf("请输入您的原始数字\n");
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
//其他进制转换为十进制
void othertoten(SqStack S)
{
    int n,sum=0,i=0;
    char c,b='0';
    printf("请输入当前进制\n");
    scanf("%d",&n);
    printf("请输入您的原始数字\n");
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
    printf("转化为十进制为%d",sum);
}
//二进制转换为八进制或十六进制
void twotoother(SqStack S,SqStack L)
{
    int n,m,sum,i;
    char b='0',c;
    printf("请输入目标进制\n");
    scanf("%d",&n);
    if(n=8)
        m=3;
    else
        m=4;
    printf("请输入您的原始数字\n");
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
    printf("请选择进制转换的方式：1.十进制转换为其他进制 2.其他进制转换为十进制 3.二进制转八进制或十六进制 4.八进制或十六进制转二进制\n");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:tentoother(S);break;
        case 2:othertoten(S);break;
        case 3:twotoother(S,L);break;
    }
    return 0;
}

















