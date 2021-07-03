
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
#include <ctype.h> //for toupper
#include <stdlib.h> //for exit
void unlist();
void search();
void payment();
void modify();
void list();
void add();
int main()
{
	char choice;
	printf("\n\t\t------WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM---");

	while (1)
	{
		printf("\n Enter\n A : for adding new records.\n L : for list of records \n M : for modifying records.\n P : for payment \n S : for searching records. \n D : for deleting records.\n E : for exit\n ");
		choice = getchar();
		choice = toupper(choice);
		switch (choice)
		{
		case 'P':
			payment();
			break;
		case 'A':
			add();
			break;
		case 'L':
			list();
			break;
		case 'M':
			modify();
			break;
		case 'S':
			search();
			break;
		case 'D':
			unlist();
			break;
		case 'E':
			printf("\n\n\t\t\t\tTHANK YOU");
			getch();
			exit(0);
			break;
		default:
			printf("Incorrect Input");
			printf("\n Press any key to continue");
			getch();
			// return 1;
			// break;
		
		}
	}
}

void add()
{ //add record
	printf("OKay");
	getch();
}
void list()
{
	printf("OKay");
	getch();
	//list record
}
void modify()
{
	printf("OKay");
	getch();
	//modify records
}
void payment()
{
	printf("OKay");
	getch();

	//void due
}
void search()
{
	printf("OKay");
	getch();

	//search
}
void unlist()
{
	printf("Delete check");
	getch();

	//delete record
}
