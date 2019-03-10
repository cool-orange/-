#include<stdio.h>
#include<stdlib.h>
#define max 100
#define LISTINCREMENT 10
typedef struct sequence
{
    int *data;
    int length;
}seq;
//顺序表的初始化
void initlist(seq *L)
{
    L->data=(int *)malloc(max*sizeof(int));
    if(L->data==NULL)
    {
        printf("当前空间不足\n");
        exit(0);
    }
    else
        L->length=0;
}
//插入元素
void listinsert(seq *L,int location,int temp)
{
    int i;
    int *newbase;
    int *p;
    p=L->data;
    if(location>L->length||location<0)
        printf("此位置不存在");
    if(L->length>max)
    {
        newbase=(int *)realloc(L->data,(max+LISTINCREMENT)*sizeof(int));
        if(newbase==NULL)
        {
            printf("重新开辟空间失败");
            exit(0);
        }
    }
    if(location==L->length)
        *(p+location)=temp;//L->data[location]=temp;
    else
    {
        for(i=L->length;i>=location;i--)
            *(p+i+1)=*(p+i);//L->data[i+1]=L->data[i];
        *(p+location)=temp;//L->data[location]=temp;
    }
}
//删除位置或元素
void listdelete(seq *L,int temp)
{
    int i,j;
    int *p;
    p=L->data;
    char choice2;
    printf("请输入您所删除的对象类型：a.输入元素，删除顺序表中的此元素 b.输入位置，删除顺序表中此位置对应的元素\n");
    scanf("\n%c",&choice2);
    if(choice2=='a')
    {
        for(i=0;i<L->length;i++)
        {
            if(*(p+i)==temp)    //if(L->data[i]==temp)
            {
                for(j=i;j<L->length-1;j++)
                    *(p+j)=*(p+j+1);      //L->data[j]=L->data[j+1];
                break;
            }
        }
    }
    else
    {
        for(i=temp;i<L->length;i++)
            *(p+i)=*(p+i+1);
    }
}
//查找位置或元素
void finding(seq *L,int temp)
{
    int i;
    int *p;
    p=L->data;
    char choice2;
    printf("请输入您所查找的对象类型：a.输入元素，查找此元素所在的位置 b.输入位置，查找此位置所含的元素\n");
    scanf("\n%c",&choice2);
    if(choice2=='a')
    {
        for(i=0;i<L->length;i++)
            if(*(p+i)==temp)//if(L->data[i]==temp)
            {
                printf("所查找元素对应的位置为%d",i);
                break;
            }
    }
    else
        printf("所查找位置的元素为%d",*(p+temp));//printf("所查找位置的元素为%d",L->data[temp]);
}
//输出顺序表
void putlist(seq *L)
{
    int i;
    int *p;
    p=L->data;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",*(p+i));//printf("%d ",L->data[i]);
    }
}
//实现两个顺序表的合并
void mergelist(seq *La,seq *Lb,seq *Lc)
{
    int i,j;
    int *pa,*pb,*pc;
    pa=La->data;
    pb=Lb->data;
    Lc->length=La->length+Lb->length;
    Lc->data=(int*)malloc(Lc->length*sizeof(int));
    pc=Lc->data;
    for(i=0;i<La->length;i++)
        *(pc+i)=*(pa+i);
    for(j=0;j<Lb->length;j++,i++)
        *(pc+i)=*(pb+j);
}
/*int main()
{
    int i,temp,choice,location;
    seq L;
    initlist(&L);
    printf("请输入当前顺序表的长度\n");
    scanf("%d",&L.length);
    printf("请依次输入当前顺序表的各个元素\n");
    for(i=0;i<L.length;i++)
    {
        scanf("%d",&temp);
        listinsert(&L,i,temp);
    }
    printf("请选择对此顺序表的操作：1.插入 2.删除 3.查找\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("请输入需要插入的位置和元素\n");scanf("%d %d",&location,&temp);listinsert(&L,location,temp);L.length++;break;
        case 2:printf("请输入需要删除的元素或位置\n");scanf("%d",&temp);listdelete(&L,temp);L.length--;break;
        case 3:printf("请输入所查找的元素或位置\n");scanf("%d",&temp);finding(&L,temp);exit(0);
    }
    putlist(&L);
    return 0;
}*/














