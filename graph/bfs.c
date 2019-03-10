#include<stdio.h>
#include<stdlib.h>
typedef char VertexType;//��������
typedef int Edgetype;//Ȩֵ����
#define Maxvex 100//��󶥵���
#define maxsize 100
#define LISTINCREMENT 10
#define infinity 65535//��������
typedef int Boolean;//Boolean�ǲ������ͣ���ֵ��TRUE��FALSE
Boolean visited[Maxvex];//���ʱ�־������
typedef struct//�ڽӾ���洢
{
    VertexType vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//�������ͱ���
}Mgraph;
//�ڽӱ�ṹ
typedef struct EdgeNode
{
    int adjvex;//�洢�ڽӵ��ڶ������±�
    Edgetype weight;
    struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode//�����
{
    VertexType data;
    EdgeNode *firstedge;//  ָ��߱��һ���ڵ�
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
        printf("�洢����ʧ��\n");
        exit(0);
    }
    else
        S->front=S->rear=0;
}
//�����µĶ�βԪ��
void enqueue(queue *S,int e)
{
    if((S->rear+1)%maxsize==S->front)
        S->base=(int *)realloc(S->base,(maxsize+LISTINCREMENT)*sizeof(int));
    if(!S->base)
    {
        printf("�洢����ʧ��\n");
        exit(0);
    }
    S->base[S->rear]=e;
    S->rear=(S->rear+1)%maxsize;
}
//ɾ����ͷԪ��
void dequeue(queue *S,int *e)
{
    *e=S->base[S->front];
    S->front=(S->front+1)%maxsize;
    return;
}
//˳����е��п�
int  queuempty(queue S)
{
    if(S.front==S.rear)
        return 1;
    else
        return 0;
}
//�ڽӾ��󴴽�
void creatMgraph(Mgraph *G)
{
    int i,j,k,w;
    printf("���붥�����ͱ���:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    for(i=0;i<G->numVertexes;i++)
        scanf("%c",&G->vexs[i]);
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
        G->arc[i][j]=infinity;
    for(k=0;k<G->numEdges;i++)
    {
        printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
        scanf("%d %d %d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
}
//�ڽӱ�Ĵ���
void creatAlgraph(GraphAdjList *G)
{
    int i,j,k;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    for(i=0;i<G->numVertexes;i++)//���붥����Ϣ�����������
    {
        scanf("%d",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;
    }
    for(k=0;k<G->numEdges;k++)
    {
        printf("�����(vi,vj)�ϵĶ������:\n");
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
//�ڽӾ��������ȱ���
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
//�ڽӱ�Ĺ�����ȱ���
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
