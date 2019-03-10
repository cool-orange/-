#include<stdio.h>
#include<stdlib.h>
#define max 100
#define LISTINCREMENT 10
typedef struct sequence
{
    int *data;
    int length;
}seq;
//˳���ĳ�ʼ��
void initlist(seq *L)
{
    L->data=(int *)malloc(max*sizeof(int));
    if(L->data==NULL)
    {
        printf("��ǰ�ռ䲻��\n");
        exit(0);
    }
    else
        L->length=0;
}
//����Ԫ��
void listinsert(seq *L,int location,int temp)
{
    int i;
    int *newbase;
    int *p;
    p=L->data;
    if(location>L->length||location<0)
        printf("��λ�ò�����");
    if(L->length>max)
    {
        newbase=(int *)realloc(L->data,(max+LISTINCREMENT)*sizeof(int));
        if(newbase==NULL)
        {
            printf("���¿��ٿռ�ʧ��");
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
//ɾ��λ�û�Ԫ��
void listdelete(seq *L,int temp)
{
    int i,j;
    int *p;
    p=L->data;
    char choice2;
    printf("����������ɾ���Ķ������ͣ�a.����Ԫ�أ�ɾ��˳����еĴ�Ԫ�� b.����λ�ã�ɾ��˳����д�λ�ö�Ӧ��Ԫ��\n");
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
//����λ�û�Ԫ��
void finding(seq *L,int temp)
{
    int i;
    int *p;
    p=L->data;
    char choice2;
    printf("�������������ҵĶ������ͣ�a.����Ԫ�أ����Ҵ�Ԫ�����ڵ�λ�� b.����λ�ã����Ҵ�λ��������Ԫ��\n");
    scanf("\n%c",&choice2);
    if(choice2=='a')
    {
        for(i=0;i<L->length;i++)
            if(*(p+i)==temp)//if(L->data[i]==temp)
            {
                printf("������Ԫ�ض�Ӧ��λ��Ϊ%d",i);
                break;
            }
    }
    else
        printf("������λ�õ�Ԫ��Ϊ%d",*(p+temp));//printf("������λ�õ�Ԫ��Ϊ%d",L->data[temp]);
}
//���˳���
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
//ʵ������˳���ĺϲ�
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
    printf("�����뵱ǰ˳���ĳ���\n");
    scanf("%d",&L.length);
    printf("���������뵱ǰ˳���ĸ���Ԫ��\n");
    for(i=0;i<L.length;i++)
    {
        scanf("%d",&temp);
        listinsert(&L,i,temp);
    }
    printf("��ѡ��Դ�˳���Ĳ�����1.���� 2.ɾ�� 3.����\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("��������Ҫ�����λ�ú�Ԫ��\n");scanf("%d %d",&location,&temp);listinsert(&L,location,temp);L.length++;break;
        case 2:printf("��������Ҫɾ����Ԫ�ػ�λ��\n");scanf("%d",&temp);listdelete(&L,temp);L.length--;break;
        case 3:printf("�����������ҵ�Ԫ�ػ�λ��\n");scanf("%d",&temp);finding(&L,temp);exit(0);
    }
    putlist(&L);
    return 0;
}*/














