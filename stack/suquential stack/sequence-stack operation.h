#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
#define LISTINCREMENT 10
typedef struct
{
    int *top;
    int *base;
    int stacksize;
}SqStack;
//����һ����ջ
void InitStack(SqStack *S)
{
    S->base=(int *)malloc(maxsize*sizeof(int));
    if(!S->base)
    {
        printf("�洢����ʧ��\n");
        exit(0);
    }
    else
        S->top=S->base;
}
//����Ԫ�أ�ѹջ�����ȿ����ڴ���˳��ջ���ֿ���˳��ջ�Ķ��˲���Ԫ�أ�
void Push(SqStack *S,int e)
{
    if(S->top-S->base==maxsize)
        S->base=(int *)realloc(S->base,(maxsize+LISTINCREMENT)*sizeof(int));
    if(!S->base)
    {
        printf("�洢����ʧ��\n");
        exit(0);
    }
    *(S->top)=e;
    S->top++;
}
//ɾ��ջ��Ԫ�أ���ջ��
void Pop(SqStack *S,int *e)
{
    *e=*--S->top;
}
//����ջ��Ԫ�ز����
void GetTop(SqStack S,int *e)
{
    *e=*(S.top-1);
}
//˳��ջ�ĳ���
int StackLength(SqStack S)
{
    int i;
    int *p;
    p=S.base;
    for(i=0;p!=S.top;p++,i++);
    return i;
}
//���˳��ջ����ջ�׵�ջ����
/*void PutStack(SqStack S)
{
    int i;
    int *p,*s;
    p=S.base;
    printf("��ǰ˳��ջΪ\n");
    for(i=0;i<StackLength(S);i++)
    {
        printf("%d ",*(p+i));
    }
}*/
//���˳��ջ����ջ�׵�ջ����
void PutStack(SqStack S)
{
    int i;
    int *p;
    p=S.base;
    printf("��ǰ˳��ջΪ\n");
    for(i=StackLength(S);i>0;i--)
    {
        printf("%d ",*(p+i));
    }

}
//����˳��ջ
void DestroyStack(SqStack *S)
{
    if(S->base)
    {
        free(S->base);
        S->base=NULL;
        S->stacksize=0;
    }
    else
    {
        printf("��˳��ջ������\n");
        exit(0);
    }
    if(!S->base)
        printf("�������\n");
}
//�ÿ�˳��ջ
void ClearStack(SqStack *S)
{
    for(;S->top!=S->base;S->top--);
    if(S->top==S->base)
        printf("˳��ջ���ÿ�\n");
}
//˳��ջ���п�
int StackEmpty(SqStack S)
{
    if(S.base==S.top)
    {
        //printf("��˳��ջΪ��\n");
        return 0;
    }
    else
        //printf("��˳���Ϊ��\n");
        return 1;
}
