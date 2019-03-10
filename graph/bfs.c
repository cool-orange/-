#include<stdio.h>
#include<stdlib.h>
typedef char VertexType;//顶点类型
typedef int Edgetype;//权值类型
#define Maxvex 100//最大顶点数
#define maxsize 100
#define LISTINCREMENT 10
#define infinity 65535//代表无穷
typedef int Boolean;//Boolean是布尔类型，其值是TRUE或FALSE
Boolean visited[Maxvex];//访问标志的数组
typedef struct//邻接矩阵存储
{
    VertexType vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//顶点数和边数
}Mgraph;
//邻接表结构
typedef struct EdgeNode
{
    int adjvex;//存储邻接点在顶点表的下标
    Edgetype weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode//顶点表
{
    VertexType data;
    EdgeNode *firstedge;//  指向边表第一个节点
}VertexNode,AdjList[Maxvex];
typedef struct
{
    AdjList adjlist;
    int numVertexes,numEdges;
}GraphAdjList;
typedef struct
{
    int *base;
    int front;
    int rear;
}queue;
void initqueue(queue *S)
{
    S->base=(int *)malloc(maxsize*sizeof(int));
    if(!S->base)
    {
        printf("存储分配失败\n");
        exit(0);
    }
    else
        S->front=S->rear=0;
}
//插入新的队尾元素
void enqueue(queue *S,int e)
{
    if((S->rear+1)%maxsize==S->front)
        S->base=(int *)realloc(S->base,(maxsize+LISTINCREMENT)*sizeof(int));
    if(!S->base)
    {
        printf("存储分配失败\n");
        exit(0);
    }
    S->base[S->rear]=e;
    S->rear=(S->rear+1)%maxsize;
}
//删除队头元素
void dequeue(queue *S,int *e)
{
    *e=S->base[S->front];
    S->front=(S->front+1)%maxsize;
    return;
}
//顺序队列的判空
int  queuempty(queue S)
{
    if(S.front==S.rear)
        return 1;
    else
        return 0;
}
//邻接矩阵创建
void creatMgraph(Mgraph *G)
{
    int i,j,k,w;
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    for(i=0;i<G->numVertexes;i++)
        scanf("%c",&G->vexs[i]);
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
        G->arc[i][j]=infinity;
    for(k=0;k<G->numEdges;i++)
    {
        printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
        scanf("%d %d %d",&i,&j,&w);
        G->arc[i][j]=w;
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
    getchar();
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
//邻接矩阵广度优先遍历
void bfstraverse(Mgraph G)
{
    int i,j;
    queue q;
    for(i=0;i<G.numVertexes;i++)
     visited[i]=0;
    initqueue(&q);
    for(i=0;i<G.numVertexes;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            printf("%c ",G.vexs[i]);
            enqueue(&q,i);
            while(!queuempty(q))
            {
                dequeue(&q,i);
                for(j=0;j<G.numVertexes;j++)
                {
                    if(G.arc[i][j]==1&&!visited[j])
                    {
                        visited[j]=1;
                        printf("%c ",G.vexs[j]);
                        enqueue(&q,j);
                    }
                }
            }
        }
    }
}
//邻接表的广度优先遍历
void Bfstraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    queue q;
    for(i=0;i<GL.numVertexes;i++)
        visited[i]=0;
    initqueue(&q);
    for(i=0;i<GL.numVertexes;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            printf("%c ",GL.adjlist[i].data);
            enqueue(&q,i);
            while(!queuempty(q))
            {
                dequeue(&q,&i);
                p=GL.adjlist[i].firstedge;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex]=1;
                        printf("%c ",GL.adjlist[p->adjvex].data);
                        enqueue(&q,p->adjvex);
                    }
                    p=p->next;
                }
            }
        }
    }
}
int main()
{
    Mgraph G;
    creatMgraph(&G);
}
