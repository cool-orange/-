#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int data;
    struct LkStack *next;
}LkStack;
//创建栈底结点
LkStack *InitStack()
{
    LkStack *top;
    top=(LkStack *)malloc(sizeof(LkStack));
    top->next=NULL;
    return top;
}
//插入元素（压栈）（既可用于创建链式栈，又可在链式栈的顶端插入元素）
//法一 用二级指针访问指针的地址，使其移动
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
//删除栈顶元素（出栈）
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
        printf("\n链式栈为空");
        exit(0);
    }
    else
    {
        p=top;
        printf("删除的栈顶元素为%d\n",top->data);
        top=top->next;
        free(p);
    }
    return top;
}
//输出链式栈（由栈顶到栈底）
void PutStack(LkStack *top)
{
    LkStack *p;
    printf("当前链式栈为\n");
    for(p=top;p->next!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
}
//查找栈顶元素（取栈顶）
void GetTop(LkStack *top,int *e)
{
    *e=top->data;
}
//置空链式栈
LkStack *ClearStack(LkStack *top)
{
    LkStack *p;
    while(top)
    {
        p=top;
        top=top->next;
        free(p);
    }
    printf("此链式栈已置空\n");
    return top;
}
//销毁顺序栈
void DestroyStack(LkStack **top)
{
    if((*top)->next==NULL)
    {
        printf("此链式栈不存在");
        exit(0);
    }
    else
    {
        *top=ClearStack(*top);
        free(*top);
        printf("销毁完毕\n");
    }
}
//栈的长度
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
//链式栈的判空
void StackEmpty(LkStack *top)
{
    if(top->next==NULL)
        printf("此链式栈为空\n");
    else
        printf("链式栈不为空\n");
}
int main()
{
    int i,elem,length,choice;
    LkStack *top;
    top=InitStack();
    printf("请输入需要创建的链式栈的长度\n");
    scanf("%d",&length);
    printf("请依次输入链式栈中的各个元素\n");
    for(i=0;i<length;i++)
    {
        scanf("%d",&elem);
        top=Push(top,elem);
    }
    printf("\n请选择对此链式栈的操作：1.插入（压栈） 2.删除栈顶元素（出栈） 3.查找栈顶元素（取栈顶） 4.销毁 5.置空 6.栈的长度 7.顺序栈的判空\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("请输入您想在栈顶插入的元素\n");scanf("%d",&elem);top=Push(top,elem);length++;break;
        case 2:top=Pop(top);length--;break;
        case 3:GetTop(top,&elem);printf("栈顶元素为%d\n",elem);break;
        case 4:DestroyStack(&top);exit(0);
        case 5:top=ClearStack(top);length=0;exit(0);
        case 6:length=StackLength(top);printf("当前长度为%d\n",length);break;
        case 7:StackEmpty(top);exit(0);
    }
    PutStack(top);

}









