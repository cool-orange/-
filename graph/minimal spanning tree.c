#include<stdio.h>
#include<stdlib.h>
typedef char VertexType;
typedef int Edgetype;
#define Maxvex 100//��󶥵���
#define Maxedge 200//����������
#define infinity 65535
typedef int Boolean;//��������
Boolean visited[Maxvex];
typedef struct //�ڽӾ���洢�ṹ
{
    VertexType vexs[Maxvex];
    Edgetype arc[Maxvex][Maxvex];
    int numVertexes,numEdges;//�������ͱ���
}Mgraph;
typedef struct
{
    int begin;
    int end;
    int weight;
}Edge;
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
void miniSpantree_Prim(Mgraph G)//Prim�㷨������С������
{
    int min,i,j,k;
    int adjvex[Maxvex];
    int lowcost[Maxvex];
    lowcost[0]=0;
    adjvex[0]=0;
    for(i=1;i<G.numVertexes;i++)
    {
        lowcost[i]=G.arc[0][i];
        adjvex[i]=0;
    }
    /*for(i=0;i<G.numVertexes;i++)
    {
        for(j=0;j<G.numVertexes;j++)
           printf("%d ",G.arc[i][j]);
      printf("\n");
    }*/
    for(i=1;i<G.numVertexes;i++)
    {
        min=infinity;
        j=1;k=0;
        while(j<G.numVertexes)
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k]=0;
       for(j=1;j<G.numVertexes;j++)
      {
        if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
        {
            lowcost[j]=G.arc[k][j];
            adjvex[j]=k;
        }
      }
    }
}
int cmp(const void *a,const void *b)
{
    return ((Edge*)a)->weight-((Edge*)b)->weight;
}
int find(int*parent,int f)
{
    while(parent[f]>0)
        f=parent[f];
    return f;
}
void miniSpantree_Kru(Mgraph G)//Krusal�㷨������С������
{
    int i,j,m,n,k=0;
    Edge edges[Maxedge];
    int parent[Maxvex];
    for(i=0;i<G.numVertexes;i++)
      parent[i]=0;//�������������жϱ�����Ƿ��γɻ�·
    for(i=0;i<G.numVertexes;i++)//ѭ�������һ��
    {
        for(j=0;j<=i;j++)
      {
         if(G.arc[i][j]!=0&&G.arc[i][j]!=65535)
         {
             edges[k].weight=G.arc[i][j];
             edges[k].begin=j;
             edges[k].end=i;
             k++;
         }

      }
    }
    qsort(edges,k,sizeof(Edge),cmp);
    for(i=0;i<G.numEdges;i++)
    {
        n=find(parent,edges[i].begin);
        m=find(parent,edges[i].end);
        //printf("%d %d\n",n,m);
        if(n!=m)
        {
            parent[n]=m;
            printf("(%d %d) %d",edges[i].begin,edges[i].end,edges[i].weight);
            //printf("\n");
        }
    }
}
int main()
{
    Mgraph G;
    creatgraph(&G);
    miniSpantree_Prim(G);
    printf("\n");
    miniSpantree_Kru(G);
}

