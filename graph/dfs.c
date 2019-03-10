#include<stdio.h>
#include<stdlib.h>
typedef char VertexType;//顶点类型
typedef int Edgetype;//权值类型
#define Maxvex 100//最大顶点数
#define infinity 65535//代表无穷
typedef int Boolean;//Bloolean 是布尔类型 表示0或1
Boolean visited[Maxvex];
typedef struct//邻接矩阵存储
{
    char vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//顶点数和边数
}Mgraph;
//邻接表结构
typedef struct EdgeNode
{
    int adjvex;
    Edgetype weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[Maxvex];
typedef struct
{
    AdjList adjlist;
    int numVertexes,numEdges;
}GraphAdjList;
//邻接矩阵创建
void creatMgraph(Mgraph *G)
{
    int i,j,k,r;
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    printf("请输入每个顶点的信息:\n");
    for(i=0;i<G->numVertexes;i++)
    {
        scanf("%c",&G->vexs[i]);
        scanf("%c",&r);
    }
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
         G->arc[i][j]=0;
    for(k=0;k<G->numEdges;k++)
    {
        printf("输入边(vi,vj)上的下标i,下标j:\n");
        scanf("%d %d",&i,&j);
        G->arc[i][j]=1;
        G->arc[j][i]=G->arc[i][j];
    }
}
//邻接表的创建
void creatAlgraph(GraphAdjList *G)
{
    int i,j,k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    for(i=0;i<G->numVertexes;i++)//读入顶点信息，建立顶点表
    {
        scanf("%d",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;
    }
    for(k=0;k<G->numEdges;k++)
    {
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d %d",&i,&j);
        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex=j;
        e->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;
        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex=i;
        e->next=G->adjlist[j].firstedge;
        G->adjlist[j].firstedge=e;
    }
}
//邻接矩阵的深度优先遍历
void dfs(Mgraph G,int i)//深度优先遍历递归算法
{
    int j;
    visited[i]=1;
    printf("%c ",G.vexs[i]);
    for(j=0;j<G.numVertexes;j++)
      if(G.arc[i][j]==1&&!visited[j])
        dfs(G,j);
}
void dfstraverse(Mgraph G)//遍历操作
{
    int i;
    for(i=0;i<G.numVertexes;i++)
        visited[i]=0;
    for(i=0;i<G.numVertexes;i++)
        if(!visited[i])
           dfs(G,i);
}
//邻接表的深度优先遍历
void Dfs(GraphAdjList GL,int i)
{
    EdgeNode *p;
    visited[i]=1;
    printf("%c ",GL.adjlist[i].data);
    p=GL.adjlist[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            Dfs(GL,p->adjvex);
        p=p->next;
    }
}
void Dfstraverse(GraphAdjList GL)
{
    int i;
    for(i=0;i<GL.numVertexes;i++)
        visited[i]=0;
    for(i=0;i<GL.numVertexes;i++)
        if(!visited[i])
        Dfs(GL,i);
}
int main()
{
    Mgraph G;
    creatMgraph(&G);
    printf("请输出邻接矩阵的深度优先遍历:\n");
    dfstraverse(G);
    printf("\n");
    GraphAdjList GL;
    creatAlgraph(&GL);
    printf("请输出邻接表的深度优先遍历:\n");
    Dfstraverse(GL);
    return 0;
}
