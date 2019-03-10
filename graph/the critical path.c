#include<stdio.h>
#include<stdlib.h>
#define Maxvex 100
typedef struct EdgeNode
{
    int adjvex;//�ڽӵ��� �洢�ö����Ӧ�±�
    int weight;//Ȩֵ
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

//ȫ�ֱ���
int *etv,*ltv;//���緢��ʱ�䡣��ٷ���ʱ��
int *stack2;//�洢��������
int top2;
//�ڽӱ�Ĵ���
void creatAlgraph(graphAdjlist *G)
{
    int i,j,k,w;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);
    printf("�����붥����Ϣ:\n");
    for(i=0;i<G->numVertexes;i++)//���붥����Ϣ�����������
    {
        scanf("%d",&G->adjlist[i].data);
        G->adjlist[i].firstedge=NULL;
        G->adjlist[i].in=0;
    }
    for(k=0;k<G->numEdges;k++)//����ͼ�ڽӱ���
    {
        printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
        scanf("%d %d %d",&i,&j,&w);
        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex=j;
        e->weight=w;
        e->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=e;
        G->adjlist[j].in++;
    }
}
//�������� ���ڹؼ�·������
int topologicalsort(Graphadjlist GL)
{
    EdgeNode *e;
    int i,k,gettop;
    int top=0;
    int count=0;
    int *stack;//��ջ�洢���Ϊ�Ķ���
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
            if(!(--GL->adjlist[k].in))//��k�Ŷ����ڽӵ����ȼ�1
            stack[++top]=k;
            if((etv[gettop]+e->weight)>etv[k])
                etv[k]=etv[gettop]+e->weight;
        }
    }
    if(count<GL->numVertexes)//count��С�ڶ�������˵�����ڻ�
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
