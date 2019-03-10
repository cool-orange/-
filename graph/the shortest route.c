//Dijkstra算法 单源路径 某顶点到所有顶点的路径
/*#include<stdio.h>
#include<stdlib.h>
#define Maxvex 9
#define infinity 65535
typedef char VertexType;
typedef int Edgetype;
typedef int Patharc[Maxvex];//typedef int Patharc[Maxvex] Patharc b[10]的意思就是 int b[10][10];存储最短路径下标数组
typedef int Shortpathtable[Maxvex];//用于存储各点最短路径之和
typedef struct //邻接矩阵存储结构
{
    VertexType vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//顶点数和边数
}Mgraph;
void creatgraph(Mgraph *G)
{
    char r;
    int i,j,k,w;
    printf("请输入顶点数和边数:\n");
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
             G->arc[i][j]=infinity;
    for(i=0;i<G->numVertexes;i++)
        G->arc[i][i]=0;
    for(k=0;k<G->numEdges;k++)
    {
        printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
        scanf("%d %d %d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
    return;
}
void ShortestPath_Dijkstra(Mgraph G,int v0,Patharc *p,Shortpathtable *d)
{
    int v,w,k,min,i;
    int final[Maxvex];
    for(v=0;v<G.numVertexes;v++)
    {
        final[v]=0;
        (*d)[v]=G.arc[v0][v];
        (*p)[v]=0;
    }
    (*d)[v0]=0;
    final[v0]=1;

    //开始主循环，每次求v0到v的最短路径
    for(v=1;v<G.numVertexes;v++)
    {
        min=65535;
        for(w=0;w<G.numVertexes;w++)
        {
            if(!final[w]&&(*d)[w]<min)
            {
                k=w;
                min=(*d)[w];
            }
        }
        final[k]=1;
        for(w=0;w<G.numVertexes;w++)
        {
            if(!final[w]&&(min+G.arc[k][w]<(*d)[w]))
            {
                (*d)[w]=min+G.arc[k][w];
                (*p)[w]=k;
            }
        }
    }
    //打印最短路径结果
    printf("dijkstra(%c):\n",G.vexs[v0]);
    for(i=0;i<G.numVertexes;i++)
     printf("shortest(%c %c)=%d\n",G.vexs[v0],G.vexs[i],(*d)[i]);
}
int main()
{
    int v0=0;
    Mgraph G;
    creatgraph(&G);
    Patharc p[Maxvex];
    Shortpathtable d[Maxvex];
    ShortestPath_Dijkstra(G,v0,p,d);
    return 0;
}*/
//Floyd算法 所有顶点至所有顶点的最短路径
#include<stdio.h>
#include<stdlib.h>
#define Maxvex 9
#define infinity 65535
typedef char VertexType;
typedef int Edgetype;
typedef int Pathmatirx[Maxvex][Maxvex];
typedef int ShortPathTable[Maxvex][Maxvex];
typedef struct //邻接矩阵存储结构
{
    VertexType vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//顶点数和边数
}Mgraph;
void creatgraph(Mgraph *G)
{
    char r;
    int i,j,k,w;
    printf("请输入顶点数和边数:\n");
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
             G->arc[i][j]=infinity;
    for(i=0;i<G->numVertexes;i++)
        G->arc[i][i]=0;
    for(k=0;k<G->numEdges;k++)
    {
        printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
        scanf("%d %d %d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
    return;
}
void ShortextPath_Floyd(Mgraph G,Pathmatirx *p,ShortPathTable *d)
{
    int v,w,k;
    for(v=0;v<G.numVertexes;++v)
    {
        for(w=0;w<G.numVertexes;w++)
        {
            (*d)[v][w]=G.arc[v][w];
            (*p)[v][w]=w;
        }

    }
    for(k=0;k<G.numVertexes;k++)
    {
        for(v=0;v<G.numVertexes;v++)
        {
            for(w=0;w<G.numVertexes;w++)
            {
                if((*d)[v][w]>(*d)[v][k]+(*d)[k][w])
                {
                    (*d)[v][w]=(*d)[v][k]+(*d)[k][w];
                    (*p)[v][w]=(*p)[v][k];
                }
            }
        }
    }
    //打印最短路径显示代码
    for(v=0;v<G.numVertexes;v++)
    {
        for(w=v+1;w<G.numVertexes;w++)
        {
            printf("v%d-v%d weight: %d",v,w,(*d)[v][w]);
            k=(*p)[v][w];
            printf(" path: %d",v);
            while(k!=w)
            {
                printf("->%d",k);
                k=(*p)[k][w];
            }
            printf("-> %d\n",w);
        }
        printf("\n");
    }
    return;
}
int main()
{
    Mgraph G;
    creatgraph(&G);
    Pathmatirx p[Maxvex][Maxvex];
    ShortPathTable d[Maxvex][Maxvex];
    ShortextPath_Floyd(G,p,d);
    return 0;
}
