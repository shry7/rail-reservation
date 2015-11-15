#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>
#include"rail.h"
#include"graph.h"
#include"list.h"
#include"queue.h"


char f[10]="f"; 	// first class //
char s[10]="s"; 	// second class //
int  flag, f1, d, m, i, amt;
float tamt;   	// total amount //

void manage();
void can();
void user();
void database();
void res();
void reserv();
void displaypassdetail();
void cancell();
void enquiry();
void getcancdet();
void displaycancdet();
void getdetail();
void displaydetail();
void getid();
void displayid();
void getresdet();
void displayresdet();

void main () {
	printf("1.Admin mode\n 2.User mode\n 3.Exit\n");
	printf("Enter your choice:");
	int ch;
	scanf("%d", &ch);
	switch(ch)
	{
		case 1:
			database();
			break;
		case 2:
			user();
			break;
		default :
			break;
	}
	printf("trains between two stations");
	graph(graph *g ,int n);
	printf("info about the trains");
	list(list *l);
}

void database() {
	char *password;
	char *pass="12345678";
	password = getpass("Enter the admininistrator password:");
	detail a;
	int ch;
	char c;
	FILE *fp;
	if(strcmp(pass,password)!=0) {
		printf("Enter the password correctly \n You are not permitted to login this mode\n");
		//goto ch;
	}
	if(strcmp(pass,password) == 0) {
	char c;
	do{
		printf("...........ADMINISTRATOR MENU...........\n");
		printf("1.Create detail data base\n 2.Add details\n 3.Display details\n 4.User management\n 				5.Display passenger details\n 6.Return to main menu\n");
		printf("Enter your choice:");
		scanf("%d\n", &ch);
	}while (ch <= 6);	
		getchar();
	}
	switch(ch) {
		case 1:
			fp = fopen("t.txt","r");
			do
			{
				getdetail(a); // write the details in a file
				fwrite(&a, sizeof(a),1, fp);
				printf("Do you want to add one more record?\n");
				printf("y-for Yes\nn-for No\n");
				scanf("%c\n", &c);
			}
			while(c == 'y');
			fclose(fp);
			break;
		case 2:
			fp = fopen("t.txt","r");
			getdetail(a);
			fwrite(&a, sizeof(a),1, fp);
			fclose(fp);
			break;
		case 3:
			fp = fopen("t.txt","r");
			while(fread(&a, sizeof(a),1, fp))
			{
				displaydetail(a);    // read the detail file and display the details
			}
			fclose(fp);
			break;
		case 4:
			manage();
			break;
		case 5:
			displaypassdetail();
			break;
		default :
			break;
	}
	while(ch <= 5)
	fclose(fp);
}

void reserv() {
	int ch;
	do
	{
		printf("1.Reserve\n 2.Return to the main menu\n");
		printf("Enter your choice:");
		scanf("%d\n", &ch);
			switch(ch)
			{
				case 1:
					res();
					break;
				default :
					break;
			}
		}
	while(ch == 1);
	getchar();
}
void res() {
	detail a;
	reserv b;
	FILE *fp1, *fp2;
	time_t t;
	fp1 = fopen("t.txt","r");
	fp2 = fopen("p.txt","r");
	int ch;
	getresdet(b);
	while(fread(&a, sizeof(a),1, fp1))
	{
		if(a.tno == b.tno)
		{
			if(strcmp(b.clas,f) == 0) // compare the class
			{
					if(a.c1 >= b.nosr)
					{
						amt = a.c1fare;
						a.c1 = a.c1 - b.nosr; // update seat availibility of class 1
						//fwrite((a.c1, sizeof(a.c1),1,  fp1);
							if(b.con == 1)   // concession
							{
								printf("Concession category:MILITARY PERSONNEL\n");
								b.amc = b.nosr * ((amt*50)/100);
							}
							else if(b.con == 2)
							{
								printf("Concession category:SENIOR CITIZEN\n");
								b.amc = b.nosr * ((amt*60)/100);
							}
							else if(b.con == 3)
							{
								printf("Concession category:CHILDERN BELOW FIVE\n");
								b.amc = 0.0;
								}
							else if(b.con == 4)
							{
								printf("You cannot get any concession\n");
								b.amc = b.nosr * amt;
							}
						srand((unsigned) time(&t)); 
						b.pnr = rand(); // give random pnr no
						fwrite(b, sizeof(b),1, fp2);
						displayresdet(b);
						printf("--------------Your ticket is reserved-----------\n");
					}
					else
					{
						printf("**********Sorry req seats not available********\n");
					}
			}
			else if(strcmp(b.clas,s) == 0) // compare the class
			{
				if(a.c2 >= b.nosr)
				{
					amt = a.c2fare; // fare 
					a.c2 = a.c2 - b.nosr; //update seat availablity of class 2
					//fwrite( (a.c2), sizeof(a.c2),1 ,fp1);
					if(b.con == 1)
					{
						printf("Concession category:MILITARY PRESONNEL\n");
						b.amc = b.nosr * ((amt*50)/100);  // fare amount
					}
					else if(b.con == 2)
					{
						printf("Concession category:SENIOR CITIZEN\n");
						b.amc = b.nosr * ((amt*60)/100);
					}
					else if(b.con == 3)
					{
						printf("Concession category:CHILDERN BELOW FIVE\n");
						b.amc = 0.0;
					}
					else if(b.con == 4)
					{
						printf("You cannot get any concession\n");
						b.amc = b.nosr * amt;
					}
					fwrite(&b, sizeof(b),1, fp2);
					displayresdet(b);
					printf("--------Your ticket is reserved--------\n");
				}
				else {
					printf("Sorry req no of seats not available\n");
				}
			}
			getchar();
			//goto ch;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		printf("....Wrong train no..Enter the train no from the data base.....\n");
	}
	fclose(fp1);
	fclose(fp2);
	getchar();
}

void displaypassdetail(){
	FILE *fp;
	reserv b;
	fp = fopen("p.txt","r");
		//fseek(0);//
	while(fread((&b,sizeof(b),1, fp)) {
		displayresdet(b);
	}
	fclose(fp);
	getchar();
	}
void enquiry() {
	FILE *fp;
	fp = fopen("t.txt","r");
	detail a;
	while(fread((&a, sizeof(a), 1,fp))
	{
		displaydetail(a);
	}
	fclose(fp);
	getchar(fp);
	}

void cancell() {
	detail a;
	reserv b;
	canc c;
	int j;
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	fp1 = fopen("t.txt","r");
	fp2 = fopen("p.txt","r");
	fp3 = fopen("cn.txt","r");
	printf("****CANCELLATION MENU****\n");
	getcancdet(c);
	while(fread(&b, sizeof(b),1, fp2))
	{
		if(b.pnr == c.pnr)
		{
			c.tno = b.tno;
			strcpy(c.tname,b.tname);
			strcpy(c.bp,b.bp);
			strcpy(c.dest,b.dest);
			c.nosc  = b.nosr;
			for(j=0; j < c.nosc; j++)
			{
				strcpy(c.pname[j],b.pname[j]);
				c.age[j] = b.age[j];
			}
			strcpy(c.clas,b.clas);
			if(strcmp(c.clas,f) == 0)
			{
				while(fread((&a, sizeof(a),1, fp1))
				{
					if(a.tno == c.tno)
					{
						a.c1 = a.c1  + c.nosc;
						d = a.dd;
						m = a.mm;
						fwrite((&(a.c1), sizeof(a.c1),1, fp1);
						tamt = b.amc;
						if((c.dd == d) && (c.mm == m))
						{
							printf("You are cancelling at the date of departure\n");
							c.amc = tamt - ((tamt*60)/100);
						}
						else if(c.mm  == m)
						{
							printf("You are cancelling at the month of departure\n");
							c.amc = tamt-((tamt*50)/100);
						}
						else if(m > c.mm)
						{
							printf("You are cancelling one month before the date of 								departure\n");
							c.amr = tamt-((tamt*20)/100);
						}
						else
						{
							printf("Cancelling after the departure\n Your request cannot be 								completed\n");
						}
						//goto ch;
						displaycancdet();
					}
			}
			}
			else if(strcmp(c.clas,s)==0)
			{
				while(fread(&a, sizeof(a),1, fp1))
			{
				if(a.tno == c.tno)
				{
					a.c2 = a.c2 + c.nosc;
					d = a.dd;
					m = a.mm;
					
					fwrite((&(a.c2),sizeof(a.c2),1, fp1);
					tamt = b.amc;
					if((c.dd == d) && (c.mm == m))
					{
						printf("You are cancelling at the date of departure\n");
						c.amr = tamt-((tamt*60)/100);
					}
					else if(c.mm == m)
					{
						printf("You are cancelling at the month of departure\n");
						c.amr=tamt-((tamt*50)/100);
					}
					else if(m > c.mm)
					{
						printf("You are cancelling one month before the date of departure\n");
						c.amc = tamt-((tamt*20)/100);
					}
					else
					{
						printf("Cancelling after the departure\n");
						printf("Your request cannot be completed\n");
					}
					//goto h;
					displaycancdet();
				}
			}
			}
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		printf("Enter the correct pnr no\n");
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	getchar();
	}
void can() {
	int ch;
	do
		{
		printf("1.Cancell\n2.Return to the main menu\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				cancell();
				break;
			default:
				break;
		}
		}
	while(ch == 1)
	getchar();
	}

void user() {
	login a;
	int ch;
	char *password;
	FILE *fp;
	fp = fopen("id.txt","r");
	char id[100];
	puts("Enter your id:");
	gets(id);
	password=getpass("Enter your password:");
	while(fread(&a,sizeof(a),1, fp))
	{
		if((strcmp(a.id,id)==0) && (strcmp(a.pass,password)==0))
		{
			do
			{
				printf("1.Reserve\n 2.Cancell\n 3.Enquiry\n 4.Return to the main menu\n");
				//printf("Enter your choice:");//
				scanf("%d", &ch);

				switch(ch)
				{
					case 1:
						reserve();
						break;
					case 2:
						cancell();
						break;
					case 3:
						enquiry();
						break;
					default :
						break;

				}
			}
			while(ch <= 3);
			getchar();
		}
	}
}
void manage()
{
	int ch;
	FILE *fp;
	char c;
	login a;
	printf(".........WELCOME TO THE USER MANAGEMENT MENU........\n");
	do
	{
		printf("1.Create id data base\n 2.Add details\n 3.Display details\n 4.Return to the main menu\n");
		printf("Enter your choice:");
		scanf("%d", &ch);
			switch(ch)
			{
				case 1:
					fp = fopen("id.txt","r");
					do
					{
						getid(a);
						fwrite(&a,sizeof(a),1, fp);
						printf("Do you want to add one more record\n");
						printf("y-Yes\n n-No\n");
						scanf("%c", &c);
					}
					while(c == 'y');
					fclose(fp);
					break;

				case 2:
					fp = fopen("id.txt","w");
					getid(a);
					fwrite(&a,sizeof(a), 1,fp);
					fclose(fp);
					break;

				case 3:
					fp = fopen("id.txt","w");
					//fseek(0);//
					while(fread(&a, sizeof(a),1, fp))
					{
						displayid(a);
					}
					fclose(fp);
					break;
				default :
					break;
				}
		}
	while(ch<=3)
	getchar();
}
