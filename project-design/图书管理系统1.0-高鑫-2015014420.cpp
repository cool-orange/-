#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

struct date
{
    int day;
    int month;
    int year;
};

typedef struct book
{
    int booknum;
    int total;
    char bookname[50];
    char author[50];
    char publisher[50];
    char kind[50];
    struct date publishtime;
    struct book *next;
}book_type;

typedef struct student
{
    char name[20];
    char borrowbook[20];
    int  id;
    struct student *next;
}student;

student sd;
book_type bk;



int maininterface()//可视化界面
{
    int n;
    printf("\n\n\n\t\t\t------------欢迎进入小规模图书管理系统-----------\n");
    printf("\n\t\t\t\t\t1:<图书登记>\n");
    printf("\n\t\t\t\t\t2:<图书查询>\n");
    printf("\n\t\t\t\t\t3:<图书分类>\n");
    printf("\n\t\t\t\t\t4:<借阅登记>\n");
    printf("\n\t\t\t\t\t5:<归还登记>\n");
    printf("\n\t\t\t\t\t6:<退出系统>\n");
    scanf("%d",&n);
    return n;
}
void check()//图书登记
{

    FILE *fp;
    int n=0;
    book_type bk;
    printf("\n\t\t\t\t\t------------图书登记-----------\n");
    while(n<1)
    {
        printf("请输入书号\n");
        scanf("%d",&bk.booknum);
        printf("请输入书本数量\n");
        scanf("%d",&bk.total);
        printf("请输入书名\n");
        scanf("%s",bk.bookname);
        printf("请输入作者\n");
        scanf("%s",bk.author);
        printf("请输入出版社\n");
        scanf("%s",bk.publisher);
        printf("请输入图书类别\n");
        scanf("%s",bk.kind);
        printf("请输入出版日期\n");
        scanf("%d %d %d",&bk.publishtime.day,&bk.publishtime.month,&bk.publishtime.year);
        printf("\n\t\t\t请选择(1:确定\t0:重新输入):");
        scanf("%d",&n);
    }
    if(n==1)
    {
        fp=fopen("text.txt","a+");
        fprintf(fp,"%d %d %s %s %s %s %d %d %d\n",bk.booknum,bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,bk.publishtime.day,
                bk.publishtime.month,bk.publishtime.year);
        fclose (fp);
    }
    system("cls");
    printf("\n\t\t\t\t\t\t------------^_^ 成功录入-----------\n\n");
    printf("请选择(1:返回主页\t2:继续输入另一本图书\t0:退出系统):\n");
    scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");check();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t抱歉！没这个功能(；′⌒`)\n");getch();system("cls");
   }

}
void findone()//根据书号查询
{
     FILE *fp;
     int booknum,i,j=0,n;
     book_type bk;
     fp=fopen("text.txt","r+");
     printf("请输入书号:");
     scanf("%d",&booknum);
     for(i=0;fscanf(fp,"%d%d%s%s%s%s%d%d%d",&bk.booknum,&bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,&bk.publishtime.day,
                &bk.publishtime.month,&bk.publishtime.year)!=EOF;i++)
     {
         if(booknum==bk.booknum)
            {printf("这本书的书号是%d,书名是%s,作者是%s,出版社是%s,出版日期是%d %d %d",bk.booknum,bk.bookname,bk.author,bk.publisher,bk.publishtime.day,
                bk.publishtime.month,bk.publishtime.year);
                j=1;
                break;
            }
     }
     if(j==0)
     printf("图书馆内暂无该书");
     printf("\n\n\n");
     printf("请选择(1:返回主页\t2:继续输入另一个书号\t0:退出系统):\n");
     scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");findone();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t抱歉！没这个功能(；′⌒`)\n");getch();system("cls");break;
   }
}
void findtwo()//根据书名查询
{
    FILE *fp;
    char bookname[20];
    int i=0,j=0,n;
    fp=fopen("text.txt","r+");
    printf("请输入书名:\n");
    scanf("%s",bookname);
    for(i=0;fscanf(fp,"%d%d%s%s%s%s%d%d%d",&bk.booknum,&bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,&bk.publishtime.day,
                &bk.publishtime.month,&bk.publishtime.year,1,fp)!=EOF;i++)
    {
      if(strcmp(bookname,bk.bookname)==0)
      {
        printf("这本书的书号是%d,书名是%s,作者是%s,出版社是%s,出版日期是%d %d %d",bk.booknum,bk.bookname,bk.author,bk.publisher,bk.publishtime.day,
                bk.publishtime.month,bk.publishtime.year);
                j=1;
        break;
      }
    }
    if(j==0)
    printf("图书馆暂无此书");
    printf("\n\n\n");
    printf("请选择(1:返回主页\t2:继续输入另一本图书\t0:退出系统):\n");
    scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");findtwo();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t抱歉！没这个功能(；′⌒`)\n");getch();system("cls");break;
   }
    fclose(fp);

}
void inquiry()//图书查询
{
    int n;
    printf("\n\t\t\t\t\t------------图书查询-----------\n");
    printf("0:<返回>\n");
    printf("1:根据书号查询图书信息\n");
    printf("2:根据书名查询图书信息\n");
    scanf("%d",&n);

    switch(n)
    {
      case 1:system("cls");findone();break;
      case 2:system("cls");findtwo();break;
      case 0:system("cls");break;
      default:printf("输入非法");getch();system("cls");
    }

}
void judge()//根据书名判断类型
{
    FILE *fp;
    char bookname[20];
    int i=0,j=0,n;
    fp=fopen("text.txt","r+");
    printf("请输入书名\n");
    scanf("%s",bookname);
    for(i=0;fscanf(fp,"%d%d%s%s%s%s%d%d%d",&bk.booknum,&bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,&bk.publishtime.day,
                &bk.publishtime.month,&bk.publishtime.year)!=EOF;i++)
    {
        if(strcmp(bookname,bk.bookname)==0)
        {
            printf("这本书为%s类",bk.kind);
            j=1;
            break;
        }
    }
    if(j==0)
        printf("图书馆暂无此书");
         printf("\n\n\n");
     printf("请选择(1:返回主页\t2:继续输入另一本图书\t0:退出系统):\n");
     scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");judge();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t输入非法\n");getch();system("cls");break;
   }
}
void judegeone()//根据类型输出所有书
{
    FILE *fp;
    char type[20];
    int i=0,j=0,n;
    fp=fopen("text.txt","r+");
    printf("请输入书的类型\n");
    scanf("%s",type);
    printf("%s类的书：\n\n");
    for(i=0;fscanf(fp,"%d%d%s%s%s%s%d%d%d",&bk.booknum,&bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,&bk.publishtime.day,
                &bk.publishtime.month,&bk.publishtime.year)!=EOF;i++)
    {
        if(strcmp(type,bk.kind)==0)
        {
            printf("%s\n",bk.bookname);
            j=1;
        }
    }
    if(j==0)
        printf("图书馆无此类型的书");
         printf("\n\n\n");
     printf("请选择(1:返回主页\t2:继续输入另一种类型\t0:退出系统):\n");
     scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");judegeone();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t输入非法\n");getch();system("cls");break;
   }


}
void classify()//图书分类
{
    int n;
    printf("\n\t\t\t\t\t------------图书分类-----------\n");
    printf("0:<返回>\n");
    printf("1:根据书名判断书的类型\n");
    printf("2:根据类型输出该类型所有的书\n");
    scanf("%d",&n);

    switch(n)
    {
      case 1:system("cls");judge();break;
      case 2:system("cls");judegeone();break;
      case 0:system("cls");break;
      default:printf("输入非法");getch();system("cls");
    }

}
book_type*createnode1(book_type *head)//以text文件创建链表
{
    FILE *fp;
    int i;
    book_type *p,*q;
    p=head;
    if((fp=fopen("text.txt","r+"))==NULL)
       {
         printf("文件为空！");
         exit(0);
       }
    else
  {
    while(!feof(fp))
    {
     q=(book_type*)malloc(sizeof(book_type));
     fscanf(fp,"%d%d%s%s%s%s%d%d%d",&q->booknum,&q->total,q->bookname,q->author,q->publisher,q->kind,&q->publishtime.day,
                &q->publishtime.month,&q->publishtime.year);
     p->next=q;
     p=q;
    }
    p->next=NULL;
  }
  fclose(fp);
  return head;
}
student *createnode2(student *head)//以student文件创建链表
{
    FILE *fp;
    int i;
    student *p,*q;
    p=head;
    if((fp=fopen("student.txt","r+"))==NULL)
       {
         printf("文件为空！");
         exit(0);
       }

    else
    {
     while(!feof(fp))
     {
       q=(student*)malloc(sizeof(student));
       fscanf(fp,"%s %d %s\n",q->name,&q->id,q->borrowbook);
       p->next=q;
       p=q;
     }
     p->next=NULL;
    }
  return head;
}
void fprintf(book_type *head)//将新链表输入到text文件中
{
    book_type *p;
    FILE *fp;
    if((fp=fopen("text.txt","w+"))==NULL)
        exit(0);
    else
    {
        for(p=head->next;p->next!=NULL;p=p->next)
        {
            fprintf(fp,"%d %d %s %s %s %s %d %d %d\n",p->booknum,p->total,p->bookname,p->author,p->publisher,p->kind,p->publishtime.day,
                p->publishtime.month,p->publishtime.year);
        }
        fclose(fp);
    }

}
void fprintf1(student *head)//将新链表输入到student文件中
{
    student *p;
    FILE *fp;
    if((fp=fopen("student.txt","w+"))==NULL)
        exit(0);
    else
    {
        for(p=head->next;p!=NULL;p=p->next)
        {
            fprintf(fp,"%s %d %s\n",p->name,p->id,p->borrowbook);
        }
        fclose(fp);
    }

}
void borrow(book_type *head)//借阅登记
{
    system("cls");
    printf("\n\t\t\t\t\t------------借阅登记-----------\n");
    int n=0,m=0;
    char bookname[20];
    FILE *fp;
    printf("请输入你所需要的书名：\n");
    scanf("%s",bookname);
    book_type *p;
    for(p=head->next;p!=NULL;p=p->next)
    {
        if(strcmp(p->bookname,bookname)==0&&p->total>0)
        {
            m=1;
            while(n<1)
            {
             printf("\n^_^，库存还有，你可以借这本书看！\n\n");
             printf("请输入你的姓名：\n");
             scanf("%s",sd.name);
             printf("请输入你的学号：\n");
             scanf("%d",&sd.id);
             printf("\n\t\t\t请选择(1:确定\t0:重新输入):");
             scanf("%d",&n);
            }
            if(n==1)
            {
            fp=fopen("student.txt","a+");
            strcpy(sd.borrowbook,p->bookname);
            fprintf(fp,"%s %d %s\n",sd.name,sd.id,sd.borrowbook);
            fclose (fp);
            }
            if(p->total>0)
            {
             p->total--;
            }
            else
                printf("图书馆此书暂无库存。");
            fprintf(head);
            system("cls");
            printf("\n\t\t\t\t\t\t------------^_^ 借阅成功-----------\n\n");
            printf("请选择(1:返回主页\t2:继续借阅另一本书\t0:退出系统):\n");
            scanf("%d",&n);
            break;
        }

    }
    switch(n)
        {
            case 1:system("cls");break;
            case 2:system("cls");borrow(head);break;
            case 0:exit(0);
            default:printf("\n\n\n\n\t\t\t\t\t\t还没这个功能(；′⌒`)\n");getch();system("cls");
        }
    if(m==0)
    {
        printf("图书馆暂无此书或输入信息有误(；′⌒`)");
        getch();system("cls");
    }

}
void sendback(student *head)//归还登记
{
    system("cls");
    printf("\n\t\t\t\t\t------------归还登记-----------\n");
    int n,m=0;
    char bookname[20];
    char name[20];
    FILE *fp;
    book_type *r,*s;
    book_type *head1;
    head1=(book_type*)malloc(sizeof(book_type));
    head1=createnode1(head1);
    printf("请输入姓名：\n");
    scanf("%s",name);
    printf("请输入书名：\n");
    scanf("%s",bookname);
    student *p,*q;
    q=head;
    for(p=head->next;p!=NULL;p=p->next,q=q->next)
    {
        if(strcmp(q->next->borrowbook,bookname)==0&&strcmp(q->next->name,name)==0)
        {
                r=head1;
                for(s=head1->next;s!=NULL;s=s->next,r=r->next)
               {
                 if(strcmp(s->bookname,bookname)==0)
                     s->total++;
               }
                fprintf(head1);
                q->next=p->next;
                free(p);
                fprintf1(head);
                m=1;
                system("cls");
                printf("\n\t\t\t\t\t\t------------^_^ 归还成功-----------\n\n");
                printf("请选择(1:返回主页\t2:继续归还另一本书\t0:退出系统):\n");
                scanf("%d",&n);
                break;
        }
    }
    if(m==1)
    {
     switch(n)
     {
        case 1:system("cls");break;
        case 2:system("cls");sendback(head);break;
        case 0:exit(0);
        default:printf("\n\n\n\n\t\t\t\t\t\t抱歉！没这个功能(；′⌒`)\n");getch();system("cls");
     }
    }
    if(m==0)
    {
        printf("你没有借这本书或信息输入有误(；′⌒`)");
        getch();system("cls");
    }
}
int main()//主函数
{
   int m=0;
   book_type *head;
   student *head2;
   head=(book_type*)malloc(sizeof(book_type));
   head2=(student *)malloc(sizeof(student));
   while(m<=5)
   {
       m=maininterface();
       switch(m)
       {
           case 1:system("cls");check();break;
           case 2:system("cls");inquiry();break;
           case 3:system("cls");classify();break;
           case 4:system("cls");head=createnode1(head);borrow(head);break;
           case 5:system("cls");head2=createnode2(head2);sendback(head2);break;
           case 6:exit(0);
           default :system("cls");printf("\n\n\n\n\t\t\t\t\t\t输入非法\n");getch();system("cls");
       }
   }
   return 0;
}
