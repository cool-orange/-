//Dijkstra�㷨 ��Դ·�� ĳ���㵽���ж����·��
/*#include<stdio.h>
#include<stdlib.h>
#define Maxvex 9
#define infinity 65535
typedef char VertexType;
typedef int Edgetype;
typedef int Patharc[Maxvex];//typedef int Patharc[Maxvex] Patharc b[10]����˼���� int b[10][10];�洢���·���±�����
typedef int Shortpathtable[Maxvex];//���ڴ洢�������·��֮��
typedef struct //�ڽӾ���洢�ṹ
{
    VertexType vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//�������ͱ���
}Mgraph;
void creatgraph(Mgraph *G)
{
    char r;
    int i,j,k,w;
    printf("�����붥�����ͱ���:\n");
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
             G->arc[i][j]=infinity;
    for(i=0;i<G->numVertexes;i++)
        G->arc[i][i]=0;
    for(k=0;k<G->numEdges;k++)
    {
        printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
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

    //��ʼ��ѭ����ÿ����v0��v�����·��
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
    //��ӡ���·�����
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
//Floyd�㷨 ���ж��������ж�������·��
#include<stdio.h>
#include<stdlib.h>
#define Maxvex 9
#define infinity 65535
typedef char VertexType;
typedef int Edgetype;
typedef int Pathmatirx[Maxvex][Maxvex];
typedef int ShortPathTable[Maxvex][Maxvex];
typedef struct //�ڽӾ���洢�ṹ
{
    VertexType vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//�������ͱ���
}Mgraph;
void creatgraph(Mgraph *G)
{
    char r;
    int i,j,k,w;
    printf("�����붥�����ͱ���:\n");
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
             G->arc[i][j]=infinity;
    for(i=0;i<G->numVertexes;i++)
        G->arc[i][i]=0;
    for(k=0;k<G->numEdges;k++)
    {
        printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
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
    //��ӡ���·����ʾ����
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
