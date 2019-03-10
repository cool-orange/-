#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int weight;
    int parent,lchild,rchild;
}htnode,*huffmanTree;
typedef char  **huffmancode;
void select(huffmanTree *t,int n,int *s1,int *s2)
{
    int i,min1=0,min2=0;
    for(i=1;i<=n;i++)
    {
        if((*t)[i].parent==0)
        {
            if((*t)[i].weight<(*t)[min1].weight)
            min1=i;
        }
    }
    *s1=min1;
    for(i=1;i<=n;i++)
    {
        if((*t)[i].parent==0&&i!=min1)
        {
            if((*t)[i].weight<(*t)[min2].weight)
            min2=i;
        }
    }
    *s2=min2;
    return;
}
void huffmancoding(huffmanTree *t,huffmancode *hc,int *w,int n)
{
    char *cd;
    int m,min1,min2,i,start,c,f;
    if(n<=1)
        return;
    huffmanTree p;
    m=2*n-1;//节点总数
    *t=(huffmanTree)malloc((m+1)*sizeof(htnode));
    for(p=*t+1,i=1;i<=n;i++,p++,w++)//叶子结点赋值
    {
        p->weight=*(w+1);
        p->parent=p->lchild=p->rchild=0;
    }
    for(;i<=m;i++,p++)//非叶子节点初始化
        p->weight=p->parent=p->lchild=p->rchild=0;
    for(i=n+1;i<=m;i++)//选出最小的两个无父亲节点的孩子
    {
        select(t,i-1,&min1,&min2);
        //printf("%d",(*t)[1].weight);
        //printf("%d %d\n",min1,min2);
        (*t)[min1].parent=(*t)[min2].parent=i;
        (*t)[i].lchild=min1;
        (*t)[i].rchild=min2;
        //printf("%d %d\n",(*t)[min1].weight,(*t)[min2].weight);
        (*t)[i].weight=(*t)[min1].weight+(*t)[min2].weight;
        //printf("%d ",(*t)[i].weight);
    }
    /*for(i=1;i<=m;i++)
        printf("%d ",(*t)[i].weight);*/
    //逆向求哈夫曼编码
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';//n个节点的最长编码为n-1
    for(i=1;i<=n;i++)
    {
       start=n-1;//编码结束位置
       for(c=i,f=(*t)[i].parent;f!=0;c=f,f=(*t)[f].parent)
       {
         if((*t)[f].lchild==c)
            cd[--start]='0';
         else
            cd[--start]='1';
        }
       (*hc)[i]=(char*)malloc((n-start)*sizeof(char));
       strcpy((*hc)[i],&cd[start]);
    }
    free(cd);
    for(i=1;i<=n;i++)
        printf("%s\n",(*hc)[i]);
    return;
}
int main()
{
    int n,i;
    int w[100];
    huffmanTree t;
    huffmancode hc;
    hc=(char **)malloc((n+1)*sizeof(char *));
    printf("请输入节点的个数:\n");
    scanf("%d",&n);
    printf("请输入每个节点的权值:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    huffmancoding(&t,&hc,w,n);
}

