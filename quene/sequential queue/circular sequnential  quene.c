/*#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define Maxsize 100
typedef struct node
{
    int *elem;
    int front;
    int rear;
}queue;
int maininterface()
{
    int n;
    printf("\t\t\t\t\t\t|--------------------------|\n");
	printf("\t\t\t\t\t\t|        1.插入元素        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        2.删除元素        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        3.队列长度        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        4.输出队列        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.退出程序        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
void initqueue(queue *Q)
{
    Q->elem=(int*)malloc(Maxsize*sizeof(int));
    if(!Q->elem)
      exit(0);
    Q->front=Q->rear=0;
    return;
}
void destroyqueue(queue *Q)
{
    if(Q->elem)
        free(Q->elem);
    Q->elem=NULL;
    Q->front=Q->rear=0;
    return;
}
void clearqueue(queue *Q)
{
    Q->front=Q->rear=0;
    return;
}
int queueEmpty(queue Q)
{
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}
int queuelength(queue Q)
{
    return (Q.rear-Q.front+Maxsize)%Maxsize;
}
int enqueue(queue *Q,int e)
{
    if((Q->rear+1)%Maxsize==Q->front)
        return 0;
    Q->elem[Q->rear]=e;
    Q->rear=(Q->rear+1)%Maxsize;
    return 1;
}
int dequeue(queue*Q)
{
    int e;
    if(Q->front==Q->rear)
      return 0;
    e=Q->elem[Q->front];
    Q->front=(Q->front+1)%Maxsize;
    return 1;
}
void outputqueue(queue Q)
{
    while(Q.front!=Q.rear)
    {
        printf("%d ",Q.elem[Q.front]);
        Q.front=(Q.front+1)%Maxsize;
    }
    return;
}
int main()
{
    int n,i,choice,node;
    queue Q;
    initqueue(&Q);
    printf("请输入循环队列初始节点数:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        enqueue(&Q,i);
    choice=maininterface();
    switch(choice)
    {
        case 1:scanf("%d",&node);enqueue(&Q,node);outputqueue(Q);break;
        case 2:dequeue(&Q);outputqueue(Q);break;
        case 3:printf("队列长度为%d",queuelength(Q));break;
        case 4:outputqueue(Q);break;
        case 0:exit(0);
    }

    return 0;
}*/
/*#include<stdio.h>//杨辉三角
#include<stdlib.h>
#include<windows.h>
#define Maxsize 100
typedef struct node
{
    int *elem;
    int front;
    int rear;
}queue;
void initqueue(queue *Q)
{
    Q->elem=(int*)malloc(Maxsize*sizeof(int));
    if(!Q->elem)
      exit(0);
    Q->front=Q->rear=0;
    return;
}
int queueEmpty(queue *Q)
{
    if(Q->front==Q->rear)
        return 1;
    else
        return 0;
}
int gethead(queue *Q,int *x)
{
    if(Q->front==Q->rear)
        return 0;
    else
        *x=Q->elem[Q->front];
    return 1;
}
int queuelength(queue Q)
{
    return (Q.rear-Q.front+Maxsize)%Maxsize;
}
int enqueue(queue *Q,int e)
{
    if((Q->rear+1)%Maxsize==Q->front)
        return 0;
    Q->elem[Q->rear]=e;
    Q->rear=(Q->rear+1)%Maxsize;
    return 1;
}
int dequeue(queue*Q,int *e)
{
    if(Q->front==Q->rear)
      return 0;
    *e=Q->elem[Q->front];
    Q->front=(Q->front+1)%Maxsize;
    return 1;
}
void yanghuitriangle(queue *Q,int N)
{
    int n,x,temp,i;
    enqueue(Q,1);
    for(n=2;n<=N;n++)
    {
        enqueue(Q,1);
        for(i=1;i<=n-2;i++)
        {
            dequeue(Q,&temp);
            printf("%d ",temp);
            gethead(Q,&x);
            temp+=x;
            enqueue(Q,temp);
        }
        dequeue(Q,&x);
        printf("%d ",x);
        enqueue(Q,1);
        printf("\n");
    }
    while(!queueEmpty(Q))
    {
        dequeue(Q,&x);
        printf("%d ",x);
    }
    return;

}
int main()
{
    int n,i;
    queue Q;
    initqueleue(&Q);
    printf("请输入杨辉三角的输出行数:\n");
    scanf("%d",&n);
    yanghuitriangle(&Q,n);
    return 0;
}*/

