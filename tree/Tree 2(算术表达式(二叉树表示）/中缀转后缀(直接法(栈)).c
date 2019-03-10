#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stack_init_size 100
#define stackincrement 10
typedef struct node
{
    char *base;
    char *top;
    int stacksize;
}sqtack;
void initstack(sqtack *s)
{
    s->base=(int*)malloc(stack_init_size*sizeof(int));
    if(!s->base)
    exit(0);
    s->top=s->base;
    s->stacksize=stack_init_size;
    return;
}
void push(sqtack*s,char e)
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
void pop(sqtack *s,char *e)
{
    if(s->top==s->base)
        return;
    else
        *e=*(--s->top);
}
char gettopstack(sqtack *s)
{
    char e;
   if(s->base==s->top)
    return;
   e=*(s->top-1);
   return e;
}
void transition(char data[])
{
    int i,j=0;
    char res[100],a;
    sqtack s;
    initstack(&s);
    for(i=0;i<strlen(data);i++)
    {
        //printf("%c",data[i]);
        if(data[i]>='0'&&data[i]<='9')
        {
            printf("%c",data[i]);
            continue;
            //res[j++]=data[i];
        }
        else
        {
            if(s.top==s.base)
            {
                //printf("!");
                push(&s,data[i]);
                continue;
            }
            else if(data[i]==')')
            {
                 while(gettopstack(&s)!='(')
                 {
                    pop(&s,&a);
                    printf("%c",a);
                    //res[j++]=a;
                 }
                 if(gettopstack(&s)=='(')
                        pop(&s,&a);
                continue;
            }
            else if(data[i]=='+'||data[i]=='-')
            {
                if(gettopstack(&s)=='(')
                {
                    //printf("%c",a);
                    push(&s,data[i]);
                    continue;
                }
                if(a!='('||a==')')
                {
                   pop(&s,&a);
                   printf("%c",a);
                   //res[j++]=a;
                   while(gettopstack(&s)!='('||gettopstack(&s)==')')
                   {
                     pop(&s,&a);
                     printf("%c",a);
                     //res[j++]=a;
                   }
                   push(&s,&data[i]);
                   continue;
                }

            }
            else if(data[i]=='*'||data[i]=='/'||data[i]=='(')
            {
                 push(&s,data[i]);
                 continue;
            }
        }
    }
    //printf("1");
    while(s.top!=s.base)
    {
        //printf("1");
        pop(&s,&a);
        printf("%c",a);
        //res[j++]=a;
    }
    //res[j]='\0';
    return;
}
int main()
{
    char data[100];
    printf("Please input a middle expression:\n");
    gets(data);
    transition(data);
}
