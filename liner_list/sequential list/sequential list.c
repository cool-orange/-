#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#define list_init_size 100
#define listincrement 10

typedef struct
{
    int *elem;
    int length;
    int listsize;
}sqlist;
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
    printf("\t\t\t\t\t\t|        4.销毁顺序表      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        5.清空顺序表      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        6.输出顺序表      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.退出程序        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
void againmalloc(sqlist *L)//空间分配不够再申请
{
    int *elemsecond;
    elemsecond=(int *)realloc(L->elem,(L->listsize+listincrement)*sizeof(int));
    if(!elemsecond)
    {
        printf("空间分配不足!");
        exit(0);
    }
    L->elem=elemsecond;
    L->listsize+=listincrement;
    return;
}
int initlist(sqlist *L)//初始化
{
    L->elem=(int*)malloc(list_init_size*sizeof(int));
    if(!L->elem)
    {
        printf("空间分配");
        exit(0);
    }
    L->length=0;
    L->listsize=list_init_size;
    return 0;
}
void insertfirst(sqlist *L,int a)//从表头插入
{
    int i;
    if(L->length>=L->listsize)
        againmalloc(L);
    for(i=L->length-1;i>=0;i--)
        L->elem[i+1]=L->elem[i];
    L->elem[0]=a;
    L->length++;
    return ;
}
int insertlast(sqlist *L,int a)//向表尾插入
{
    if(L->length>=L->listsize)
        againmalloc(L);
    L->elem[L->length]=a;
    L->length++;
    return 0;
}
int insertmid(sqlist *L,int a,int pos)//向表第几个位置后插入
{
    int i;
    if(a<1||a>L->length)
        return 0;
    for(i=L->length-1;i>=a;i--)
        L->elem[i+1]=L->elem[i];
    L->elem[a]=pos;
    L->length++;
    return  0;
}
int outputlist(sqlist *L)//输出线性表
{
    int i;
    for(i=0;i<L->length;i++)
        printf("%d ",L->elem[i]);
    return 0;
}
void incrementlist(sqlist *L)//插入节点
{
    int n,a,pos;
    scanf("%d",&n);
    switch(n)
    {
        case 1:printf("\n\t\t\t\t\t1:<表头插入>\n");scanf("%d",&a);insertfirst(L,a);outputlist(L);break;
        case 2:printf("\n\t\t\t\t\t1:<表尾插入>\n");scanf("%d",&a);insertlast(L,a);outputlist(L);break;
        case 3:printf("\n\t\t\t\t\t1:<向表第几个位置后插入>\n");scanf("%d %d",&a,&pos);insertmid(L,a,pos);outputlist(L);break;
    }
}
int  deletelist(sqlist *L,int pos)//删除节点
{
    int i;
    if(pos<1||pos>L->length)
        return 0;
    for(i=pos;i<L->length;i++)
        L->elem[i-1]=L->elem[i];
    L->length--;
    return 0;
}
void getlist(sqlist *L,int m)//查找节点位置
{
    int i,pos=1;
    for(i=0;i<L->length;i++)
    {
        if(m!=L->elem[i])
        {
            pos++;
        }
        else
            printf("%d在顺序表的第%d个位置",m,pos);
    }
}
void destroylist(sqlist *L)//销毁线性表
{
    if(L->elem)
    {
        free(L->elem);
        L->elem=NULL;
        L->length=0;
        L->listsize=0;
    }
    return;
}
void clearlist(sqlist *L)//清空线性表
{
    L->length=0;
}
int main()
{
    sqlist L;
    int m,n,i,length,temp;
    initlist(&L);
    printf("请输入顺序表的长度:\n");
    scanf("%d",&length);
    for(i=0;i<length;i++)
    {
        scanf("%d",&temp);
        insertlast(&L,temp);
    }
    system("cls");
    n=maininterface();
    system("cls");
    switch(n)
    {
        case 1:printf("\n\t\t\t\t\t1:<插入节点>\n");incrementlist(&L);break;
        case 2:printf("\n\t\t\t\t\t1:<删除节点>\n");scanf("%d",&m);deletelist(&L,m);outputlist(&L);break;
        case 3:printf("\n\t\t\t\t\t1:<查找结点>\n");scanf("%d",&m);getlist(&L,m);break;
        case 4:destroylist(&L);break;
        case 5:clearlist(&L);break;
        case 6:outputlist(&L);break;
        case 0:exit(0);
        default:printf("\n\n\n\n\t\t\t\t\t\t输入有误!\n");getch();system("cls");break;
    }
    return 0;
}


