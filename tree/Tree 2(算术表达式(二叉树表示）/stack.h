#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define stack_init_size 100
#define stackincrement 10
#include"bitree.h"
typedef struct nodetwo
{
    char *base;
    char *top;
    int stacksize;
}optrsqtack;
typedef struct stacknode
{
    bitreeone *base;
    bitreeone *top;
    int stacksize;
}stacknode;
void initstack(stacknode *s)
{
    s->base=(bitreeone*)malloc(stack_init_size*sizeof(bitreeone));
    if(!s->base)
    exit(0);
    s->top=s->base;
    s->stacksize=stack_init_size;
    return;
}
void pushopnd(stacknode*s,bitreeone e)
{
    if(s->top-s->base==s->stacksize)
    {
        s->base=(bitreeone*)realloc(s->base,(s->stacksize+stackincrement)*sizeof(bitreeone));
        if(!s->base)
            exit(0);
        s->top=s->base+s->stacksize;
        s->stacksize+=stackincrement;
    }
    *s->top++=e;
    return;
}
void popopnd (stacknode*s,bitreeone *x)
{
    int e;
    if(s->top==s->base)
        return;
    else
        *x=*(--s->top);
}
int gettop_opnd(stacknode *s,bitreeone *e)
{
    if(s->base==s->top)
        return 0;
    *e=*(s->top-1);
    return e;
}
void initstack_optr(optrsqtack*s)
{
    s->base=(char*)malloc(stack_init_size*sizeof(char));
    if(!s->base)
    exit(0);
    s->top=s->base;
    s->stacksize=stack_init_size;
    return;
}
char gettop_optr(optrsqtack *s)
{
    char e;
    if(s->base==s->top)
        return 0;
    e=*(s->top-1);
    return e;
}
void pushoptr(optrsqtack*s,char e)
{
    if(s->top-s->base==s->stacksize)
    {
        s->base=(int*)realloc(s->base,(s->stacksize+stackincrement)*sizeof(int));
        if(!s->base)
            exit(0);
        s->top=s->base+s->stacksize;
        s->stacksize+=stackincrement;
    }
    *s->top++=e;
    return;
}
void popoptr(optrsqtack *s,char *x)
{
    if(s->top==s->base)
        return;
    else
        *x=*(--s->top);
}
int opperator(char c)//
{
    switch(c)
    {
        case '+':return 1;break;
        case '-':return 1;break;
        case '*':return 1;break;
        case '/':return 1;break;
        case '(':return 1;break;
        case ')':return 1;break;
        case '#':return 1;break;
        default :return 0;break;
    }
}
char precede(char op1,char op2)//≈–∂œ”≈œ»º∂
{
    switch(op1)
    {
        case'+':
            switch(op2)
            {
                case'*':return'<';break;
                case'/':return'<';break;
                case'(':return'<';break;
                default:return'>';break;
            }
        break;
        case'-':
             switch(op2)
            {
                case'*':return'<';break;
                case'/':return'<';break;
                case'(':return'<';break;
                default:return'>';break;
            }
        break;
        case'*':
            switch(op2)
            {
                case'(':return '<';break;
                default:return '>';break;
            }
        break;
        case'/':
           switch(op2)
           {
                case'(':return '<';break;
                default:return '>';break;
           }
        break;
        case'(':
            switch(op2)
              {
                  case')':return'=';break;
                  default:return'<';break;
              }
        break;
        case')':
            switch(op2)
            {
                default:return'<';break;
            }
        break;
        case'#':
            switch(op2)
            {
                case'#':return'=';break;
                default:return'<';break;
            }
        break;
        default:return'<';break;
    }
}
#endif // STACK_H_INCLUDED
