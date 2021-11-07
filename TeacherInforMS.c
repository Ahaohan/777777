#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define SIZE 10
struct teacher_type
{    char name[10];
     int num;
     int age;
     char sex[10];
     char jobtitle[10];
     char education[10];
     int money;
     char department[10];
}teacher[SIZE];
void menu()
{
 printf("        ************��ӭʹ�ý�ʦ��Ϣ����ϵͳ**********\n");
 printf("           1.¼���ʦ��Ϣ");
 printf("           2.�����ʦ��Ϣ\n");
 printf("           3.��ѯ��ʦ��Ϣ");
 printf("           4.��ӽ�ʦ��Ϣ\n");
 printf("           5.ɾ����ʦ��Ϣ");
 printf("           6.�޸Ľ�ʦ��Ϣ\n");
 printf("           7.�����ʦ��Ϣ");
 printf("           8.ͳ�ƽ�ʦ��Ϣ\n");
 printf("           0.�˳�\n");
 printf("\n");
 printf("\n");
}
int main()
{
    void menu();
    void input();
	void search();
	void display();
	void stat();
	void save();
	void add();
	void del();
	void modify();
	void sort();
      menu();
 int n,flag;
 char a;
 do
 {
    printf("��ѡ������Ҫ�����Ĳ���(0--8):");
    scanf("%d",&n);
    if(n>=0&&n<=8)
     {
       flag=1;
       break;
     }
    else
    {
	   flag=0;
	   printf("����������,������ѡ��!\n");
    }
 } while(flag==0);

while(flag==1)
 {
    switch(n)
    {
       case 1:printf("      \n�����������ʦ��Ϣ ������\n");printf("\n");input();break;
       case 2:printf("      \n�����������ʦ��Ϣ ������\n");printf("\n");display();break;
       case 3:printf("  	\n��������ѯ��ʦ��Ϣ ������\n");printf("\n");search();break;
       case 4:printf(" 		\n��������ӽ�ʦ��Ϣ ������\n");printf("\n");add();break;
       case 5:printf("  	\n������ɾ����ʦ��Ϣ ������\n");printf("\n");del();break;
       case 6:printf("  	\n�������޸Ľ�ʦ��Ϣ ������\n");printf("\n");modify();break;
       case 7:printf("  	\n�����������ʦ��Ϣ ������\n");printf("\n");sort();;break;
	   case 8:printf("  	\n������ͳ�ƽ�ʦ��Ϣ ������\n");printf("\n");stat();break;
	   case 9:exit(0);break;
       default :break;
     }
  getchar();
  printf("\n");
  printf("�Ƿ��������(y or n):\n");
  scanf("%c",&a);
  if(a=='y')
  {
  	 flag=1;
     system("cls");  /*����*/
     menu(); /*���ò˵�����*/
     printf("���ٴ�ѡ������Ҫ�����Ĳ���(0--8):");
     scanf("%d",&n);
     printf("\n");
  }
  else   exit(0);
 }
	  return 0;
}
void input()
{
	void save(int m);
     int i;
     int m,c;
     printf("*�ٴ�¼�뽫�����Ѿ�¼��õ���Ϣ��ȷ��¼���밴1��ȡ��¼���밴0��\n");
     scanf("%d",&c);
     if(c==1)
     {
         printf("������������");
         scanf("%d",&m);
         for(i=0;i<m;i++)
	        scanf("%s%d%d%s%s%s%d%s",teacher[i].name,&teacher[i].num,&teacher[i].age,&teacher[i].sex,&teacher[i].jobtitle,&teacher[i].education,&teacher[i].money,&teacher[i].department);
         save(m);
     }
     else if(c==0);
     else;
}
void save(int m)
{   FILE *fp;
     int  i;
     if((fp=fopen("teacher_dat","wb"))==NULL)
     {    printf("cannot open file\n");
	      exit(0);
     }
     for(i=0;i<m;i++)
         if(fwrite(&teacher[i],sizeof(struct teacher_type),1,fp)!=1)
	     printf("file write error\n");
     fclose(fp);
}
void display()
{
     int load();
	 int  i,n;
     n=load();
	 printf("  ����\tְ����\t����\t�Ա�\tְ��\tѧ��\t����\t���� \n");
     for(i=0;i<n;i++)
	 printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
}
int load()
{
     FILE *fp;
     int i=0;
     if((fp=fopen("teacher_dat","rb"))==NULL)
     {
	     printf("cannot open file��\n");
	     exit(0);
     }
     while(feof(fp)==0)
	 {
	       fread(&teacher[i],sizeof(struct teacher_type),1,fp);
		   i++;
	}
	fclose(fp);
	return i-1;
}
void stat()
{
	void stat_education();
	void stat_sex();
	int c;
	int n=load();
	printf("��������ţ�1.ѧ��,2.�Ա�3.ȡ��ͳ��     ");
	scanf ("%d",&c);
	if(c==1) stat_education();
    else if(c==2) stat_sex();
    else if(c==3);
    else;// if(c>3||c<1)
    /*{
        printf("\nѡ��������������룡\n");
        stat();
    }*/
}
void stat_education()
{
    int m;
	m=load();
	int a,b,c,i,n=10;
	a=0;b=0;c=0;
	printf("\n");
	printf("���ƣ�");
	for(i=0;i<n;i++)
	{
		 if(strcmp(teacher[i].education,"����")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	printf("��ʿ��");
	for(i=0;i<n;i++)
	{
		 if(strcmp(teacher[i].education,"��ʿ")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	printf("˶ʿ��");
	for(i=0;i<n;i++)
	{
		 if(strcmp(teacher[i].education,"˶ʿ")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	for(i=0;i<n;i++)
	 {
		 if(strcmp(teacher[i].education,"����")==0)
		 a++;//printf("���ƣ�%s\n",teacher[i].name);
		 if(strcmp(teacher[i].education,"��ʿ")==0)
		 b++;//printf("��ʿ��%s\n",teacher[i].name);
		 if(strcmp(teacher[i].education,"˶ʿ")==0)
		 c++ ;//printf("˶ʿ��%s\n",teacher[i].name);
	 }
	 /*for(i=0;i<d;i++)//d=8,i���ֵΪ7
		{
			 if(strcmp(teacher[i].education,"��ʿ")==0)
				 b++;
			 else c++;
         }*/
	 printf("���ƹ���%d�ˣ���ʿ����%d�ˣ�˶ʿ����%d�ˡ�\n",a,b,c);
	 //display();
}
void stat_sex()
{
    int m=load();
	int a,b,i;
	//char education2[10],education1[10];
	a=0;b=0;
	//printf("%s",teacher[1].education);
	printf("\n");
	printf("�У�");
	for(i=0;i<m;i++)
	{
		 if(strcmp(teacher[i].sex,"��")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	printf("Ů��");
	for(i=0;i<m;i++)
	{
		 if(strcmp(teacher[i].sex,"Ů")==0)
		 printf("%s  ",teacher[i].name);
	}
	 for(i=0;i<m;i++)
	 {
		 if(strcmp(teacher[i].sex,"��")==0)
			 a++;
		 else b++;
	 }
	 printf("\n");
	 printf("�У�%d�ˣ�Ů��%d��\n",a,b);
}
void search()
{
	void search_name();
	void search_num();
	int c;//,flag;
    /*do
   {
    printf("��������ţ�1.����,2.ְ���ţ�3.ȡ����ѯ     ");
    scanf("%d",&c);
    if(c>=1&&c<=3)
     {
       flag=1;
       break;
     }
    else
    {
	   flag=0;
	   printf("\n����������,������ѡ��!\n");
	   printf("\n");
    }
  }while(flag==0);
  while(flag==1)
	{
	   if(c==1) search_name();
       else if(c==2) search_num();
       else if(c==3);break;
	}*/
	printf("��������ţ�1.����,2.ְ���ţ�3.ȡ����ѯ     ");
    scanf("%d",&c);
       if(c==1) search_name();
       else if(c==2) search_num();
       else if(c==3);
       else;
}
void search_name()
{
	char name[10];
	int i,n,flag;
	n=load();
    printf("\n  ����:\tְ����:\n");
    for(i=0;i<n;i++)
        {
            printf("%6s\t%4d\n",teacher[i].name,teacher[i].num);
        }
	printf("������Ҫ��ѯ�Ľ�ʦ��������");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(strcmp(teacher[i].name,name)==0)
		  {
			printf("\n���ҵ��˽�ʦ������Ϣ���£�\n");
            printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display();printf("\n");
             flag=0;
		  break;
		}
    }
        if (flag!=0)
            {
                printf("\n�Բ��𣬲��޴��ˣ�\n");printf("\n");
                display();printf("\n");
            }//break;
	search();
}
void search_num()
{
	int m;
	int i,n,flag;
	n=load();
	printf("\n  ����:\tְ����:\n");
    for(i=0;i<n;i++)
        printf("%6s\t%4d\n",teacher[i].name,teacher[i].num);
	printf("������Ҫ��ѯ�Ľ�ʦ��ְ���ţ�");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
        if(m==teacher[i].num)
        {
            printf("\n���ҵ��˽�ʦ������Ϣ���£�\n");
            printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display();printf("\n");
            flag=0;
            break;
         }
	}
	if(flag!=0)
    {
        printf("\n�Բ��𣬲��޴��ˣ�\n");printf("\n");
        display();printf("\n");
    }
    //if (i==n)
        	/*printf("\nְ���ţ�\n");
		    for(i=0;i<n;i++)
            {
                printf("%d ",teacher[i].num);
            }*/
     //printf("%d",teacher[n].num);
        search();
}
void sort()
{
    void sort_money();
	void sort_age();
	int c;
	printf("��������ţ�1.����,2.���䣺3.ȡ������     ");
	scanf ("%d",&c);
	if(c==1) sort_money();
    else if(c==2) sort_age();
    else if(c==3);
    else;// if(c>3||c<1)
    /*{
        printf("\nѡ��������������룡\n");
        sort();
    }*/
}
void sort_money()
{
    int m=load();
    struct teacher_type t;
	int i,j,k,n=10;
	printf("����������\n");
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(teacher[j].money>teacher[k].money)
			k=j;
			t=teacher[k];
			teacher[k]=teacher[i];
			teacher[i]=t;
	}
	for(i=0;i<n;i++)
	printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
	printf("\n");
	sort();
}
void sort_age()
{
    int m=load();
    struct teacher_type t;
	int i,j,k,n=10;
	printf("����������\n");
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(teacher[j].age>teacher[k].age)
			k=j;
			t=teacher[k];
			teacher[k]=teacher[i];
			teacher[i]=t;
	}
	for(i=0;i<n;i++)
	  printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
	printf("\n");
	sort();
}
void add()
{
   FILE *fp;
   int n;
   int mam=0;
   int i;
   int m=load();
   printf("\nԭ���Ľ�ʦ��Ϣ��\n");
   display();
   printf ("\n");
   fp=fopen("teacher_dat","a");
   printf("�����������ӵĽ�ʦ������\n");
   scanf ("%d",&n);
   for(i=m;i<m+n;i++)
  {
    printf("\n���������ӵĽ�ʦ��Ϣ��\n");
    scanf ("%s%d%d%s%s%s%d%s",teacher[i].name,&teacher[i].num,&teacher[i].age,&teacher[i].sex,&teacher[i].jobtitle,&teacher[i].education,&teacher[i].money,&teacher[i].department);
        mam=mam+1;
        printf("�����ӽ�ʦ������");
        printf("%d\n",mam);
  }
  printf("������\n");
  m=m+mam;
  printf("\n������Ӻ�Ľ�ʦ��Ϣ\n");
  save(m);
  display();
  fclose(fp);
}
 void del()
{
	int n=load();
	int i,j,m,t,flag;
	char name[10];
	printf("\n");
    printf("\nԭ���Ľ�ʦ��Ϣ\n");
    display();
	printf("������Ҫɾ���Ľ�ʦ������");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(strcmp(teacher[i].name,name)==0)
		{
			printf("\n���ҵ��˽�ʦ��ԭ��¼���£�\n");
			printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
			//int k=1;
			flag=0;break;
		}
	}
	if(flag!=0) printf("\n�Բ��𣬲��޴��ˣ�\n");
	else
	{
		printf("\nȷ��Ҫɾ���˽�ʦ��Ϣ�밴1����ɾ���밴0: ");
		scanf("%d",&m);
		if(m==1)
		{
			for(j=i;j<m-1;j++)
				teacher[j]=teacher[j+1];
			    n--;
		}
        save(n);
        printf("\n���ɾ��������н�ʦ��Ϣ:\n");
        display();
	}
    printf("\n����ɾ���밴1��ȡ��ɾ���밴0��\n");
    scanf("%d",&t);
    if(t==1) del();
    else;
}

void modify()
{
     char name[10];
     int num;
     int age;
     char sex[10];
     char jobtitle[10];
     char education[10];
     int money;
     char department[10];
   int c,i,n,t,k;//flag;
   int m=load();
   printf("\nԭ���Ľ�ʦ��Ϣ��\n");
   display();
   printf("��������Ҫ�޸ĵĽ�ʦ������");
   scanf("%s",name);
   for(i=0;i<m;i++)
   {
       if(strcmp(name,teacher[i].name)==0)
	   {
            printf("\n���ҵ����ˣ����¼���£�\n");
            printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
            k=i;
            printf("\nȷ��Ҫ�޸Ĵ˽�ʦ��Ϣ�밴1�����޸��밴0��\n");
            scanf ("%d",&n);
            if (n==1)
			{
                 printf("�����������޸�ѡ�����ţ�1��������2��ְ���ţ�3�����䣻4���Ա�5��ְ�ƣ�6��ѧ����7�����ʣ�8������\n");
                 scanf ("%d",&c);
                 if(c>8||c<1)
                 printf("\nѡ��������������룡\n");
  switch(c)
  {
   case 1:printf("������Ϊ��\n");
   scanf("%s",&name);
   strcpy(teacher[i].name,name);break;
   case 2:printf("ְ���Ÿ�Ϊ��\n");
   scanf("%d",&num);
   teacher[i].num=num;break;
   case 3:printf("�����Ϊ��\n");
   scanf("%d",&age);
   teacher[i].age=age;break;
   case 4:printf("�Ա��Ϊ��\n");
   scanf("%s",&sex);
   strcpy(teacher[i].sex,sex);break;
   case 5:printf("ְ�Ƹ�Ϊ��\n");
   scanf("%d",&jobtitle);
   strcpy(teacher[i].jobtitle,jobtitle);break;
   case 6:printf("ѧ����Ϊ��\n");
   scanf ("%d",&education);
   strcpy(teacher[i].education,education);break;
   case 7:printf("���ʸ�Ϊ��\n");
   scanf ("%d",&money);
   teacher[i].money=money;break;
   case 8:printf("���Ÿ�Ϊ��\n");
   scanf ("%d",&department);
   strcpy(teacher[i].department,department);
   break;
   }
    printf("\n����޸ĺ�����н�ʦ��Ϣ\n");
    save(m);
    display();
    printf("\n�����޸��밴1��ȡ���޸��밴0:\n");
    scanf("%d",&t);
    switch (t)
	{
      case 1:modify();break;
      case 0:break;
      default:break;
	}
	break;
	//flag=0;
			}
			if (n==0);//break;
	   }
   }
     //if(!flag)
      //m=m-1;
	if(i==m)
    {
        printf("\n�Բ��𣬲��޴��ˣ�\n");
	    printf("\n�����޸��밴1��ȡ���޸��밴0��\n");
        scanf("%d",&t);
        if (t==1) modify();
	    else;//break;
    }
}
