#include<stdio.h>
#include<string.h>
int tem=0,choice=0,n,i,flag,temp,count=0,mcount=0;
void sadd();
void slist();
void ssearch_name();
void ssearch_phno();
void ssearch_med();
void sedit_name();
void sedit_phno();
void sedit_med();
void sdel();
void sui();
void mui();
void purchase();
void sale();
void msearch();
void sread();
void swrite();
void main_ui();
void mread();
FILE *supply;
FILE *med;
struct Supplier{
    char sname[100],ssur[100],smed[100];
    double sphno;
};
struct Supplier s[]={};
struct Medicine{
    char med[100];
    int total_s,stemp_s,ctemp_s;
};
struct Medicine m[]={};
int main()
{
    main_ui();
    return 0;
}
void sread()
{
    char name[100],sname[100],medi[100];
    double temp;
    int flag,size,tem=0;
    supply=fopen("supply.txt","a+");
    fseek(supply,0,SEEK_END);
    size=ftell(supply);
    if (size == 0)
    {
        sui();
    }else{
        fclose(supply);
        supply=fopen("supply.txt","r+");
        i=0;
        while(fscanf(supply,"%s %s %lf %s",name,sname,&temp,medi)!=EOF)
        {
            //printf("1");
            strcpy(s[i].sname,name);
            strcpy(s[i].ssur,sname);
            s[i].sphno=temp;
            strcpy(s[i].smed,medi);
            i++;
        }
    }
    fclose(supply);
    med=fopen("med.txt","r+");
    i=0;
    while(fscanf(med,"%s %d",medi,&tem)!=EOF)
    {
        strcpy(m[i].med,medi);
        m[i].total_s=tem;
        i++;
    }
    count=i;
    fclose(med);
    sui();
}
void swrite()
{
    med=fopen("med.txt","w");
    for(i=0;i<count;i++)
    {
        fprintf(med,"%s %d\n",m[i].med,m[i].total_s);
    }
    fclose(med);
    supply=fopen("supply.txt","w");
    for(i=0;i<count;i++)
    {
        fprintf(supply,"%s %s %lf %s\n",s[i].sname,s[i].ssur,s[i].sphno,s[i].smed);
    }
    fclose(supply);

    main_ui();
}
void sadd(){
    for(i=temp;i<count;i++)
    {
        printf("Enter the name");
        scanf("%s",s[i].sname);
        printf("Enter the surname");
        scanf("%s",s[i].ssur);
        printf("Enter the phno");
        scanf("%lf",&s[i].sphno);
        printf("Enter the medicine");
        scanf("%s",m[i].med);
    strcpy(s[i].smed,m[i].med);
    }
    sui();
}
void slist(){
    for(i=0;i<count;i++){
        printf("Name is %s %s\nand Contact number is %.0lf and %s.",s[i].sname,s[i].ssur,s[i].sphno,m[i].med);
    }
    sui();
}
void ssearch_name(){
    char name[100],sur[100];
    printf("Enter the name and surname you want to search");
    scanf("%s %s",name,sur);
    for(i=0;i<count;i++)
    {
        if((strcmp(name,s[i].sname)==0) && (strcmp(sur,s[i].ssur)==0))
        {
            printf("%s %s %s %s",s[i].sname,s[i].ssur,name,sur);
            printf("Result Found:");
            printf("Name is %s %s\nand Contact number is %.0lf and %s.",s[i].sname,s[i].ssur,s[i].sphno,m[i].med);
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
    sui();
}
void ssearch_phno(){
    double temp;
    printf("Enter the phone number");
    scanf("%lf",&temp);
    for(i=0;i<count;i++)
    {
        if(s[i].sphno==temp)
        {
            printf("%lf %lf",s[i].sphno,temp);
            printf("Result Found:");
            printf("Name is %s %s\nand Contact number is %.0lf and %s.",s[i].sname,s[i].ssur,s[i].sphno,m[i].med);
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
    sui();
}
void ssearch_med() {
    char med[100];
    printf("Enter the medicine name");
    scanf("%s",med);
    for(i=0;i<count;i++)
    {
        if((strcmp(med,m[i].med)==0))
        {
            printf("%s %s",m[i].med,med);
            printf("Result Found:");
            printf("Name is %s %s\nand Contact number is %.0lf and %s.",s[i].sname,s[i].ssur,s[i].sphno,m[i].med);
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
    sui();
}
void sui()
{
    printf("Enter\n1.Add\n2.List\n3.Search\n4.Edit\n5.delete\n6.Exit to main menu");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            printf("Enter n");
            scanf("%d",&n);
            temp=count;
            count=count+n;
            sadd();
            break;
        case 2: slist();break;
        case 3:printf("Enter 1.Search by name\n2.Search by Phno\n3.Search by Med");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:ssearch_name();break;
                case 2:ssearch_phno();break;
                case 3:ssearch_med();break;
                default:break;
            }
        case 4:printf("Enter 1.Edit name\n2.Edit Phno\n3.Edit Med");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:sedit_name();break;
                case 2:sedit_phno();break;
                case 3:sedit_med();break;
                default:break;
            }
        case 5:sdel();break;
        case 6:swrite();break;
        default:break;
    }
}
void sedit_name()
{
    char name[100],sur[100];
    printf("Enter the name and surname you want to search");
    scanf("%s %s",name,sur);
    for(i=0;i<count;i++)
    {
        if((strcmp(name,s[i].sname)==0) && (strcmp(sur,s[i].ssur)==0))
        {
            printf("%s %s %s %s",s[i].sname,s[i].ssur,name,sur);
            printf("Result Found:");
            printf("Enter the neew name and sur");
            scanf("%s %s",name,sur);
            strcpy(s[i].sname,name);
            strcpy(s[i].ssur,sur);
            printf("%s %s %s %s",s[i].sname,s[i].ssur,name,sur);
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
    sui();
}

void sedit_phno()
{
    double temp;
    printf("Enter the phone number");
    scanf("%lf",&temp);
    for(i=0;i<count;i++)
    {
        if(s[i].sphno==temp)
        {
            printf("%lf %lf",s[i].sphno,temp);
            printf("Result Found:");
            printf("Enter the new phone number");
            scanf("%lf",&temp);
            s[i].sphno=temp;
            printf("%lf %lf",s[i].sphno,temp);
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
    sui();
}
void sedit_med()
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
    sui();
}
void sdel()
{
    char name[100],sur[100];
    printf("Enter the name and surname you want to search");
    scanf("%s %s",name,sur);
    for(i=0;i<count;i++)
    {
        if((strcmp(name,s[i].sname)==0) && (strcmp(sur,s[i].ssur)==0))
        {
            printf("%s %s %s %s",s[i].sname,s[i].ssur,name,sur);
            printf("Result Found:");
            printf("Are You Sure you want to delete the supplier info:\nEnter\n Y to cont\n N to Abort");
            getchar();
            if (getchar()=='Y')
            {
                strcpy(s[i].sname,s[i+1].sname);
                strcpy(s[i].ssur,s[i+1].ssur);
                strcpy(m[i].med,m[i+1].med);
                s[i].sphno=s[i+1].sphno;
                count=count-1;
            }
            else {
                sui();
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
    sui();
}
void mui(){
    printf("Enter\n1.Purchase\n2.Sale\n3.Search\n4.Edit\n5.Delete\n6.Stock");
    scanf("%d",&choice);
    switch(choice){
        case 1:mread();break;
        case 2:sale();break;
        case 3:msearch();break;
        default:break;
    }
}

void main_ui(){
    printf("Enter\n1.Supplier\n2.Customer\n3.Medicine\n4.Billing");
    scanf("%d",&choice);
    switch (choice){
        case 1:
            sread();break;
        case 2:mui();
            break;
        default:break;
    }
}

void mread()
{
    char medi[100];
    int tem,size;
    med=fopen("med.txt","a+");
    fseek(supply,0,SEEK_END);
    size=ftell(supply);
    if (size == 0)
    {
        mui();
    }else{
    i=0;
        fclose(med);
        med=fopen("med.txt","r+");
        while(fscanf(med,"%s %d",medi,&tem)!=EOF)
    {
        strcpy(m[i].med,medi);
        m[i].total_s=tem;
        i++;
    }
    count=i;
    fclose(med);
purchase();
}}
void purchase()
{
    char mtemp[100];
    int pt=0;
    for(i=0;i<1;i++) {
        printf("Enter the med name");
        scanf("%s", mtemp);
        printf("Enter the stock amount");
        scanf("%d", &pt);
    }
    for(i=0;i<count;i++)
    {
        if(strcmp(m[i].med,mtemp)==0)
        {
            m[i].stemp_s=pt;
            printf("%d units of %s Purchased", m[i].stemp_s, m[i].med);
           m[i].total_s=m[i].total_s+m[i].stemp_s;
            break;
        }else{
            printf("Medicine not found");
        }
}
mui();
}
void sale()
{
    char mtemp[100];
    int st=0;
    for(i=0;i<1;i++) {
        printf("Enter the med name");
        scanf("%s", mtemp);
        printf("Enter the stock amount");
        scanf("%d", &st);
    }
    for(i=0;i<count;i++)
    {
        if(strcmp(m[i].med,mtemp)==0)
        {
            m[i].ctemp_s=st;
            printf("%d units of %s Sold", m[i].ctemp_s, m[i].med);
            m[i].total_s=m[i].total_s-m[i].ctemp_s;
            break;
        }else{
            printf("Medicine not found");
        }
}
mui();
}
void msearch()
{
   char mtemp[100];
    printf("Enter the med name");
    scanf("%s",mtemp);
for(i=0;i<count;i++)
{
    if(strcmp(m[i].med,mtemp)==0)
    {
        printf("Result Found");
        printf("The medicine %s has total of %d ",m[i].med,m[i].total_s);
    }else
    {
        printf("No such medicine is present");
    }}
mui();
}

void medit()
{
    char mtemp[100];
    int temp;
    printf("Enter the med name");
    scanf("%s",mtemp);
    for(i=0;i<count;i++)
    {
        if(strcmp(m[i].med,mtemp)==0)
        {
            printf("Result Found");
            printf("The medicine %s has total of %d ",m[i].med,m[i].total_s);
        printf("Enter the new stock amount");
            scanf("%d",&temp);
        m[i].total_s=temp;
        }else
        {
            printf("No such medicine is present");
        }}
    mui();

}