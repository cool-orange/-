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



int maininterface()//���ӻ�����
{
    int n;
    printf("\n\n\n\t\t\t------------��ӭ����С��ģͼ�����ϵͳ-----------\n");
    printf("\n\t\t\t\t\t1:<ͼ��Ǽ�>\n");
    printf("\n\t\t\t\t\t2:<ͼ���ѯ>\n");
    printf("\n\t\t\t\t\t3:<ͼ�����>\n");
    printf("\n\t\t\t\t\t4:<���ĵǼ�>\n");
    printf("\n\t\t\t\t\t5:<�黹�Ǽ�>\n");
    printf("\n\t\t\t\t\t6:<�˳�ϵͳ>\n");
    scanf("%d",&n);
    return n;
}
void check()//ͼ��Ǽ�
{

    FILE *fp;
    int n=0;
    book_type bk;
    printf("\n\t\t\t\t\t------------ͼ��Ǽ�-----------\n");
    while(n<1)
    {
        printf("���������\n");
        scanf("%d",&bk.booknum);
        printf("�������鱾����\n");
        scanf("%d",&bk.total);
        printf("����������\n");
        scanf("%s",bk.bookname);
        printf("����������\n");
        scanf("%s",bk.author);
        printf("�����������\n");
        scanf("%s",bk.publisher);
        printf("������ͼ�����\n");
        scanf("%s",bk.kind);
        printf("�������������\n");
        scanf("%d %d %d",&bk.publishtime.day,&bk.publishtime.month,&bk.publishtime.year);
        printf("\n\t\t\t��ѡ��(1:ȷ��\t0:��������):");
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
    printf("\n\t\t\t\t\t\t------------^_^ �ɹ�¼��-----------\n\n");
    printf("��ѡ��(1:������ҳ\t2:����������һ��ͼ��\t0:�˳�ϵͳ):\n");
    scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");check();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t��Ǹ��û�������(�����`)\n");getch();system("cls");
   }

}
void findone()//������Ų�ѯ
{
     FILE *fp;
     int booknum,i,j=0,n;
     book_type bk;
     fp=fopen("text.txt","r+");
     printf("���������:");
     scanf("%d",&booknum);
     for(i=0;fscanf(fp,"%d%d%s%s%s%s%d%d%d",&bk.booknum,&bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,&bk.publishtime.day,
                &bk.publishtime.month,&bk.publishtime.year)!=EOF;i++)
     {
         if(booknum==bk.booknum)
            {printf("�Ȿ��������%d,������%s,������%s,��������%s,����������%d %d %d",bk.booknum,bk.bookname,bk.author,bk.publisher,bk.publishtime.day,
                bk.publishtime.month,bk.publishtime.year);
                j=1;
                break;
            }
     }
     if(j==0)
     printf("ͼ��������޸���");
     printf("\n\n\n");
     printf("��ѡ��(1:������ҳ\t2:����������һ�����\t0:�˳�ϵͳ):\n");
     scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");findone();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t��Ǹ��û�������(�����`)\n");getch();system("cls");break;
   }
}
void findtwo()//����������ѯ
{
    FILE *fp;
    char bookname[20];
    int i=0,j=0,n;
    fp=fopen("text.txt","r+");
    printf("����������:\n");
    scanf("%s",bookname);
    for(i=0;fscanf(fp,"%d%d%s%s%s%s%d%d%d",&bk.booknum,&bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,&bk.publishtime.day,
                &bk.publishtime.month,&bk.publishtime.year,1,fp)!=EOF;i++)
    {
      if(strcmp(bookname,bk.bookname)==0)
      {
        printf("�Ȿ��������%d,������%s,������%s,��������%s,����������%d %d %d",bk.booknum,bk.bookname,bk.author,bk.publisher,bk.publishtime.day,
                bk.publishtime.month,bk.publishtime.year);
                j=1;
        break;
      }
    }
    if(j==0)
    printf("ͼ������޴���");
    printf("\n\n\n");
    printf("��ѡ��(1:������ҳ\t2:����������һ��ͼ��\t0:�˳�ϵͳ):\n");
    scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");findtwo();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t��Ǹ��û�������(�����`)\n");getch();system("cls");break;
   }
    fclose(fp);

}
void inquiry()//ͼ���ѯ
{
    int n;
    printf("\n\t\t\t\t\t------------ͼ���ѯ-----------\n");
    printf("0:<����>\n");
    printf("1:������Ų�ѯͼ����Ϣ\n");
    printf("2:����������ѯͼ����Ϣ\n");
    scanf("%d",&n);

    switch(n)
    {
      case 1:system("cls");findone();break;
      case 2:system("cls");findtwo();break;
      case 0:system("cls");break;
      default:printf("����Ƿ�");getch();system("cls");
    }

}
void judge()//���������ж�����
{
    FILE *fp;
    char bookname[20];
    int i=0,j=0,n;
    fp=fopen("text.txt","r+");
    printf("����������\n");
    scanf("%s",bookname);
    for(i=0;fscanf(fp,"%d%d%s%s%s%s%d%d%d",&bk.booknum,&bk.total,bk.bookname,bk.author,bk.publisher,bk.kind,&bk.publishtime.day,
                &bk.publishtime.month,&bk.publishtime.year)!=EOF;i++)
    {
        if(strcmp(bookname,bk.bookname)==0)
        {
            printf("�Ȿ��Ϊ%s��",bk.kind);
            j=1;
            break;
        }
    }
    if(j==0)
        printf("ͼ������޴���");
         printf("\n\n\n");
     printf("��ѡ��(1:������ҳ\t2:����������һ��ͼ��\t0:�˳�ϵͳ):\n");
     scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");judge();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t����Ƿ�\n");getch();system("cls");break;
   }
}
void judegeone()//�����������������
{
    FILE *fp;
    char type[20];
    int i=0,j=0,n;
    fp=fopen("text.txt","r+");
    printf("�������������\n");
    scanf("%s",type);
    printf("%s����飺\n\n");
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
        printf("ͼ����޴����͵���");
         printf("\n\n\n");
     printf("��ѡ��(1:������ҳ\t2:����������һ������\t0:�˳�ϵͳ):\n");
     scanf("%d",&n);

    switch(n)
   {
     case 1:system("cls");break;
     case 2:system("cls");judegeone();break;
     case 0:exit(0);
     default:printf("\n\n\n\n\t\t\t\t\t\t����Ƿ�\n");getch();system("cls");break;
   }


}
void classify()//ͼ�����
{
    int n;
    printf("\n\t\t\t\t\t------------ͼ�����-----------\n");
    printf("0:<����>\n");
    printf("1:���������ж��������\n");
    printf("2:��������������������е���\n");
    scanf("%d",&n);

    switch(n)
    {
      case 1:system("cls");judge();break;
      case 2:system("cls");judegeone();break;
      case 0:system("cls");break;
      default:printf("����Ƿ�");getch();system("cls");
    }

}
book_type*createnode1(book_type *head)//��text�ļ���������
{
    FILE *fp;
    int i;
    book_type *p,*q;
    p=head;
    if((fp=fopen("text.txt","r+"))==NULL)
       {
         printf("�ļ�Ϊ�գ�");
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
student *createnode2(student *head)//��student�ļ���������
{
    FILE *fp;
    int i;
    student *p,*q;
    p=head;
    if((fp=fopen("student.txt","r+"))==NULL)
       {
         printf("�ļ�Ϊ�գ�");
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
void fprintf(book_type *head)//�����������뵽text�ļ���
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
void fprintf1(student *head)//�����������뵽student�ļ���
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
void borrow(book_type *head)//���ĵǼ�
{
    system("cls");
    printf("\n\t\t\t\t\t------------���ĵǼ�-----------\n");
    int n=0,m=0;
    char bookname[20];
    FILE *fp;
    printf("������������Ҫ��������\n");
    scanf("%s",bookname);
    book_type *p;
    for(p=head->next;p!=NULL;p=p->next)
    {
        if(strcmp(p->bookname,bookname)==0&&p->total>0)
        {
            m=1;
            while(n<1)
            {
             printf("\n^_^����滹�У�����Խ��Ȿ�鿴��\n\n");
             printf("���������������\n");
             scanf("%s",sd.name);
             printf("���������ѧ�ţ�\n");
             scanf("%d",&sd.id);
             printf("\n\t\t\t��ѡ��(1:ȷ��\t0:��������):");
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
                printf("ͼ��ݴ������޿�档");
            fprintf(head);
            system("cls");
            printf("\n\t\t\t\t\t\t------------^_^ ���ĳɹ�-----------\n\n");
            printf("��ѡ��(1:������ҳ\t2:����������һ����\t0:�˳�ϵͳ):\n");
            scanf("%d",&n);
            break;
        }

    }
    switch(n)
        {
            case 1:system("cls");break;
            case 2:system("cls");borrow(head);break;
            case 0:exit(0);
            default:printf("\n\n\n\n\t\t\t\t\t\t��û�������(�����`)\n");getch();system("cls");
        }
    if(m==0)
    {
        printf("ͼ������޴����������Ϣ����(�����`)");
        getch();system("cls");
    }

}
void sendback(student *head)//�黹�Ǽ�
{
    system("cls");
    printf("\n\t\t\t\t\t------------�黹�Ǽ�-----------\n");
    int n,m=0;
    char bookname[20];
    char name[20];
    FILE *fp;
    book_type *r,*s;
    book_type *head1;
    head1=(book_type*)malloc(sizeof(book_type));
    head1=createnode1(head1);
    printf("������������\n");
    scanf("%s",name);
    printf("������������\n");
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
                printf("\n\t\t\t\t\t\t------------^_^ �黹�ɹ�-----------\n\n");
                printf("��ѡ��(1:������ҳ\t2:�����黹��һ����\t0:�˳�ϵͳ):\n");
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
        default:printf("\n\n\n\n\t\t\t\t\t\t��Ǹ��û�������(�����`)\n");getch();system("cls");
     }
    }
    if(m==0)
    {
        printf("��û�н��Ȿ�����Ϣ��������(�����`)");
        getch();system("cls");
    }
}
int main()//������
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
           default :system("cls");printf("\n\n\n\n\t\t\t\t\t\t����Ƿ�\n");getch();system("cls");
       }
   }
   return 0;
}
