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
 printf("        ************欢迎使用教师信息管理系统**********\n");
 printf("           1.录入教师信息");
 printf("           2.浏览教师信息\n");
 printf("           3.查询教师信息");
 printf("           4.添加教师信息\n");
 printf("           5.删除教师信息");
 printf("           6.修改教师信息\n");
 printf("           7.排序教师信息");
 printf("           8.统计教师信息\n");
 printf("           0.退出\n");
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
    printf("请选择你需要操作的步骤(0--8):");
    scanf("%d",&n);
    if(n>=0&&n<=8)
     {
       flag=1;
       break;
     }
    else
    {
	   flag=0;
	   printf("您输入有误,请重新选择!\n");
    }
 } while(flag==0);

while(flag==1)
 {
    switch(n)
    {
       case 1:printf("      \n◆◆◆输入教师信息 ◆◆◆\n");printf("\n");input();break;
       case 2:printf("      \n◆◆◆浏览教师信息 ◆◆◆\n");printf("\n");display();break;
       case 3:printf("  	\n◆◆◆查询教师信息 ◆◆◆\n");printf("\n");search();break;
       case 4:printf(" 		\n◆◆◆添加教师信息 ◆◆◆\n");printf("\n");add();break;
       case 5:printf("  	\n◆◆◆删除教师信息 ◆◆◆\n");printf("\n");del();break;
       case 6:printf("  	\n◆◆◆修改教师信息 ◆◆◆\n");printf("\n");modify();break;
       case 7:printf("  	\n◆◆◆排序教师信息 ◆◆◆\n");printf("\n");sort();;break;
	   case 8:printf("  	\n◆◆◆统计教师信息 ◆◆◆\n");printf("\n");stat();break;
	   case 9:exit(0);break;
       default :break;
     }
  getchar();
  printf("\n");
  printf("是否继续进行(y or n):\n");
  scanf("%c",&a);
  if(a=='y')
  {
  	 flag=1;
     system("cls");  /*清屏*/
     menu(); /*调用菜单函数*/
     printf("请再次选择你需要操作的步骤(0--8):");
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
     printf("*再次录入将重置已经录入好的信息，确认录入请按1，取消录入请按0：\n");
     scanf("%d",&c);
     if(c==1)
     {
         printf("请输入人数：");
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
	 printf("  姓名\t职工号\t年龄\t性别\t职称\t学历\t工资\t部门 \n");
     for(i=0;i<n;i++)
	 printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
}
int load()
{
     FILE *fp;
     int i=0;
     if((fp=fopen("teacher_dat","rb"))==NULL)
     {
	     printf("cannot open file！\n");
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
	printf("请输入序号，1.学历,2.性别：3.取消统计     ");
	scanf ("%d",&c);
	if(c==1) stat_education();
    else if(c==2) stat_sex();
    else if(c==3);
    else;// if(c>3||c<1)
    /*{
        printf("\n选择错误，请重新输入！\n");
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
	printf("本科：");
	for(i=0;i<n;i++)
	{
		 if(strcmp(teacher[i].education,"本科")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	printf("博士：");
	for(i=0;i<n;i++)
	{
		 if(strcmp(teacher[i].education,"博士")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	printf("硕士：");
	for(i=0;i<n;i++)
	{
		 if(strcmp(teacher[i].education,"硕士")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	for(i=0;i<n;i++)
	 {
		 if(strcmp(teacher[i].education,"本科")==0)
		 a++;//printf("本科：%s\n",teacher[i].name);
		 if(strcmp(teacher[i].education,"博士")==0)
		 b++;//printf("博士：%s\n",teacher[i].name);
		 if(strcmp(teacher[i].education,"硕士")==0)
		 c++ ;//printf("硕士：%s\n",teacher[i].name);
	 }
	 /*for(i=0;i<d;i++)//d=8,i最大值为7
		{
			 if(strcmp(teacher[i].education,"博士")==0)
				 b++;
			 else c++;
         }*/
	 printf("本科共有%d人，博士共有%d人，硕士共有%d人。\n",a,b,c);
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
	printf("男：");
	for(i=0;i<m;i++)
	{
		 if(strcmp(teacher[i].sex,"男")==0)
		 printf("%s  ",teacher[i].name);
	}
	printf("\n");
	printf("女：");
	for(i=0;i<m;i++)
	{
		 if(strcmp(teacher[i].sex,"女")==0)
		 printf("%s  ",teacher[i].name);
	}
	 for(i=0;i<m;i++)
	 {
		 if(strcmp(teacher[i].sex,"男")==0)
			 a++;
		 else b++;
	 }
	 printf("\n");
	 printf("男：%d人，女：%d人\n",a,b);
}
void search()
{
	void search_name();
	void search_num();
	int c;//,flag;
    /*do
   {
    printf("请输入序号，1.姓名,2.职工号：3.取消查询     ");
    scanf("%d",&c);
    if(c>=1&&c<=3)
     {
       flag=1;
       break;
     }
    else
    {
	   flag=0;
	   printf("\n您输入有误,请重新选择!\n");
	   printf("\n");
    }
  }while(flag==0);
  while(flag==1)
	{
	   if(c==1) search_name();
       else if(c==2) search_num();
       else if(c==3);break;
	}*/
	printf("请输入序号，1.姓名,2.职工号：3.取消查询     ");
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
    printf("\n  姓名:\t职工号:\n");
    for(i=0;i<n;i++)
        {
            printf("%6s\t%4d\n",teacher[i].name,teacher[i].num);
        }
	printf("请输入要查询的教师的姓名：");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(strcmp(teacher[i].name,name)==0)
		  {
			printf("\n已找到此教师，其信息如下：\n");
            printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display();printf("\n");
             flag=0;
		  break;
		}
    }
        if (flag!=0)
            {
                printf("\n对不起，查无此人！\n");printf("\n");
                display();printf("\n");
            }//break;
	search();
}
void search_num()
{
	int m;
	int i,n,flag;
	n=load();
	printf("\n  姓名:\t职工号:\n");
    for(i=0;i<n;i++)
        printf("%6s\t%4d\n",teacher[i].name,teacher[i].num);
	printf("请输入要查询的教师的职工号：");
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
        if(m==teacher[i].num)
        {
            printf("\n已找到此教师，其信息如下：\n");
            printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display();printf("\n");
            flag=0;
            break;
         }
	}
	if(flag!=0)
    {
        printf("\n对不起，查无此人！\n");printf("\n");
        display();printf("\n");
    }
    //if (i==n)
        	/*printf("\n职工号：\n");
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
	printf("请输入序号，1.工资,2.年龄：3.取消排序     ");
	scanf ("%d",&c);
	if(c==1) sort_money();
    else if(c==2) sort_age();
    else if(c==3);
    else;// if(c>3||c<1)
    /*{
        printf("\n选择错误，请重新输入！\n");
        sort();
    }*/
}
void sort_money()
{
    int m=load();
    struct teacher_type t;
	int i,j,k,n=10;
	printf("按工资排序：\n");
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
	printf("按年龄排序：\n");
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
   printf("\n原来的教师信息：\n");
   display();
   printf ("\n");
   fp=fopen("teacher_dat","a");
   printf("请输入想增加的教师人数：\n");
   scanf ("%d",&n);
   for(i=m;i<m+n;i++)
  {
    printf("\n请输入增加的教师信息：\n");
    scanf ("%s%d%d%s%s%s%d%s",teacher[i].name,&teacher[i].num,&teacher[i].age,&teacher[i].sex,&teacher[i].jobtitle,&teacher[i].education,&teacher[i].money,&teacher[i].department);
        mam=mam+1;
        printf("已增加教师人数：");
        printf("%d\n",mam);
  }
  printf("添加完毕\n");
  m=m+mam;
  printf("\n浏览增加后的教师信息\n");
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
    printf("\n原来的教师信息\n");
    display();
	printf("请输入要删除的教师姓名：");
	scanf("%s",name);
	for(i=0;i<n;i++)
	{
		if(strcmp(teacher[i].name,name)==0)
		{
			printf("\n已找到此教师，原记录如下：\n");
			printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
			//int k=1;
			flag=0;break;
		}
	}
	if(flag!=0) printf("\n对不起，查无此人！\n");
	else
	{
		printf("\n确定要删除此教师信息请按1，不删除请按0: ");
		scanf("%d",&m);
		if(m==1)
		{
			for(j=i;j<m-1;j++)
				teacher[j]=teacher[j+1];
			    n--;
		}
        save(n);
        printf("\n浏览删除后的所有教师信息:\n");
        display();
	}
    printf("\n继续删除请按1，取消删除请按0：\n");
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
   printf("\n原来的教师信息：\n");
   display();
   printf("请输入需要修改的教师姓名：");
   scanf("%s",name);
   for(i=0;i<m;i++)
   {
       if(strcmp(name,teacher[i].name)==0)
	   {
            printf("\n已找到此人，其记录如下：\n");
            printf("%6s\t%4d\t%d\t%2s\t%4s\t%4s\t%2d\t%6s\n",teacher[i].name,teacher[i].num,teacher[i].age,teacher[i].sex,teacher[i].jobtitle,teacher[i].education,teacher[i].money,teacher[i].department);
            k=i;
            printf("\n确认要修改此教师信息请按1，不修改请按0：\n");
            scanf ("%d",&n);
            if (n==1)
			{
                 printf("请输入你想修改选项的序号：1，姓名；2，职工号；3，年龄；4，性别；5，职称；6，学历；7，工资；8，部门\n");
                 scanf ("%d",&c);
                 if(c>8||c<1)
                 printf("\n选择错误，请重新输入！\n");
  switch(c)
  {
   case 1:printf("姓名改为：\n");
   scanf("%s",&name);
   strcpy(teacher[i].name,name);break;
   case 2:printf("职工号改为：\n");
   scanf("%d",&num);
   teacher[i].num=num;break;
   case 3:printf("年龄改为：\n");
   scanf("%d",&age);
   teacher[i].age=age;break;
   case 4:printf("性别改为：\n");
   scanf("%s",&sex);
   strcpy(teacher[i].sex,sex);break;
   case 5:printf("职称改为：\n");
   scanf("%d",&jobtitle);
   strcpy(teacher[i].jobtitle,jobtitle);break;
   case 6:printf("学历改为：\n");
   scanf ("%d",&education);
   strcpy(teacher[i].education,education);break;
   case 7:printf("工资改为：\n");
   scanf ("%d",&money);
   teacher[i].money=money;break;
   case 8:printf("部门改为：\n");
   scanf ("%d",&department);
   strcpy(teacher[i].department,department);
   break;
   }
    printf("\n浏览修改后的所有教师信息\n");
    save(m);
    display();
    printf("\n继续修改请按1，取消修改请按0:\n");
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
        printf("\n对不起，查无此人！\n");
	    printf("\n继续修改请按1，取消修改请按0。\n");
        scanf("%d",&t);
        if (t==1) modify();
	    else;//break;
    }
}
