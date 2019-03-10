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
//构造一个空栈
void InitStack(SqStack *S)
{
    S->base=(int *)malloc(maxsize*sizeof(int));
    if(!S->base)
    {
        printf("存储分配失败\n");
        exit(0);
    }
    else
        S->top=S->base;
}
//插入元素（压栈）（既可用于创建顺序栈，又可在顺序栈的顶端插入元素）
void Push(SqStack *S,int e)
{
    if(S->top-S->base==maxsize)
        S->base=(int *)realloc(S->base,(maxsize+LISTINCREMENT)*sizeof(int));
    if(!S->base)
    {
        printf("存储分配失败\n");
        exit(0);
    }
    *(S->top)=e;
    S->top++;
}
//删除栈顶元素（出栈）
void Pop(SqStack *S,int *e)
{
    *e=*--S->top;
}
//查找栈顶元素并输出
void GetTop(SqStack S,int *e)
{
    *e=*(S.top-1);
}
//顺序栈的长度
int StackLength(SqStack S)
{
    int i;
    int *p;
    p=S.base;
    for(i=0;p!=S.top;p++,i++);
    return i;
}
//输出顺序栈（由栈底到栈顶）
/*void PutStack(SqStack S)
{
    int i;
    int *p,*s;
    p=S.base;
    printf("当前顺序栈为\n");
    for(i=0;i<StackLength(S);i++)
    {
        printf("%d ",*(p+i));
    }
}*/
//输出顺序栈（由栈底到栈顶）
void PutStack(SqStack S)
{
    int i;
    int *p;
    p=S.base;
    printf("当前顺序栈为\n");
    for(i=StackLength(S);i>0;i--)
    {
        printf("%d ",*(p+i));
    }

}
//销毁顺序栈
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
        printf("此顺序栈不存在\n");
        exit(0);
    }
    if(!S->base)
        printf("销毁完毕\n");
}
//置空顺序栈
void ClearStack(SqStack *S)
{
    for(;S->top!=S->base;S->top--);
    if(S->top==S->base)
        printf("顺序栈已置空\n");
}
//顺序栈的判空
int StackEmpty(SqStack S)
{
    if(S.base==S.top)
    {
        //printf("此顺序栈为空\n");
        return 0;
    }
    else
        //printf("此顺序表不为空\n");
        return 1;
}
