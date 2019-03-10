#include<stdio.h>
#include<stdlib.h>
#define Maxvex 100
typedef struct EdgeNode
{
    int adjvex;//邻接点域 存储该顶点对应下标
    int weight;//权值
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    int in;
    int data;
    EdgeNode *firstedge;
}VertexNode,Adjlist[Maxvex];

typedef struct
{
    Adjlist adjlist;
    int numVertexes,numEdges;
}graphAdjlist,*Graphadjlist;

//全局变量
int *etv,*ltv;//最早发生时间。最迟发生时间
int *stack2;//存储拓扑序列
int top2;
//邻接表的创建
void creatAlgraph(graphAdjlist *G)
{
    int i,j,k,w;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    printf("请输入顶点信息:\n");
    for(i=0;i<G->numVertexes;i++)//读入顶点信息，建立顶点表
    {
        scanf("%d",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;
        G->adjlist[i].in=0;
    }
    for(k=0;k<G->numEdges;k++)//有向图邻接表创建
    {
        printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
        scanf("%d %d %d",&i,&j,&w);
        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex=j;
        e->weight=w;
        e->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;
        G->adjlist[j].in++;
    }
}
//拓扑排序 用于关键路径计算
int topologicalsort(Graphadjlist GL)
{
    EdgeNode *e;
    int i,k,gettop;
    int top=0;
    int count=0;
    int *stack;//建栈存储入度为的顶点
    stack=(int *)malloc(GL->numVertexes*sizeof (int));
    for(i=0;i<GL->numVertexes;i++)
    if(GL->adjlist[i].in==0)
        stack[++top]=i;
    top2=0;
    etv=(int*)malloc(GL->numVertexes*sizeof(int));
    for(i=0;i<GL->numVertexes;i++)
        etv[i]=0;
    stack2=(int*)malloc(GL->numVertexes*sizeof(int));
    while(top!=0)
    {
        gettop=stack[top--];
        count++;
        stack2[++top2]=gettop;
        for(e=GL->adjlist[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            if(!(--GL->adjlist[k].in))//将k号顶点邻接点的入度减1
            stack[++top]=k;
            if((etv[gettop]+e->weight)>etv[k])
                etv[k]=etv[gettop]+e->weight;
        }
    }
    if(count<GL->numVertexes)//count数小于顶点数，说明存在环
        return 0;
    else
        return 1;
}

void criticalpath(Graphadjlist GL)
{
    //printf("1@");
    EdgeNode *e;
    int i,gettop,k,j;
    int ete,lte;
    topologicalsort(GL);
    ltv=(int*)malloc(GL->numVertexes*sizeof(int));
    for(i=0;i<GL->numVertexes;i++)
     ltv[i]=etv[GL->numVertexes-1];
     /*for(i=0;i<GL->numVertexes;i++)
        printf("%d ",ltv[i]);*/
     while(top2!=0)
     {
         gettop=stack2[top2--];
         for(e=GL->adjlist[gettop].firstedge;e;e=e->next)
         {
             k=e->adjvex;
             if(ltv[k]-e->weight<ltv[gettop])
                ltv[gettop]=ltv[k]-e->weight;
         }
     }
     for(j=0;j<GL->numVertexes;j++)
     {
         for(e=GL->adjlist[j].firstedge;e;e=e->next)
         {
             k=e->adjvex;
             ete=etv[j];
             lte=ltv[k]-e->weight;
             if(ete==lte)
             printf("<v%d,v%d>length:%d,",GL->adjlist[j].data,GL->adjlist[k].data,e->weight);
         }
     }
}
int main()
{
    graphAdjlist GL;
    creatAlgraph(&GL);
    criticalpath(&GL);
    return 0;
}
