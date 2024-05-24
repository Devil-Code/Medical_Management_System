#include<stdio.h>
void main()
{
	int amt,price;
	char name[20],meds[20];
	printf("\n\t\t\t\t\t\tABC MEDICAL\n");
	printf("\t\t\t********************************************************************\n");
	printf("\n\t\t\t\t\t\tName:");
	scanf("\n\t\t\t\t\t\t%s",name);
	printf("\n\t\t\t\t\t\tMedicine:");
	scanf("\n\t\t\t\t\t\t%s",meds);
	printf("\n\t\t\t\t\t\tPrice:");
	scanf("\n\t\t\t\t\t\t%d",&price);
	printf("\n\t\t\t\t\t\tAmount:");
	scanf("\n\t\t\t\t\t\t%d",&amt);
	printf("\n\t\t\t\t\t\tTotal:%d",amt*price);
	
}
