#include<stdio.h>
#include<stdlib.h>
typedef char VertexType;//��������
typedef int Edgetype;//Ȩֵ����
#define Maxvex 100//��󶥵���
#define infinity 65535//��������
typedef int Boolean;//Bloolean �ǲ������� ��ʾ0��1
Boolean visited[Maxvex];
typedef struct//�ڽӾ���洢
{
    char vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//�������ͱ���
}Mgraph;
//�ڽӱ�ṹ
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
//�ڽӾ��󴴽�
void creatMgraph(Mgraph *G)
{
    int i,j,k,r;
    printf("���붥�����ͱ���:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    getchar();
    printf("������ÿ���������Ϣ:\n");
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
        printf("�����(vi,vj)�ϵ��±�i,�±�j:\n");
        scanf("%d %d",&i,&j);
        G->arc[i][j]=1;
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
//�ڽӾ����������ȱ���
void dfs(Mgraph G,int i)//������ȱ����ݹ��㷨
{
    int j;
    visited[i]=1;
    printf("%c ",G.vexs[i]);
    for(j=0;j<G.numVertexes;j++)
      if(G.arc[i][j]==1&&!visited[j])
        dfs(G,j);
}
void dfstraverse(Mgraph G)//��������
{
    int i;
    for(i=0;i<G.numVertexes;i++)
        visited[i]=0;
    for(i=0;i<G.numVertexes;i++)
        if(!visited[i])
           dfs(G,i);
}
//�ڽӱ��������ȱ���
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
    printf("������ڽӾ����������ȱ���:\n");
    dfstraverse(G);
    printf("\n");
    GraphAdjList GL;
    creatAlgraph(&GL);
    printf("������ڽӱ��������ȱ���:\n");
    Dfstraverse(GL);
    return 0;
}
