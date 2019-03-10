/*#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct node
{
    int  data;
    struct node *next;
}Qnode;
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
    printf("\t\t\t\t\t\t|        5.返回队首元素    |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|        0.退出程序        |\n");
    printf("\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t|--------------------------|\n");
    scanf("%d",&n);
    return n;
}
typedef struct
{
    Qnode*front;
    Qnode*rear;
}linkqueue;
void initqueue(linkqueue *Q)
{
    Q->front=Q->rear=(Qnode*)malloc(sizeof(Qnode));
    if(!Q->front)
        exit(0);
    Q->front->next=NULL;
    return;
}
void destroyqueue(linkqueue *Q)
{
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return;
}
void queueEmpty(linkqueue Q)
{
    if(Q.front==Q.rear)
        return 0;
    else
        return 1;
}
void clearqueue(linkqueue*Q)
{
    Qnode*p;
    while(Q->front!=Q->rear)
    {
       p=Q->front->next;
       if(p!=Q->rear)
       {
           Q->front->next=p->next;
           free(p);
       }
       else
       {
           Q->rear=Q->front;
           free(p);
       }
    }
    return;
}
int queuelength(linkqueue Q)
{
    int i=0;
    Qnode *p;
    p=Q.front->next;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;

}
int gethead(linkqueue Q)
{
    Qnode *p;
    p=Q.front->next;
    return p->data;
}
int enqueue(linkqueue *Q,int e)
{
    Qnode *p;
    p=(Qnode*)malloc(sizeof(Qnode));
    if(!p)
        exit(0);
    p->data=e;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return 1;
}
int dequeue(linkqueue *Q)
{
    int e;
    Qnode *p;
    if(Q->front==Q->rear)
        return 0;
    p=Q->front->next;
    e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    p->next=NULL;
    return 1;
}
void outputqueue(linkqueue Q)
{
    Qnode *p;
    p=Q.front->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return;
}
int main()
{
    int i,choice,node,n;
    linkqueue Q;
    initqueue(&Q);
    printf("请输入初始节点个数:\n");
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
        case 5:printf("队首元素为%d",gethead(Q));
        case 0:exit(0);
    }
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
typedef struct event
{
    int occurtime;
    int type;
    struct event *next;
}event,elemtype;
typedef struct
{
    event *head;
    int len;
}eventlist;
//链表结构体
typedef struct node
{
    int arrivaltime;//到达时刻
    int duration;//办理业务所需时间
    struct node *next;
}qelemtype;
typedef struct
{
    qelemtype *front,*rear;
}linkqueue;
//队列结构体
eventlist ev;
event en;
linkqueue q[5];
qelemtype  customer;
int totaltime,customernum;
int closetime=20;
//全局变量
/*int cmp(event a,event b)
{
    if(a.occurtime==b.occurtime)
        return 0;
    else
        return (a.occurtime-b.occurtime)/abs(a.occurtime-b.occurtime);
}*/
void printlist(eventlist L)
{
    event *p;
    p=L.head->next;
    printf("Current Eventlist is：\n");
    if(!p)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        while(p!=NULL)
        {
            printf("occurtime:%d,event type:%d\n",p->occurtime,p->type);
            p=p->next;
        }
    }
    return;
}
void initlist(eventlist*L)
{
    L->head=(event*)malloc(sizeof(event));
    if(!L->head)
        exit(0);
    L->head->next=NULL;
    L->len=0;
    return;
}
int listempty(eventlist ev)
{
    if(ev.head->next==NULL)
        return 1;
    else
        return 0;
}
void orderinsert(eventlist*ev,event e)
{
    event *p,*q,*newnode;
    newnode=(event*)malloc(sizeof(event));
    *newnode=e;
    //printf("%d!",flag);
    p=ev->head;
    q=p->next;
    while(q!=NULL&&q->occurtime<newnode->occurtime)
    {
        //printf("1");
        p=q;
        q=q->next;
    }
    p->next=newnode;
    newnode->next=q;
    return;
}
void delfirst(eventlist *ev,event *en)
{
    event*p;
    p=ev->head->next;
    if(!p)
        return;
    ev->head->next=p->next;
    *en=*p;
    free(p);
    p->next=NULL;
    return;
}
void initqueue(linkqueue *Q)
{
    Q->front=Q->rear=(qelemtype*)malloc(sizeof(qelemtype));
    if(!Q->front)
        exit(0);
    Q->front->next=NULL;
    return;

}
void openforday()
{
    int i;
    totaltime=0;customernum=0;
    initlist(&ev);
    en.occurtime=0,en.type=0;
    orderinsert(&ev,en);
    for(i=1;i<=4;i++)
        initqueue(&q[i]);
}
void random(int *durtime,int *intertime)
{
    *intertime=rand()%5+1;
    *durtime=rand()%30+1;
    return;
}
int queuelength(linkqueue Q)
{
    int i=0;
    qelemtype *p;
    p=Q.front->next;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    //printf("%d!",i);
    return i;
}
int mininum()
{
    int pos,i,t;
    t=queuelength(q[1]);
    pos=1;
    for(i=2;i<=4;i++)
    {
        if(queuelength(q[i])<t)
        {
            t=queuelength(q[i]);
            pos=i;
        }
    }
    return pos;
}
void enqueue(linkqueue*q,qelemtype e)
{
    qelemtype *p;
    p=(qelemtype*)malloc(sizeof(qelemtype));
    if(!p)
        exit(0);
    *p=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return ;
}
void customerarrived()
{
    event p,m;
    qelemtype e;
    int durtime,intertime,t,i;
    ++customernum;
    random(&durtime,&intertime);
    //printf("%d %d\n",durtime,intertime);
    t=en.occurtime+intertime;//下一个顾客到达时刻
    //printf("%d",t);
    if(t<closetime)
    {
        printf("A new customer will arrive at:%d\n",en.occurtime);
        p.occurtime=t;p.type=0;
        orderinsert(&ev,p);
    }
    i=mininum();
    //printf("%d",i);
    e.arrivaltime=en.occurtime;
    e.duration=durtime;
    enqueue(&q[i],e);
    m.occurtime=en.occurtime+durtime;
    m.type=i;
    //printf("%d",i);
    if(queuelength(q[i])==1)
    {
        //printf("1");
        orderinsert(&ev,m);
    }
}
void delqueue(linkqueue *q,qelemtype *e)
{
    qelemtype *p;
    if(q->front==q->rear)
        return ;
    p=q->front->next;
    *e=*p;
   // printf("%d",e->arrivaltime);
    q->front->next=p->next;
    if(q->rear==p)
        q->rear=q->front;
    free(p);
    p->next=NULL;
    return;
}
int queueempty(linkqueue*q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
void gethead(linkqueue*q,qelemtype*e)
{
    if(queueempty(q))
        exit(0);
    *e=*(q->front->next);
}
void customerdeparture()
{
    int i;
    i=en.type;
    event m;
    delqueue(&q[i],&customer);
    //printf("%d %d",customer.arrivaltime,customer.duration);
    printf("A customer leaves at:%d\n",en.occurtime);
    totaltime+=en.occurtime-customer.arrivaltime;
    if(!queueempty(&q[i]))
    {
        gethead(&q[i],&customer);
        //printf("%d %d",customer.arrivaltime,customer.duration);
        m.occurtime=en.occurtime+customer.duration;
        m.type=i;
        orderinsert(&ev,m);
    }
    return;
}
void traverse(linkqueue q)
{
    qelemtype *p;
    p=q.front->next;
    if(!p)
        printf("queue is empty");
    while(p)
    {
        printf("(%d %d)",p->arrivaltime,p->duration);
        p=p->next;
    }
    printf("\n");
}
void printqueue()
{
    int i;
     //printf("%d",queuelength(q[1]));
    for(i=1;i<=4;i++)
    {
        printf("queue %d have %d customer:",i,queuelength(q[i]));
        traverse(q[i]);
    }
    printf("\n");
}
void bank_simulation()
{
    openforday();
    while(!listempty(ev))
    {
        delfirst(&ev,&en);
        //printf("%d!",en.occurtime);
        if(en.type==0)
            customerarrived();
        else
            customerdeparture();
        printlist(ev);
        //printf("1");
        printqueue();
    }
    printf("The average time is %d \n",totaltime/customernum);
    return;
}
int main()
{
    bank_simulation();
    return 0;
}

