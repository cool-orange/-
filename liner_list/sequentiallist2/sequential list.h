#include<stdio.h>
#define list_init_size 100
#define listincrement 10

typedef struct
{
    int *elem;
    int length;
    int listsize;
}sqlist;

void againmalloc(sqlist *L)
{
    int *elemsecond;
    elemsecond=(int *)realloc(L->elem,(L->listsize+listincrement)*sizeof(int));
    if(!elemsecond)
        exit(0);
    L->elem=elemsecond;
    L->listsize+=listincrement;
    return;
}
void initlist(sqlist *L)
{
    L->elem=(int*)malloc(list_init_size*sizeof(int));
    if(!L->elem)
        exit(0);
    L->length=0;
    L->listsize=list_init_size;
    return ;
}
void outputlist(sqlist *L)
{
    int i;
    for(i=0;i<L->length;i++)
        printf("%d ",L->elem[i]);
    return ;
}
void insertlast(sqlist *L,int a)
{
    if(L->length>=L->listsize)
        againmalloc(L);
    L->elem[L->length]=a;
    L->length++;
    return ;
}
void destroylist(sqlist*L)
{
    if(L->elem)
        free(L->elem);
}
