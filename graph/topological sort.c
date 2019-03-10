//���������㷨 AOV�� �����ڻ�· ��Ϊһ������ʼ���������Լ������Ϊ�Ⱦ�����
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
//�ڽӱ�Ĵ���
void creatAlgraph(graphAdjlist *G)
{
    int i,j,k;
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
        printf("�����(vi,vj)�ϵĶ������:\n");
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
    int *stack;//��ջ�洢���Ϊ�Ķ���
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
            if(!(--GL->adjlist[k].in))//��k�Ŷ����ڽӵ����ȼ�1
            stack[++top]=k;
        }
    }
    if(count<GL->numVertexes)//count��С�ڶ�������˵�����ڻ�
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
//-fexec-charset=GBK  ������������
