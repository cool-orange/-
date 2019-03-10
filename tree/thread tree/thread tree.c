   #include<stdio.h>
#include<stdlib.h>                      //Link代表指向左右孩子指针，Thread代表前驱和后继
typedef enum{Link,Thread} pointertag;  //enum枚举函数的运用 系统自定义从0开始
typedef struct bitnode
{
    char data;
    struct bitnode *lchild,*rchild;
    pointertag  ltag;//枚举变量
    pointertag  rtag;
}bitnode,*bitree;
bitree pre;
void creatbitree (bitree *T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        *T=NULL;
    else
    {
      *T=(bitree)malloc(sizeof(struct bitnode));
      (*T)->data=ch;
      (*T)->ltag=Link;
      (*T)->rtag=Link;
      creatbitree(&(*T)->lchild);
      creatbitree(&(*T)->rchild);
    }
}
void inthreading(bitree p)//中序遍历线索化
{
    if(p)
    {
        inthreading(p->lchild);
        if(!p->lchild)//没有左孩子
        {
            p->ltag=Thread;
            p->lchild=pre;
        }
        if(!pre->rchild)
        {
            pre->rtag=Thread;
            pre->rchild=p;
        }
        pre=p;
        inthreading(p->rchild);
      }
}
void inorderthreading(bitree *head,bitree T)
{
    *head=(bitree)malloc(sizeof(struct bitnode));
    if(!(*head))
        return;
    (*head)->ltag=Link;
    (*head)->rtag=Thread;
    (*head)->rchild=*head;
    if(!T)
        (*head)->lchild=*head;
    else
    {
        (*head)->lchild=T;
        pre=*head;
        inthreading(T);
        pre->rchild=*head;
        pre->rtag=Thread;
        (*head)->rchild=pre;
    }

}
void inordertraverse(bitree head)//中序遍历
{
    bitree p;
    p=head->lchild;
    while(p!=head)
    {
        while(p->ltag==Link)
          p=p->lchild;
        printf("%c",p->data);
        while(p->rtag==Thread&&p->rchild!=head)
        {
            p=p->rchild;
            printf("%c",p->data);
        }
        p=p->rchild;
    }
}
int main()
{
    bitree T;
    bitree head;
    printf("请输入前序遍历线索树:\n");
    creatbitree(&T);
    inorderthreading(&head,T);
    printf("输出中序二叉线索树:\n");
    inordertraverse(head);
    return 0;
}

