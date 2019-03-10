/*#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100
#define stackincrement 10
typedef struct node
{
    int *base;
    int *top;
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
int  stacklength(sqtack *s)
{
    return s->top-s->base;
}
int emptystack(sqtack *s)
{
    return s->top==s->base;
}
void getstack(sqtack *s,int *e)
{
    int i=1;
    if(*e==*s->top)
    {
        printf("Ԫ����ջ�е�%d��λ��",i);
        return;
    }
    else
    {
        *e=*(s->top-1);
        i++;
    }
    return;
}
void push(sqtack*s,int e)
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
int pop (sqtack *s)
{
    int e;
    if(s->top==s->base)
        return;
    else
    {
        e=*(--s->top);
        printf("%d ",e);
    }
}
void clearstack(sqtack *s)
{
    s->top==s->base;
}
void destorystack(sqtack *s)
{
    free(s->base);
    s->base=s->top=NULL;
    s->stacksize=0;
    return;
}
void gettopstack(sqtack *s,int *e)
{
   if(emptystack(s))
   {
       printf("stack is empty\n");
       return;
   }
   *e=*(s->top-1);
}
void searchstack(sqtack*s)
{
    int *p,m,i=1,flag=0;
    p=(int*)malloc(sizeof(int));
    p=s->top;
    if(s->top==s->base)
        printf("stack is empty\n");
    else
    {
        p--;
        printf("��������Ҫ���ҵ�Ԫ��ֵ:\n");
        scanf("%d",&m);
        while(p!=s->base)
        {
            if(*p==m)
            {
                flag=1;
                printf("Ԫ����ջ�д����������ĵ�%d��\n",i);
                break;
            }
            else
                i++;
        }
    }
    if(m==*s->base)
    {
        flag=1;
        printf("Ԫ����ջ��\n");
    }
    if(flag==0)
        printf("��������\n");
    return;
}
void stacktraverse(sqtack*s)
{
   int *p;
   p=(int*)malloc(sizeof(int));
   p=s->top;
   if(s->top==s->base)
    printf("stack is empty!\n");
   else
   {
       p--;
       while(p!=s->base)
       {
           printf("%d ",*p);
           p--;
       }
   }
   printf("%d ",*s->base);
   printf("\n");
   return;
}
int main()
{
    int n,i,e,temp,length;
    sqtack s;
    initstack(&s);
    printf("������ڵ����:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        push(&s,e);
    }
    length=stacklength(&s);
    printf("������˳��ջ�ĳ���Ϊ%d\n",length);
    gettopstack(&s,&temp);
    printf("ջ��Ԫ����%d\n",temp);
    printf("�������ջ����ջ�׵�Ԫ��\n");
    stacktraverse(&s);
    searchstack(&s);
    printf("��Ԫ�����γ�ջ:\n");
    for(i=0;i<n;i++)
        pop(&s);
    clearstack(&s);
    destorystack(&s);
    return;
}*/

/*#include<stdio.h>
#include<stdlib.h>
#define stack_init_size 100  //ʮ����תΪN����
#define stackincrement 10
typedef struct node
{
    int *base;
    int *top;
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
int emptystack(sqtack *s)
{
    if(s->top==s->base)
        return 1;
    else
        return 0;
}
void push(sqtack*s,int e)
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

int pop (sqtack *s)
{
    int e;
    if(s->top==s->base)
        return;
    else
    {
        e=*(--s->top);
        if(e>=10)
        {
            printf("%c",(e-10)+'A');
        }
        else
        printf("%d",e);
    }
}
void conversioneight(sqtack *s,int n)
{
    while(n)
    {
        push(s,n%8);
        n=n/8;
    }
    while(!emptystack(s))
        pop(s);

}
void conversiontwo(sqtack*s,int n)
{
    while(n)
    {
        push(s,n%2);
        n=n/2;
    }
    while(!emptystack(s))
        pop(s);
}
void conversionsixteen(sqtack*s,int n)
{
    while(n)
    {
        push(s,n%16);
        n=n/16;
    }
    while(!emptystack(s))
        pop(s);

}
int main()
{
    int n,choice;
    sqtack s;
    initstack(&s);
    printf("������һ��ʮ������\n");
    scanf("%d",&n);
    printf("<1>��ʮ����ת��Ϊ������<2>��ʮ����ת��Ϊ�˽���<3>��ʮ����ת��Ϊʮ������\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:conversiontwo(&s,n);break;
        case 2:conversioneight(&s,n);break;
        case 3:conversionsixteen(&s,n);break;
        default:printf("��������!\n");break;
    }
    return 0;
}*/
/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define stack_init_size 100
#define stackincrement 10      //������ ʮ���� ʮ������תΪʮ����
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
int emptystack(sqtack *s)
{
    if(s->top==s->base)
        return 1;
    else
        return 0;
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
char pop (sqtack *s)
{
    int e;
    if(s->top==s->base)
        return;
    else
        e=*(--s->top);
    return e;
}
int  stacklength(sqtack *s)
{
    return s->top-s->base;
}
void twoconversion(sqtack *s)
{
    int length,i,sum=0;
    char c,temp;
    scanf("%c",&c);
    while(c!='\n')
    {
        push(s,c);
        scanf("%c",&c);
    }
    length=stacklength(s);
    for(i=0;i<length;i++)
    {
       temp=pop(s);
       if(temp=='1')
       sum+=pow(2,i);
    }
    printf("ʮ������Ϊ%d\n",sum);
    return;
}
void eightconversion(sqtack*s)
{
    int length,i,sum=0;
    char c,temp;
    scanf("%c",&c);
    while(c!='\n')
    {
        push(s,c);
        scanf("%c",&c);
    }
    length=stacklength(s);
    for(i=0;i<length;i++)
    {
       temp=pop(s);
       if(temp!='0')
       sum+=(temp-48)*pow(8,i);
    }
    printf("ʮ������Ϊ%d\n",sum);
    return;
}
void sixteenconversion(sqtack *s)
{
    int length,i,sum=0;
    char c,temp;
    scanf("%c",&c);
    while(c!='\n')
    {
        push(s,c);
        scanf("%c",&c);
    }
    length=stacklength(s);
    for(i=0;i<length;i++)
    {
       temp=pop(s);
       if(temp!='0')
       {
           if(temp<='9')
            sum+=(temp-'0')*pow(16,i);
           if(temp>='A'&&temp<='Z')
            sum+=(temp-'A'+10)*pow(16,i);
       }
    }
    printf("ʮ������Ϊ%d\n",sum);
    return;

}
int main()
{
    sqtack s;
    int choice;
    initstack(&s);
    printf("<1>����һ����������<2>����һ���˽�����<3>����һ��ʮ��������\n");
    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
        case 1:twoconversion(&s);break;
        case 2:eightconversion(&s);break;
        case 3:sixteenconversion(&s);break;
        default:break;
    }
    return;
}*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define stack_init_size 100//ջ����������
#define stackincrement 10
typedef struct nodeone
{
    int *base;
    int *top;
    int stacksize;
}opndsqtack;
typedef struct nodetwo
{
    char *base;
    char *top;
    int stacksize;
}optrsqtack;
void initstack_opnd(opndsqtack *s) //������ջ
{
    s->base=(int*)malloc(stack_init_size*sizeof(int));
    if(!s->base)
    exit(0);
    s->top=s->base;
    s->stacksize=stack_init_size;
    return;
}
void pushopnd(opndsqtack*s,int e)
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
void popopnd (opndsqtack *s,int *x)
{
    int e;
    if(s->top==s->base)
        return;
    else
        *x=*(--s->top);
}
int gettop_opnd(opndsqtack *s,int e)
{
    if(s->base==s->top)
        return 0;
    e=*(s->top-1);
    return e;
}
void initstack_optr(optrsqtack*s) //�����ջ
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
char precede(char op1,char op2)//�ж����ȼ�
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
int opperator(char c)//�ж��Ƿ�Ϊ�ַ�
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
int operate(int a,char b,int c)//���ز���ֵ
{
    int i;
    switch(b)
    {
        case'+':i=a+c;break;
        case'-':i=a-c;break;
        case'*':i=a*c;break;
        case'/':if(c==0){printf("error:��������Ϊ0");exit(0);}i=a/c;break;
        default:printf("is not a operator\n");break;
    }
    return i;
}
char *change(char *c,int *result)
{
    int temp,sum=0;
    while(!opperator(*c)&&*c!='\0')
    {
        temp=*c-'0';
        sum=sum*10+temp;
        c++;
    }
    *result=sum;
    return c;
}
int evaluate(char exp[],optrsqtack*optr,opndsqtack*opnd)
{
     int num,a,b,result;
     char theta,x,*c;
     c=exp;
     pushoptr(optr,'#');
     while(*c!='#'||gettop_optr(optr)!='#')
     {
         //printf("getchar=%c  %c\n",*c,gettop_optr(optr));
         if(*c=='\0')
            break;
         if(!opperator(*c))
         {
             c=change(c,&num);
             pushopnd(opnd,num);
         }
         else
         {
             //printf("1");
             switch(precede(gettop_optr(optr),*c))
             {
                 case'<':pushoptr(optr,*c);c++;break;
                 case'=':popoptr(optr,&x);c++;break;
                 case'>':popoptr(optr,&theta);popopnd(opnd,&b);popopnd(opnd,&a);
                          result=operate(a,theta,b);pushopnd(opnd,result);
                           break;
                 default:break;
             }
         }
     }
    result=gettop_opnd(opnd,result);
    return result;
}
void standard(char exp[])
{
    char *p;
    p=exp;
    while(*p!='\0')
        p++;
    *p++='#';
    *p='\0';
}
int main()
{
    int result,len;
    char exp[101];
    printf("Please input a calculational expression:\n");
    scanf("%s",exp);
    optrsqtack optr;
    opndsqtack  opnd;
    initstack_optr(&optr);
    initstack_opnd(&opnd);
    standard(exp);
    result=evaluate(exp,&optr,&opnd);
    printf("The result is %d",result);
}
/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define stack_init_size 100
#define stackincrement 10    //������Ƶ�ת��
typedef struct node
{
    int *base;
    int *top;
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
int emptystack(sqtack *s)
{
    if(s->top==s->base)
        return 1;
    else
        return 0;
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
void push2(sqtack*s,int e)
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
char pop (sqtack *s)
{
    char e;
    if(s->top==s->base)
        return;
    else
        e=*(--s->top);
    return e;
}
int pop2 (sqtack *s)
{
    int e;
    if(s->top==s->base)
        return;
    else
        e=*(--s->top);
    return e;
}
int  otherten(sqtack *s,char m[],int a)
{
    int i,sum=0,j=0;
    char c;
    double k;
    for(i=0;m[i]!='\0';i++)
        push(s,m[i]);
    while(!emptystack(s))
    {
        c=pop(s);
        //printf("%c",c);
        if(c>='A'&&c<='F')
        {
            k=pow(a,j);
            sum+=(c-'A'+10)*k;
            j++;
        }
        else
        {
            k=pow(a,j);
            sum+=(c-48)*k;
            //printf("%d!",sum);
            j++;

        }
    }
    //printf("%d",sum);
    return sum;
}
void tentransimit(sqtack*s,int mid,int b)
{
    int c;
    while(mid)
    {
        push2(s,mid%b);
        mid=mid/b;
    }
    while(!emptystack(s))
    {
        c=pop(s);
        //printf("%d!",c);
        if(c>=10)
        {
            printf("%c",(c-10)+'A');
        }
        else
        printf("%d",c);
    }
}
int main()
{
    int mid;
    sqtack s;
    initstack(&s);
    int a,b;
    char S[40];
    scanf("%d %d %s",&a,&b,&S);
    mid=otherten(&s,S,a);
    tentransimit(&s,mid,b);
    return 0;
}*/

