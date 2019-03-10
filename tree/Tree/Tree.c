#include<stdio.h>
#include<stdlib.h>
#define Maxsize 2000
typedef struct bitnode//递归遍历
{
    char data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;
int i;
void creatbitree(bitree *T,char ch[])//前序遍历创建树
{
     if(ch[i]=='#')
    {
        *T=NULL;
        if(i==0)
            return;
        i++;
    }
    else
    {
      *T=(bitree)malloc(sizeof(struct bitnode));
      (*T)->data=ch[i];
      i++;
      creatbitree(&(*T)->lchild,ch);
      creatbitree(&(*T)->rchild,ch);
    }
}
//前序遍历
void traverse (bitree T)
{
    if(T==NULL)
        return;
    printf("%c",T->data);
    traverse(T->lchild);
    traverse(T->rchild);

}
//中序遍历
void  inordertraverse(bitree T)
{
    if(T==NULL)
        return;
    inordertraverse(T->lchild);
    printf("%c",T->data);
    inordertraverse(T->rchild);
}
//后序遍历
void postordertraverse(bitree T)
{
    if(T==NULL)
        return;
    postordertraverse(T->lchild);
    postordertraverse(T->rchild);
    printf("%c",T->data);
}
int main()
{
    char ch[Maxsize];
    while(scanf("%s",&ch)!=EOF)
    {
      i=0;
      bitree T;
      creatbitree(&T,ch);
      if(T==NULL)
      {
        printf("  \n");
      }
      else
      {
        traverse(T);
        printf(" ");
        inordertraverse(T);
        printf(" ");
        postordertraverse(T);
        printf(" ");
        printf("\n");
      }
    }
}
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>//根据前序和中序表达式
typedef struct bitnode
{
    char data;
    struct bitnode *lchild,*rchild;

}bitnode,*bitree;
bitree creatbitree(char a[],char b[])
{
    int i;
    char root=a[0];
    bitree t;
    int a_len=strlen(a);
    int b_len=strlen(b);
    if(a_len==0||b_len==0)
    {
        t=NULL;
        return t;
    }
    t=(bitree)malloc(sizeof(bitnode));
    t->data=a[0];
    t->lchild=NULL;
    t->rchild=NULL;
    if(a_len==1)
        return t;
    if(b_len==1)
        return t;
    char left_a[2000];
    char right_a[2000];
    char left_b[2000];
    char right_b[2000];
    memset(left_a,0,2000);
    memset(right_a,0,2000);
    memset(left_b,0,2000);
    memset(right_b,0,2000);
    for(i=0;i<b_len;i++)
        if(root==b[i])
            break;
    if(i>0)
    {
        memcpy(left_b,b,i);
        memcpy(left_a,a+1,i);
        t->lchild=creatbitree(left_a,left_b);
        memcpy(right_a, a+i+1, a_len-i-1);
        memcpy(right_b, b+i+1, b_len-i-1);
        t->rchild = creatbitree(right_a,right_b);
    }
    return t;
}
void postordertraverse(bitree T)
{
    if(T==NULL)
        return;
    postordertraverse(T->lchild);
    postordertraverse(T->rchild);
    printf("%c",T->data);
}
int main()
{
    char a[2000],b[2000];
    bitree T;
    memset(a, 0, 2000);
    memset(b, 0, 2000);
    printf("请输入前序遍历:\n");
    gets(a);
    printf("请输入后序遍历:\n");
    gets(b);
    T=creatbitree(a,b);
    postordertraverse(T);
    return 0;
}*/
/*#include<stdio.h>
#include<stdio.h>
#include<string.h>//根据中序遍历和后序遍历
typedef struct bitnode
{
    char data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;
bitree creatbitree(char a[],char b[])
{
    int i;
    char root;
    bitree t;
    int a_len=strlen(a);
    int b_len=strlen(b);
    root=b[b_len-1];
    if(a_len==0||b_len==0)
    {
        t=NULL;
        return t;
    }
    t=(bitree)malloc(sizeof(bitnode));
    t->data=b[b_len-1];
    t->lchild=NULL;
    t->rchild=NULL;
    if(a_len==1)
        return t;
    if(b_len==1)
        return t;
    char left_a[2000];
    char right_a[2000];
    char left_b[2000];
    char right_b[2000];
    memset(left_a,0,2000);
    memset(right_a,0,2000);
    memset(left_b,0,2000);
    memset(right_b,0,2000);
    for(i=0;i<a_len;i++)
        if(root==a[i])
            break;
    if(i==0)
    {
        memcpy(right_a,a+1,a_len-1);
        memcpy(right_b,b,b_len-1);
        t->lchild=NULL;
        t->rchild = creatbitree(right_a,right_b);
    }
    if(i>0)
    {
        memcpy(left_a,a,i);
        memcpy(left_b,b,i);
        t->lchild=(left_a,left_b);
        memcpy(right_a, a+i+1, a_len-i-1);
        memcpy(right_b, b+i, b_len-i-1);
        t->rchild = creatbitree(right_a,right_b);
    }
    return t;
}
void traverse(bitree T)
{
    if(T==NULL)
        return;
    printf("%c",T->data);
    traverse(T->lchild);
    traverse(T->rchild);
    return;
}
int main()
{
    bitree T;
    char a[2000],b[2000];
    printf("请输入中序遍历树:\n");
    gets(a);
    printf("请输入后序遍历树:\n");
    gets(b);
    T=creatbitree(a,b);
    traverse(T);
    return 0;
}*/
