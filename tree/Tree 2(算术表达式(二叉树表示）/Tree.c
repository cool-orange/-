#include<stdio.h>
#include<string.h>
#include"stack.h"
#include"bitree.h"

stacknode opnd;
optrsqtack optr;
void PrintTree(bitreeone T)
{
    if(T==NULL)
        return;
    PrintTree(T->lchild);
    PrintTree(T->rchild);
    printf("%c",T->data);
}
void creatnode(bitreeone *node,char s)
{
    *node=(bitreeone)malloc(sizeof(bitnode));
    (*node)->data=s;
    (*node)->lchild=NULL;
    (*node)->rchild=NULL;
    return;
}
void creatroot(bitreeone *T,bitreeone node,char e,bitreeone nodeone)
{
     *T=(bitreeone)malloc(sizeof(bitnode));
     (*T)->data=e;
     (*T)->lchild=nodeone;
     (*T)->rchild=node;
     return;
}

void creattree()
{
    int i;
    char s[100];
    char c,x,theta;
    printf("请输入算术表达式:\n");
    gets(s);
    bitreeone node,root,nodeone;
    pushoptr(&optr,'#');
    for(i=0;i<strlen(s);i++)
    {
        //printf("%c",s[i]);
        if(!opperator(s[i]))
        {
             creatnode(&node,s[i]);
             pushopnd(&opnd,node);
        }
        else
        {
            c=gettop_optr(&optr);
            switch(precede(c,s[i]))
            {
                case'<':pushoptr(&optr,s[i]);/*printf("%c",precede(c,s[i]))*/;break;
                case'=':popoptr(&optr,&x);/*printf("%c",precede(c,s[i]))*/;break;
                case'>':/*printf("%c",precede(c,s[i]));*/popoptr(&optr,&theta);popopnd(&opnd,&node);popopnd(&opnd,&nodeone);
                          creatroot(&root,node,theta,nodeone);/*printf("%c",root->lchild->data);*/pushopnd(&opnd,root);
                           break;
                default:break;
            }
        }
    }
    popopnd(&opnd,&root);
    PrintTree(root);
    return;

}
int main()
{
    initstack(&opnd);
    initstack_optr(&optr);
    creattree();
    return 0;
}
