#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 101
typedef struct
{
    char a[Maxsize];
}str;
void strlength(str*s)
{
    int i,m=0;
    for(i=0;s->a[i]!='\0';i++)
        m++;
    for(i=m;i>0;i--)
        s->a[i]=s->a[i-1];
    s->a[0]=m;
}
void get_next(str s,int *next)
{
    int i=1;
    next[1]=0;
    int j=0;
    while(i<s.a[0])
    {
        if(j==0||s.a[i]==s.a[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
void get_nextval(str s,int *nextval)//改进的KMP算法
{
    int i,j;
    i=1;
    j=0;
    nextval[1]=0;
    while(i<s.a[0])
    {
        if(j==0||s.a[i]==s.a[j])
        {
            ++i;
            ++j;
            if(s.a[i]!=s.a[j])
                nextval[i]=j;
            else
            nextval[i]=nextval[j];
        }
        else
        j=nextval[j];
    }
}
int index_KMP(str s,str t)
{
    int next[255];
    int i=1;
    int j=1;
    get_next(t,next);
    while(i<=s.a[0]&&j<=t.a[0])
    {
        if(j==0||s.a[i]==t.a[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>t.a[0])
        return i-t.a[0];
    else
        return 0;
}
int main()
{
  str s;
  str t;
  int i=0;
  int m;
  while(i<3)
  {
      scanf("%s %s",&s.a,&t.a);
      strlength(&s);
      strlength(&t);
      m=index_KMP(s,t);
      printf("%d",m);
      printf("\n");
      i++;
  }
}


