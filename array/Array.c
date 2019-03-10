/*#include<stdio.h>
#define MAXSIZE 12500
typedef struct
{
    int i,j;
    int e;
}Tr;
typedef struct
{
    Tr date[MAXSIZE+1];
    int mu,nu,tu;
}Ts;
int creat(Ts *m,int a,int b)
{
    m->mu=a;
    m->nu=b;
}
void TransponseSMatrix(Ts m,Ts*t)   //三元组顺序表的创建
{
    int p,q,col;
    t->mu=m.nu;
    t->nu=m.mu;
    t->tu=m.tu;
    if(t->tu)
    {
        q=1;
        for(col=1;col<=m.nu;++col)
            for(p=1;p<=m.tu;++p)
            if(m.date[p].j==col)
            {
                t->date[q].i=m.date[p].j;
                t->date[q].j=m.date[p].i;
                t->date[q].e=m.date[p].e;
                q++;
            }
    }
    return;
}
int main()
{
    int a,b,i,j,k,s,q,p;
    s=1,i=1,j=1;
    Ts m,t;
    printf("请输入稀疏矩阵的行和列值:\n");
    scanf("%d %d",&a,&b);
    creat(&m,a,b);
    for(k=1;k<=m.mu;k++)
    {
        for(p=1;p<=m.nu;p++)
       {
         scanf("%d",&q);
         if(q!=0)
         {
          m.date[s].e=q;
          m.date[s].i=k;
          m.date[s].j=p;
          s++;
         }
        }
    }
    m.tu=s-1;
    s=1;
    TransponseSMatrix(m,&t);
    for(i=1;i<=t.mu;i++)
    {
        for(j=1;j<=t.nu;j++)
       {
           if(t.date[s].i==i&&t.date[s].j==j)
           {
               printf("%d ",t.date[s].e);
               s++;
           }
           else
           printf("0 ");
       }
       printf("\n");
    }
    return 0;
}*/
/*#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
    int i,j;
    int e;
}Tr;
typedef struct
{
    Tr data[MAXSIZE+1];
    int mu,nu,tu;
}Ts;
int num[200]={0};
int cpot[200]={0};
int creat(Ts *m,int a,int b)
{
    m->mu=a;
    m->nu=b;
}
void fasttransposeSMatrix(Ts m,Ts *t)
{
    int col,s,p,q,i;
    t->mu=m.nu;
    t->nu=m.mu;
    t->tu=m.tu;
    if(t->tu)

    {
        for(col=1;col<=m.nu;col++)
             num[col]=0;
        for(s=1;s<=m.tu;s++)
            num[m.data[s].j]++;
        cpot[1]=1;
        for(col=2;col<=m.tu;col++)
            cpot[col]=cpot[col-1]+num[col-1];
        for(p=1;p<=m.tu;p++)
        {
            col=m.data[p].j;
            q=cpot[col];
            t->data[q].i=m.data[p].j;
            t->data[q].j=m.data[p].i;
            t->data[q].e=m.data[p].e;
            cpot[col]++;
        }
    }
    for(i=1;i<=t->tu;i++)
        printf("%d ",t->data[i].e);
    return;
}
int main()
{
    int a,b,i,j,k,s,q,p;
    s=1,i=1,j=1;
    Ts m,t;
    printf("请输入稀疏矩阵的行和列值:\n");    //快速转置
     scanf("%d %d",&a,&b);
    creat(&m,a,b);
    for(k=1;k<=m.mu;k++)
    {
        for(p=1;p<=m.nu;p++)
       {
         scanf("%d",&q);
         if(q!=0)
         {
          m.data[s].e=q;
          m.data[s].i=k;
          m.data[s].j=p;
          s++;
         }
        }
    }
    m.tu=s-1;
    s=1;
    fasttransposeSMatrix(m,&t);
    printf("\n");
    for(i=1;i<=t.mu;i++)
    {
        for(j=1;j<=t.nu;j++)
       {
           if(t.data[s].i==i&&t.data[s].j==j)
           {
               printf("%d ",t.data[s].e);
               s++;
           }
           else
           printf("0 ");
       }
       printf("\n");
    }
    return 0;
}*/
/*#include<stdio.h>
#define Maxsize 100    //稀疏矩阵的乘积
#define Maxrc 10
typedef struct
{
    int i,j;
    int e;
}Tr;
typedef struct
{
    Tr data[Maxsize];
    int rpos[Maxrc];
    int mu,nu,tu;
}Ts;
void creatrectangle(Ts *s)
{
    int m,n,k,l,q,p=0,row,num[Maxsize];
    printf("请输入稀疏矩阵的行值和列值:\n");
    scanf("%d %d",&m,&n);
    s->mu=m;s->nu=n;
    s->rpos[1]=1;
    for(k=1;k<=m;k++)
    {
        s->rpos[k]=p+1;
        for(l=1;l<=n;l++)
       {
        scanf("%d",&q);
        if(q!=0)
         {
          s->data[p+1].e=q;
          s->data[p+1].i=k;
          s->data[p+1].j=l;
          p++;
         }

       }
    }
    s->tu=p;
    return;
}
void mutiple(Ts s,Ts t,Ts*q)
{
    int ctemp[Maxrc];
    int arow,brow,ccol;
    int tp,p,ts,qs;
    if(s.nu!=t.mu)
        return 0;
    q->mu=s.mu;
    q->nu=t.nu;
    q->tu=0;
    //printf("1");
    if(s.tu*t.tu!=0)
    {
        for(arow=1;arow<=s.mu;arow++)
        {
            memset(ctemp, 0, sizeof(ctemp));
            q->rpos[arow]=q->tu+1;
            if(arow<s.mu)
                tp=s.rpos[arow+1];
            else
                tp=s.tu+1;
            for(p=s.rpos[arow];p<tp;p++)
            {
                brow=s.data[p].j;
                //printf("%d",brow);
                if(brow<t.mu)
                    ts=t.rpos[brow+1];
                else
                    ts=t.tu+1;
                for(qs=t.rpos[brow];qs<ts;qs++)
               {

                 ccol=t.data[qs].j;
                 ctemp[ccol]+=s.data[p].e*t.data[qs].e;
               }
            }
            for(ccol=1;ccol<=q->nu;ccol++)
            {
               if(ctemp[ccol])
              {
                q->tu++;
                if(q->tu>Maxsize)
                    return 0;
                q->data[q->tu].i=arow;
                q->data[q->tu].j=ccol;
                q->data[q->tu].e=ctemp[ccol];
              }
            }
        }
    }
    return;
}
int main()
{
    int i,j,m=1;
    Ts s,t,q;
    creatrectangle(&s);
    creatrectangle(&t);
    mutiple(s,t,&q);
    //for(i=1;i<=q.tu;i++)
        //printf("%d ",q.data[i].e);
    for(i=1;i<=q.mu;i++)
    {
        for(j=1;j<=q.nu;j++)
       {
           if(q.data[m].i==i&&q.data[m].j==j)
           {
               printf("%d ",q.data[m].e);
               m++;
           }
           else
           printf("0 ");
       }
       printf("\n");
    }
    return 0;
}*/
/*#include<stdio.h>
int main()
{
    int n,i;
    int a[21];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

    }

}*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string int2str(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

int main()
{
    vector<string> v;
    int num;

    while (cin>>num) {
        v.push_back(int2str(num));
    }
    for (unsigned int i = 0; i < v.size()-1; i++) {
        for (unsigned int j = 0; j < v.size()-i-1; j++) {
            if ((v[j] + v[j+1]) < (v[j+1]+v[j])) {
                swap(v[j], v[j+1]);
            }
        }
    }

    for (unsigned int i = 0; i < v.size(); i++) {
        cout<<v[i];
    }
    return 0;
}
