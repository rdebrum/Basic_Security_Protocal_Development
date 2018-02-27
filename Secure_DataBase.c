//Basic Database - secure through user interface
//
//Eduardo Ortega
//
//SecDev

//Include statements
#include <stdio.h>		//C standard I/O Library
#include <stdlib.h>		//C standard Library
#include <string.h>		//C string Library

//Define Statements
#define MAX_LENGTH_NAME 	20
#define ZIP_LENGTH 			5
#define MAX_SIZE			5

//Struct for the person's information
struct Employee
{
	char 	name[MAX_LENGTH];
	int 	zip[ZIP_LENGTH];
	int 	number[NUMB_LENGTH];
	char 	*email;
}

//Forward Declarations
void print_db(Employee *db, int count);
int db_search(Employee *db, int count, char target[MAX_LENGTH_NAME]);

int main(int argc, char *argv[])
{
	//callocing memory for the database
	Employee *db = calloc(MAX_SIZE, sizeof(Employee));
	//local variables used
	int call = 1;
	int count = 0;
	char target[MAX_LENGTH_NAME];
	int search_entry;
	//Welcme statement
	printf("Welcome to the database, please follow the menu\n"); 
	printf("actions to interact with the databases\n");
	while(true)
	{
		//Menu statement
		printf("\nMAIN MENU\n");
		printf("1 - prints database\n");
		printf("2 - add employee to database\n");
		printf("3 - will get an employee information\n");
		printf("4 - will quit\n");
		printf("enter your choice \n");
		scanf("%d", &call);
		//prints database
		if(call == 1)
		{
			printf("Printing the Datatbase\n");
			print_db(db, count);
		}
		//adds employee
		else if(call == 2)
		{

		}
		//search for employee info
		else if(call == 3)
		{
			printf("\nSearching by name, enter the person you are looking for\n");
			scanf("%s", &target);
			search_entry = db_search(db, count, target);
			if(search_entry < 0)
			{
				printf("\nERROR: person not found\n");
			}
			else
			{
				printf("Person found, it shall be in the followin format\n");
				printf("Name\tzip\tnumber\temail\n");
				printf("%s\t%d\t%d\t%s\n", 
						db[search_entry].name, db[search_entry].zip, 
						db[search_entry].number, db[search_entry].email);
			}
		}
		//will exit
		else if(call == 4)
		{
			printf("\nquitting\n");
			break;
		}
		else if((call < 1) || (call > 4))
		{
			printf("\n\n ERROR: choice if not valid\n\n");
		}
	}
	//exit statement
	printf("\nThank you for using this database\n");
	free(db);
	return 0;
}

void print_db(Employee *db, int count)
{
	int i;
	printf("\nName\tzip\tnumber\temail\n");
	for(i = 0; i < count; i++)
	{
		printf("\n%s\t%d\t%d\t%s\n", db[i].name, db[i].zip, db[i].number, db[i].email);
	}
	if(count == 0)
	{
		printf("The dtabase is empty - add a entry via the number 2 option\n");
	}
}

int db_search(Employee *db, int count, char target[MAX_LENGTH_NAME])
{
	int i = 0;
	for(i = 0; i < count, i++)
	{
		if(!(strcmp(target, db[i].name)))
		{
			return i;
			break;
		}
	}
	return -1;
}

int add_employee(Employee *db, 
