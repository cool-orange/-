#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int data;
    struct LkStack *next;
}LkStack;
//����ջ�׽��
LkStack *InitStack()
{
    LkStack *top;
    top=(LkStack *)malloc(sizeof(LkStack));
    top->next=NULL;
    return top;
}
//����Ԫ�أ�ѹջ�����ȿ����ڴ�����ʽջ���ֿ�����ʽջ�Ķ��˲���Ԫ�أ�
//��һ �ö���ָ�����ָ��ĵ�ַ��ʹ���ƶ�
/*void Push(LkStack **top,int e)
{
    LkStack *p;
    p=(LkStack *)malloc(sizeof(LkStack));
    p->data=e;
    p->next=top;
    *top=p;
}*/
LkStack *Push(LkStack *top,int e)
{
    LkStack *p;
    p=(LkStack *)malloc(sizeof(LkStack));
    p->data=e;
    p->next=top;
    top=p;
    return top;
}
//ɾ��ջ��Ԫ�أ���ջ��
/*void Pop(LkStack *top)
{
    LkStack *p;
    p=top;
    top=top->next;
    free(p);
}*/
LkStack *Pop(LkStack *top)
{
    LkStack *p;
    if(!top)
    {
        printf("\n��ʽջΪ��");
        exit(0);
    }
    else
    {
        p=top;
        printf("ɾ����ջ��Ԫ��Ϊ%d\n",top->data);
        top=top->next;
        free(p);
    }
    return top;
}
//�����ʽջ����ջ����ջ�ף�
void PutStack(LkStack *top)
{
    LkStack *p;
    printf("��ǰ��ʽջΪ\n");
    for(p=top;p->next!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
}
//����ջ��Ԫ�أ�ȡջ����
void GetTop(LkStack *top,int *e)
{
    *e=top->data;
}
//�ÿ���ʽջ
LkStack *ClearStack(LkStack *top)
{
    LkStack *p;
    while(top)
    {
        p=top;
        top=top->next;
        free(p);
    }
    printf("����ʽջ���ÿ�\n");
    return top;
}
//����˳��ջ
void DestroyStack(LkStack **top)
{
    if((*top)->next==NULL)
    {
        printf("����ʽջ������");
        exit(0);
    }
    else
    {
        *top=ClearStack(*top);
        free(*top);
        printf("�������\n");
    }
}
//ջ�ĳ���
int StackLength(LkStack *top)
{
    int i=0;
    LkStack *p;
    p=top;
    while(p->next!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
//��ʽջ���п�
void StackEmpty(LkStack *top)
{
    if(top->next==NULL)
        printf("����ʽջΪ��\n");
    else
        printf("��ʽջ��Ϊ��\n");
}
int main()
{
    int i,elem,length,choice;
    LkStack *top;
    top=InitStack();
    printf("��������Ҫ��������ʽջ�ĳ���\n");
    scanf("%d",&length);
    printf("������������ʽջ�еĸ���Ԫ��\n");
    for(i=0;i<length;i++)
    {
        scanf("%d",&elem);
        top=Push(top,elem);
    }
    printf("\n��ѡ��Դ���ʽջ�Ĳ�����1.���루ѹջ�� 2.ɾ��ջ��Ԫ�أ���ջ�� 3.����ջ��Ԫ�أ�ȡջ���� 4.���� 5.�ÿ� 6.ջ�ĳ��� 7.˳��ջ���п�\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("������������ջ�������Ԫ��\n");scanf("%d",&elem);top=Push(top,elem);length++;break;
        case 2:top=Pop(top);length--;break;
        case 3:GetTop(top,&elem);printf("ջ��Ԫ��Ϊ%d\n",elem);break;
        case 4:DestroyStack(&top);exit(0);
        case 5:top=ClearStack(top);length=0;exit(0);
        case 6:length=StackLength(top);printf("��ǰ����Ϊ%d\n",length);break;
        case 7:StackEmpty(top);exit(0);
    }
    PutStack(top);

}









