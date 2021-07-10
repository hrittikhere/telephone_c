
/*
With this mini project in C Telecom Billing System, you can perform and manage
billing operations like they do in Telecom companies. Here, you can add records
with name, phone number and the amount of payment. You can view, modify, search
and delete existing records. You can also make payment by providing your phone
number instead of name. All data added or modified are recorded in a file. This
project will teach you how to add, list, edit, search and delete records using file
handling.
The functions and features used in this project are listed below:


 Add new records: add new data into file with name, phone number and
amount to be paid
 View list of records – lists all telephone billing records (as shown in
screenshot 3)
 Modify records – edit the added records; name, phone number and/or
amount of payment can be edited
 View payment – shows amount to be paid
 Search records – search for added/updated records in file
 Delete records – removes data permanently from file
This project is limited to the functions aforementioned. You can add new features as you
like to make this project a better one.*/

#include <stdio.h>
#include <stdlib.h> //for exit
#include <conio.h>
#include <windows.h>


struct subscriber
{
	char phonenumber[20];
	char name[50];
	float amount;
} s;
void gotoxy(int, int);
void addrecords();
void listrecords();
void modifyrecords();
void deleterecords();
void searchrecords();
void payment();
char get;
int main()
{
	int phonenumber;
	char choice;

	system("cls");
	printf("\t\t****************************************************************");
	printf("\n\t\t  ------WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM------");
	printf("\n\t\t****************************************************************");
	printf("\n\n\n\t\t Press Any Key To Continue. . ");
	getch();
	system("cls");

	printf("\n\n\xDB\xDB\xDB\xDB\xDB  TELECOM BILLING SYSTEM  \xDB\xDB\xDB\xDB\xDB");

	while (1)
	{
		printf(" \n\n \xDB\xDB 1 : Add New Records.\n\n \xDB\xDB 2 : List Of Records");
		printf("\n\n \xDB\xDB 3 : Modify Records.\n\n \xDB\xDB 4 : For Payment");
		printf("\n\n \xDB\xDB 5 : Search Records.");
		printf("\n\n \xDB\xDB 6 : Delete Records.\n\n \xDB\xDB 7 : Exit\n");
		printf("\n Enter Your Choice:-");
		choice = getche();

		switch (choice)
		{
		case '1':
			addrecords();
			break;
		case '2':
			listrecords();
			break;
		case '3':
			modifyrecords();
			break;
		case '4':
			payment();
			break;
		case '5':
			searchrecords();
			break;
		case '6':
			deleterecords();
			break;
		case '7':
			system("cls");
			printf("Thank you");
			getch();
			exit(0);
			break;
		default:
			system("cls");
			system("color 0F");
			gotoxy(30, 20);
			printf("Incorrect Input");
			printf("\a......");
			gotoxy(30, 24);
			printf("Any key to continue");
			getch();
		}
	}
}
COORD coord = {0, 0};
// sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res, cursor_size;
void gotoxy(int x, int y)
{

	coord.X = x;
	coord.Y = y;
	// X and Y coordinates

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void addrecords()
{
	FILE *f;
	char test;
	f = fopen("pro.txt", "ab+");
	if (f == 0)
	{
		f = fopen("pro.txt", "wb+");
		system("cls");
		printf("Please wait while we configure your computer");
		printf("\npress any key to continue");
		getch();
	}
	while (1)
	{
		system("cls");
		printf("\n Enter phone number: ");
		scanf("%s", &s.phonenumber);
		printf("\n Enter name: ");
		fflush(stdin);
		scanf("%s", &s.name);
		printf("\n Enter amount: ");
		scanf("%f", &s.amount);
		fwrite(&s, sizeof(s), 1, f);
		fflush(stdin);
		printf("\n\n Record Is Successfully Added");
		printf("\n Press esc Key to exit or Press any other key to add other record:");
		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
	system("cls");
}
void listrecords()
{
	FILE *f;
	int i;
	if ((f = fopen("pro.txt", "rb")) == NULL)
		exit(0);
	system("cls");
	printf("Phone Number\t\tUser Name\tAmount\n");
	for (i = 0; i < 79; i++)
		printf("-");
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		printf("\n%s\t\t%s\t\tRs. %.2f /-", s.phonenumber, s.name, s.amount);
	}
	printf("\n");
	for (i = 0; i < 79; i++)
		printf("-");

	fclose(f);
	printf("\n\nPress Any Key To Go Back");
	getch();
	system("cls");
}
void deleterecords()
{
	FILE *f, *t;
	char phonenumber[20];
	system("cls");
	f = fopen("pro.txt", "rb+");
	t = fopen("pro1.txt", "wb+");
	do
	{
		rewind(f);
		printf("Enter the phone number to be deleted from the Database: ");
		scanf("%s", phonenumber);
		while (fread(&s, sizeof(s), 1, f) == 1)
		{
			if (strcmp(s.phonenumber, phonenumber) != 0)
			{
				fwrite(&s, sizeof(s), 1, t);
			}
			else
				printf("Record deleted successfully.");
		}

		fclose(f);
		fclose(t);
		remove("pro.txt");
		rename("pro1.txt", "pro.txt");

		f = fopen("pro.txt", "rb+");
		t = fopen("pro1.txt", "wb+");
		printf("\nDo you want to delete another record (y/n):");
		fflush(stdin);
	} while (getche() == 'y' || getche() == 'Y');
	fclose(f);
	getch();
	system("cls");
}
void searchrecords()
{
	FILE *f;
	char phonenumber[20];
	int flag = 1;
	f = fopen("pro.txt", "rb+");

	fflush(stdin);
	system("cls");
	printf("Enter Phone Number to search in our database: ");
	scanf("%s", phonenumber);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.phonenumber, phonenumber) == 0)
		{
			system("cls");
			printf(" Record Found ");
			printf("\n\nPhonenumber: %s\nName: %s\nAmount: Rs.%0.2f\n", s.phonenumber, s.name, s.amount);
			flag = 0;
			break;
		}
		else if (flag == 1)
		{
			system("cls");
			printf("Requested Phone Number Not found in our database");
		}
	}
	getch();
	fclose(f);
	system("cls");
}
void modifyrecords()
{
	FILE *f;
	char phonenumber[20];
	long int size = sizeof(s);
	if ((f = fopen("pro.txt", "rb+")) == NULL)
		exit(0);
	system("cls");
	printf("Enter phone number of the subscriber to modify: ");
	scanf("%s", phonenumber);
	fflush(stdin);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.phonenumber, phonenumber) == 0)
		{
			system("cls");
			printf("\n Enter phone number: ");
			scanf("%s", &s.phonenumber);
			printf("\n Enter name: ");
			fflush(stdin);
			scanf("%[^\n]", &s.name);
			printf("\n Enter amount: ");
			scanf("%f", &s.amount);
			fseek(f, -size, SEEK_CUR);
			fwrite(&s, sizeof(s), 1, f);
			break;
		}
	}
	fclose(f);
	system("cls");
}
void payment()
{
	FILE *f;
	char phonenumber[20];
	long int size = sizeof(s);
	float amt;
	int i;
	if ((f = fopen("pro.txt", "rb+")) == NULL)
		exit(0);
	system("cls");
	printf("Enter phone number of the subscriber for payment: ");
	scanf("%s", phonenumber);
	fflush(stdin);
	while (fread(&s, sizeof(s), 1, f) == 1)
	{
		if (strcmp(s.phonenumber, phonenumber) == 0)
		{
			printf("\n ***DETAILS***");
			printf("\n Phone No.: %s", s.phonenumber);
			printf("\n Name: %s", s.name);
			printf("\n Current amount: %f", s.amount);
			printf("\n");
			for (i = 0; i < 79; i++)
				printf("-");
			printf("\n\nEnter amount of payment: ");
			fflush(stdin);
			scanf(" %f", &amt);
			s.amount = s.amount - amt;
			fseek(f, -size, SEEK_CUR);
			fwrite(&s, sizeof(s), 1, f);
			break;
		}
	}
	printf("\n\n");
	printf("System Message: THANK YOU %s FOR YOUR TIMELY PAYMENTS!!", s.name);
	getch();
	fclose(f);
	system("cls");
}
