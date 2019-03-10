//拓扑排序算法 AOV网 不存在回路 因为一项任务开始不可能以自己完成作为先决条件
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
//邻接表的创建
void creatAlgraph(graphAdjlist *G)
{
    int i,j,k;
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
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d %d",&i,&j);
        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex=j;
        e->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;
        G->adjlist[j].in++;
    }
}
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
    while(top!=0)
    {
        gettop=stack[top--];
        if(count==GL->numVertexes-1)
            printf("%d",GL->adjlist[gettop].data);
        else
            printf("%d->",GL->adjlist[gettop].data);
        count++;
        for(e=GL->adjlist[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            if(!(--GL->adjlist[k].in))//将k号顶点邻接点的入度减1
            stack[++top]=k;
        }
    }
    if(count<GL->numVertexes)//count数小于顶点数，说明存在环
        return 0;
    else
        return 1;
}
int main()
{
    graphAdjlist GL;
    creatAlgraph(&GL);
    topologicalsort(&GL);
    return 0;
}
//-finput-charset=GBK
//-fexec-charset=GBK  中文乱码问题
