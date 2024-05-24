#include<stdio.h>
#include<string.h>
int choice=0,n,i,counter,flag,temp,count=0;
void cadd();
void clist();
void csearch_name();
void csearch_phno();
void csearch_med();
void cedit_name();
void cedit_phno();
void cedit_med();
void cdel();
void cui();
void mui();
//void purchase();
void cread();
void cwrite();
void main_ui();
FILE *customer;
FILE *med;
struct Customer{
    char cname[100],csur[100],cmed[100];
    double cphno;
};
struct Customer c[]={};
struct Medicine{
char med[100];
int id,t_stock;
};
struct Medicine m[]={};
int main()
{
  main_ui();
return 0;
}
void cread()
{
	char name[100],cname[100],medi[100];
	double temp;
	int flag,size,tem;
	customer=fopen("customer.txt","a+");
	fseek(customer,0,SEEK_END);
size=ftell(customer);
if (size == 0)
 {
   cui();
 }else{   
fclose(customer);
customer=fopen("customer.txt","r+");
i=0;
while(fscanf(customer,"%s %s %lf %s",name,cname,&temp,medi)!=EOF)
{
strcpy(c[i].cname,name);
strcpy(c[i].csur,cname);
c[i].cphno=temp;
    strcpy(c[i].cmed,medi);
//printf("%s %s %lf %d\n",c[i].cname,c[i].csur,c[i].cphno,i);
i++;
}
}
fclose(customer);
count=i;
cui();
}
void cadd(){
    for(i=temp;i<count;i++)
    {
        printf("Enter the name");
        scanf("%s",c[i].cname);
        printf("Enter the surname");
        scanf("%s",c[i].csur);
        printf("Enter the phno");
        scanf("%lf",&c[i].cphno);
        printf("Enter the medicine");
        scanf("%s",c[i].cmed);
    }
    cui();
}
void clist(){
   for(i=0;i<count;i++){
    printf("Name is %s %s and Contact number is %.0lf and %s.\n",c[i].cname,c[i].csur,c[i].cphno,m[i].med);
   }
cui();
}
void csearch_name(){
    char name[100],sur[100];
    printf("Enter the name and surname you want to search");
    scanf("%s %s",name,sur);
    for(i=0;i<count;i++)
{
    if((strcmp(name,c[i].cname)==0) && (strcmp(sur,c[i].csur)==0))
    {
        printf("%s %s %s %s",c[i].cname,c[i].csur,name,sur);
        printf("Result Found:");
        printf("Name is %s %s\nand Contact number is %.0lf and %s.",c[i].cname,c[i].csur,c[i].cphno,m[i].med);
        flag=0;
        break;
    }else
    {
        flag=1;
    }
}
if(flag==1)
    {
        printf("No such Info by name %s %s exists.",name,sur);
    }
cui();
}
void csearch_phno(){
    double temp;
printf("Enter the phone number");
    scanf("%lf",&temp);
    for(i=0;i<count;i++)
    {
        if(c[i].cphno==temp)
        {
            printf("%lf %lf",c[i].cphno,temp);
            printf("Result Found:");
            printf("Name is %s %s\nand Contact number is %.0lf and %s.",c[i].cname,c[i].csur,c[i].cphno,m[i].med);
            flag=0;
            break;
        }else
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("No such Info by phno %.0lf exists.",temp);
    }
cui();
}
void csearch_med() {
    char med[100];
    printf("Enter the medicine name");
    scanf("%s",med);
    for(i=0;i<count;i++)
    {
        if((strcmp(med,m[i].med)==0))
        {
            printf("%s %s",m[i].med,med);
            printf("Result Found:");
            printf("Name is %s %s\nand Contact number is %.0lf and %s.",c[i].cname,c[i].csur,c[i].cphno,m[i].med);
            flag=0;
            break;
        }else
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("No such med %s exists.",med);
    }
    cui();
}
void cui()
{
   printf("Enter\n1.Add\n2.List\n3.Search\n4.Edit\n5.delete\n6.Exit to main menu");
    scanf("%d",&choice);
switch (choice)
    {
        case 1:  
	printf("Enter number of Customers you want to add:\n");
            scanf("%d",&n);
            temp=count;
			count=count+n;
			cadd();
            break;
        case 2: clist();break;
        case 3:cprintf("Enter 1.Search by name\n2.Search by Phno\n3.Search by Med");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:csearch_name();break;
                case 2:csearch_phno();break;
                case 3:csearch_med();break;
                default:break;
            }
        case 4:printf("Enter 1.Edit name\n2.Edit Phno\n3.Edit Med");
        scanf("%d",&choice);
            switch (choice)
            {
                case 1:cedit_name();break;
				case 2:cedit_phno();break;
                case 3:cedit_med();break;
                default:break;
            }
		case 5:del();break;
		case 6:cwrite();break;
		default:break;
    }
}
void cedit_name()
{
	 char name[100],sur[100];
	  printf("Enter the name and surname you want to search:\n");
    scanf("%s %s",name,sur);
    for(i=0;i<count;i++)
{
    if((strcmp(name,c[i].cname)==0) && (strcmp(sur,c[i].csur)==0))
    {
        printf("%s %s %s %s",c[i].cname,c[i].csur,name,sur);
        printf("Result Found:");
        printf("Enter the neew name and sur");
        scanf("%s %s",name,sur);
		strcpy(c[i].cname,name);
	   	strcpy(c[i].csur,sur);
		printf("%s %s %s %s",c[i].cname,c[i].csur,name,sur);
		flag=0;
        break;
    }else
    {
        flag=1;
    }
}
if(flag==1)
    {
        printf("No such Info by name %s %s exists.",name,sur);
    }
cui();
}

void cedit_phno()
{
 double temp;
printf("Enter a 10 digit phone number:\n");
    scanf("%lf",&temp);
    for(i=0;i<count;i++)
    {
        if(c[i].cphno==temp)
        {
            printf("%lf %lf",c[i].cphno,temp);
            printf("Result Found:");
            printf("Enter the new phone number");
		    scanf("%lf",&temp);
		    c[i].cphno=temp;
			printf("%lf %lf",c[i].cphno,temp);
			flag=0;
            break;
        }else
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("No such Info by phno %.0lf exists.",temp);
    }
cui();	
}
void cedit_med()
{
	char med[100];
    printf("Enter the medicine name");
    scanf("%s",med);
    for(i=0;i<count;i++)
    {
        if((strcmp(med,m[i].med)==0))
        {
            printf("%s %s",m[i].med,med);
            printf("Result Found:");
            printf("Enter the new medicine name");
            scanf("%s",med);
			strcpy(m[i].med,med);
			printf("%s %s",m[i].med,med);
			flag=0;
            break;
        }else
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("No such med %s exists.",med);
    }
    cui();
}
void cdel()
{
	 char name[100],sur[100];
    printf("Enter the name and surname you want to search");
    scanf("%s %s",name,sur);
    for(i=0;i<count;i++)
{
    if((strcmp(name,c[i].cname)==0) && (strcmp(sur,c[i].csur)==0))
    {
        printf("%s %s %s %s",c[i].cname,c[i].csur,name,sur);
        printf("Result Found:");
       printf("Are You Sure you want to delete the Customer info:\nEnter\n Y to continue\n N to Abort");
        getchar();
		if (getchar()=='Y')
		{
		strcpy(c[i].cname,c[i+1].cname);
	   	strcpy(c[i].csur,c[i+1].csur);
		strcpy(m[i].med,m[i+1].med);
		    c[i].cphno=c[i+1].cphno;
		    m[i].id=m[i+1].id;
			count=count-1;
		}
		else {
			cui();
		}
		flag=0;
        break;
    }else
    {
        flag=1;
    }
}
if(flag==1)
    {
        printf("No such Info by name %s %s exists.",name,sur);
    }
cui();
}
void mui(){
	printf("Enter\n1.Purchase\n2.Sale\n3.Search\n4.Edit\n5.Delete\n6.Stock");
scanf("%d",&choice);
switch(choice){
	case 1:break;
}
}

void main_ui(){
printf("\t\t\t********************************************************************");	
printf("\n\t\t\t\t\t\tEnter your choice\n\t\t\t\t\t\t1.Customer\n\t\t\t\t\t\t2.Supplier\n\t\t\t\t\t\t3.Medicine\n\t\t\t\t\t\t4.Billing\n");
    printf("\n\t\t\t********************************************************************");
	scanf("%d",&choice);
switch (choice){
case 1:
   cread();break;
case 2:mui();
break;
default:break;
}	
}
void cwrite()
{
	customer=fopen("customer.txt","w");
	for(i=0;i<count;i++)
	{
	fprintf(customer,"%s %s %lf\n",c[i].cname,c[i].csur,c[i].cphno);
	}
fclose(customer);
med=fopen("med.txt","w");
	for(i=0;i<count;i++)
	{
	fprintf(med,"%s\n",m[i].med);
	}
fclose(med);
main_ui();
}

