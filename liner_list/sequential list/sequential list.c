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
	printf("\t\t\t\t\t\t|        1.����ڵ�        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        2.ɾ���ڵ�        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        3.���ҽ��        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        4.����˳���      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        5.���˳���      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        6.���˳���      |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.�˳�����        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
void againmalloc(sqlist *L)//�ռ���䲻��������
{
    int *elemsecond;
    elemsecond=(int *)realloc(L->elem,(L->listsize+listincrement)*sizeof(int));
    if(!elemsecond)
    {
        printf("�ռ���䲻��!");
        exit(0);
    }
    L->elem=elemsecond;
    L->listsize+=listincrement;
    return;
}
int initlist(sqlist *L)//��ʼ��
{
    L->elem=(int*)malloc(list_init_size*sizeof(int));
    if(!L->elem)
    {
        printf("�ռ����");
        exit(0);
    }
    L->length=0;
    L->listsize=list_init_size;
    return 0;
}
void insertfirst(sqlist *L,int a)//�ӱ�ͷ����
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
int insertlast(sqlist *L,int a)//���β����
{
    if(L->length>=L->listsize)
        againmalloc(L);
    L->elem[L->length]=a;
    L->length++;
    return 0;
}
int insertmid(sqlist *L,int a,int pos)//���ڼ���λ�ú����
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
int outputlist(sqlist *L)//������Ա�
{
    int i;
    for(i=0;i<L->length;i++)
        printf("%d ",L->elem[i]);
    return 0;
}
void incrementlist(sqlist *L)//����ڵ�
{
    int n,a,pos;
    scanf("%d",&n);
    switch(n)
    {
        case 1:printf("\n\t\t\t\t\t1:<��ͷ����>\n");scanf("%d",&a);insertfirst(L,a);outputlist(L);break;
        case 2:printf("\n\t\t\t\t\t1:<��β����>\n");scanf("%d",&a);insertlast(L,a);outputlist(L);break;
        case 3:printf("\n\t\t\t\t\t1:<���ڼ���λ�ú����>\n");scanf("%d %d",&a,&pos);insertmid(L,a,pos);outputlist(L);break;
    }
}
int  deletelist(sqlist *L,int pos)//ɾ���ڵ�
{
    int i;
    if(pos<1||pos>L->length)
        return 0;
    for(i=pos;i<L->length;i++)
        L->elem[i-1]=L->elem[i];
    L->length--;
    return 0;
}
void getlist(sqlist *L,int m)//���ҽڵ�λ��
{
    int i,pos=1;
    for(i=0;i<L->length;i++)
    {
        if(m!=L->elem[i])
        {
            pos++;
        }
        else
            printf("%d��˳���ĵ�%d��λ��",m,pos);
    }
}
void destroylist(sqlist *L)//�������Ա�
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
void clearlist(sqlist *L)//������Ա�
{
    L->length=0;
}
int main()
{
    sqlist L;
    int m,n,i,length,temp;
    initlist(&L);
    printf("������˳���ĳ���:\n");
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
        case 1:printf("\n\t\t\t\t\t1:<����ڵ�>\n");incrementlist(&L);break;
        case 2:printf("\n\t\t\t\t\t1:<ɾ���ڵ�>\n");scanf("%d",&m);deletelist(&L,m);outputlist(&L);break;
        case 3:printf("\n\t\t\t\t\t1:<���ҽ��>\n");scanf("%d",&m);getlist(&L,m);break;
        case 4:destroylist(&L);break;
        case 5:clearlist(&L);break;
        case 6:outputlist(&L);break;
        case 0:exit(0);
        default:printf("\n\n\n\n\t\t\t\t\t\t��������!\n");getch();system("cls");break;
    }
    return 0;
}


