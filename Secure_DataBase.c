//Basic Database - user interface Security
//Avaiablity - Yes
//Confidential - No
//Intregity - No
//Eduardo Ortega
//
//SecDev

//Include statements
#include <stdio.h>		//C standard I/O Library
#include <stdlib.h>		//C standard Library
#include <string.h>		//C string Library

//Define Statements
#define MAX_LENGTH_NAME	20
#define ZIP_LENGTH 	5
#define MAX_COUNT	5

//Struct for the person's information
struct Employee
{
	char 	*name;
	char	*zip;
	char 	*number;
	char 	*email;
};

//Forward Declarations
void 	print_db(struct Employee *db, int count);
int 	db_search(struct Employee *db, char *target);
int 	add_check(struct Employee *db, int count, char *add_name, 
		char *add_zip, char *add_number, char *add_email);
int 	check_name(char *name,struct Employee *db);
int 	check_zip(char *zip);
int 	check_email(char *email);
int 	check_number(char *number);
int	check_number_type_one(char *number);
int 	check_number_type_two(char *number);
int	check_number_type_three(char *number);

int main()
{
	//callocing memory for the database and setting everything to NULL
	struct Employee *db = calloc(MAX_COUNT, sizeof(struct Employee));
	int x;
	/*for(x = 0; x < MAX_COUNT; x++)
	{
		printf("name insert\n");	
		strcpy(db[x].name, "none");
		printf("zip\n");
		strcpy(db[x].zip, "none");
		printf("numb\n");
		strcpy(db[x].number, "none");
		printf("email\n");
		strcpy(db[x].email, "none");
	}*/
	printf("local variables dec\n");
	//local variables used
	int 	call = 0;
	int 	count = 0;
	int 	delete_fin = 0;
	char 	*target;
	char 	*add_name;
	char  	*add_zip;
	char 	*add_number;
	char 	*add_email;
	int 	search_entry;
	
	//Welcome statement
	printf("Welcome to the database, please follow the menu\n"); 
	printf("actions to interact with the databases\n");
	
	//Main Loop
	while(call >= 0 || call <= 5)
	{
		if(call == 0)
		{
			printf("\nMAIN MENU\n");
			printf("0 - Prints Main Menu\n");
			printf("1 - Prints database\n");
			printf("2 - Add entry to database\n");
			printf("3 - Will get an entry information\n");
			printf("4 - will delete a entry\n");
			printf("5 - Will quit\n");
			printf("enter your choice \n");
			scanf("%d", &call);
		}

		//prints database
		if(call == 1)
		{
			printf("Printing the Datatbase\n");
			print_db(db, count);
			printf("Going to Main Menu\n");
			call = 0;
		}

		//adds employee
		else if(call == 2)
		{
			if(count == MAX_COUNT)
			{
				printf("The Database is already filled, delete a record");
				printf("to ensure that you may add a entry\n");
				call = 0;
			}
			printf("When adding a entry to this database, please follow the constraints as descirbed below\n");
			printf("NAME: 20 characters or less\n");
			printf("ZIP: must be 5 numbers\n");
			printf("NUMBER: must be in the following formats, no spaces\n");
			printf("(XXX)XXX-XXXX\nXXX-XXX-XXXX\nXXXXXXXXXX\n");
			printf("EMAIL: must be in the following format\n");
			printf("name@domain.name (the second name is arbitrary\n");
			count = add_check(db, count, add_name,
					add_zip, add_number, add_email);
			call = 0;
		}

		//search for entry info
		else if(call == 3)
		{
			printf("\nSearching by name, enter the person you are looking for\n");
			scanf("%s", &target);
			if(strlen(target) > MAX_LENGTH_NAME)
			{
				printf("Names must be less than 20 characters, back to main menu\n");
				call = 0;
			}
			while(target[0] < 'a' || target[0] > 'z')
			{
				printf("Enter valid command\n");
				scanf("%s", &target);
			}
			search_entry = db_search(db, target);
			if(search_entry < 0)
			{
				printf("\nERROR: person not found\n");
			}
			else
			{
				printf("Person found, it shall be in the following format\n");
				printf("Name\tZIP\tNumber\tEmail\n");
				printf("%s\t%d\t%d\t%s\n", 
						db[search_entry].name, db[search_entry].zip, 
						db[search_entry].number, db[search_entry].email);
			}
			call = 0;
		}

		//will delete a record
		else if(call == 4)
		{
			printf("\nSearching by name, enter the person you are looking for\n");
			scanf("%s", &target);
			/*while(strlen(target) > MAX_LENGTH_NAME)
			{
				printf("Names must be less than 20 characters, Enter again\n");
				scanf("%s", target);
			}*/
			printf("searching...\n");
			search_entry = db_search(db, target);
			if(search_entry < 0)
			{
				printf("\nERROR: person not found\n");
			}
			else
			{
				printf("Person found, are you sure you want to delete entry?\n");
				printf("Name\tzip\tnumber\temail\n");
				printf("%s\t%d\t%d\t%s\n", 
						db[search_entry].name, db[search_entry].zip, 
						db[search_entry].number, db[search_entry].email);
				scanf("\nEnter: yes(1) or no (2)%s\n", &delete_fin);
				if(delete_fin == 1)
				{
						strcpy(db[search_entry].name, NULL);
						strcpy(db[search_entry].zip, NULL);
						strcpy(db[search_entry].number, NULL);
						strcpy(db[search_entry].email, NULL);
						count = count - 1;
				}
				else
				{
					printf("Entry not deleted\n");
				}
			}
			call = 0;
		}

		//will exit
		else if(call == 5)
		{
			printf("quitting\n");
			break;
		}
		else if((call < 0) || (call > 5))
		{
			printf("\n\nERROR: choice if not valid\n\n");
			call = 0;
		}
	}
	//exit statement
	printf("\nThank you for using this database\n");
	free(db);
	return 0;
}

//function to print the database
void print_db(struct Employee *db, int count)
{
	int i;
	printf("Printing the Data Base in the following format\n");
	printf("\nName\tzip\tnumber\temail\n");
	for(i = 0; i < MAX_COUNT; i++)
	{
		if(db[i].name != NULL)
		{
			printf("\n%s\t%d\t%d\t%s\n", db[i].name, db[i].zip, db[i].number, db[i].email);			
		}
	}
	if(count == 0)
	{
		printf("The database is empty - add a entry via the number 2 option\n");
	}
}

//functions to find teh entry in teh database
int db_search(struct Employee *db, char *target)
{
	int i = 0;
	printf("loop\n");
	for(i = 0; i < MAX_COUNT; i++)
	{
		
		if(!(strcmp(target, db[i].name)))
		{
			return i;
			break;
		}
	}
	return -1;
}

//function to add entry to the database
int add_check(struct Employee *db, int count, char *add_name, 
			char *add_zip, char *add_number, char *add_email)
{
	int i;
	int add = 0;
	int add_check = 0;
	printf("Enter the person you would like to add to this database.\n");
	printf("This is all case sensitive, MUST BE LOWERCASE FOR ALL ENTRIES\n");
	
	//checks name
	printf("Name:");
	scanf("%s", add_name);
	while(add_name[0] < 'a' || add_name[0] > 'z')
	{
		printf("\nType in a valid command\n");
		scanf("%s", add_name);
	}	
	printf("check\n");
	add_check = check_name(add_name, db);
	if(add_check == 1)
	{
		add++;
	}
	else
	{
		printf("\nERROR: Name was added incorrectly\n");
		return count;
	}

	//check zip
	printf("\nZIP:");
	scanf("%s", add_zip);
		while(add_name[0] < 'a' || add_name[0] > 'z')
	{
		printf("\nType in a valid command: ");
		scanf("%s", add_zip);
	}
	add_check = check_zip(add_zip);
	if(add_check == 1)
	{
		add++;
	}
	else
	{
		printf("\nERROR: ZIP was added incorrectly\n");
		return count;
	}

	//checks number
	printf("\nNumber:");
	scanf("%s", add_number);
	while(add_number[0] < '0' || add_number[0] > '9')
	{
		printf("\nType in a valid command: ");
		scanf("%s", add_number);
	}
	add_check = (int)check_number(add_number);
	if(add_check == 1)
	{
		add++;
	}
	else
	{
		printf("\nERROR: Number was added incorrectly\n");
		return count;
	}

	//checks email
	printf("\nEmail:");
	scanf("%s", &add_email);
	while(add_email[0] != '\0')
	{
		printf("\nType in a valid command: ");
		scanf("%s", &add_email);
	}
	add_check = check_email(add_email);
	if(add_check == 1)
	{
		add++;
	}
	else
	{
		printf("\nERROR: Email was added incorrectly\n");
		return count;
	}
	if(add == 4)
	{
		for(i = 0; i < MAX_COUNT; i++)
		{
			if(db[i].name == NULL)
			{
				
				printf("adding %s to database\n", add_name);
				strcpy(db[i].name, add_name);
				strcpy(db[i].zip, add_zip);
				strcpy(db[i].number, add_number);
				strcpy(db[i].email, add_number);
				return count + 1;
			}
		}
	}
	return count;
}

//function to check name
int check_name(char *name,struct Employee *db)
{
	int name_length = strlen(name);
	
	if(name_length > MAX_LENGTH_NAME)
	{
		return 0;
	}
	int i;
	for(i = 0; i < name_length; i++)
	{
		if(name[i] < 'a' || name[i] > 'z')
		{
			printf("ERROR: Must be lowercase\n");
			return 0;
		}
	}
	printf("x\n");
	int x;
	for(x = 0; i < MAX_COUNT; i++)
	{
		printf("y\n");
		if(name == db[i].name)
		{
			printf("ERROR: Duplicate name found\n");
			return 0;
		}
	}
	return 1;
}

//function to check zip
int check_zip(char *zip)
{
	int zip_len = strlen(zip);
	
	if(zip_len != ZIP_LENGTH)
	{
		return 0;
	}
	int i;
	for(i = 0; i < zip_len; i++)
	{
		if((zip[0] < '0' || zip[0] > '9'))
		{
			return 0;
		}
	}
	return 1;
}

//function to check email
int check_email(char *email)
{
	int email_length = strlen(email);
	int check_point_one = 0;
	int check_point_two = 0;
	int i;
	if((email[0] < 'a' || email[0] > 'z'))
	{
		return 0;
	}
	else
	{
		for(i = 1; i < email_length; i++)
		{
			if(email[i] == '@')
			{
				check_point_one = i + 1;
				break;
			}
			else
			{
				if(email[i] < 'a' || email[i] > 'z')
				{
					return 0;
				}
			}
		}
		for(; check_point_one < email_length; check_point_one++)
		{
			if(email[check_point_one] == '.')
			{
				check_point_two = check_point_one + 1;
				break;
			}
			else
			{
				if(email[check_point_one] < 'a' ||
					email[check_point_one] > 'z')
					{
						return 0;
					}
			}
		}
		for(; check_point_two < email_length; check_point_two++)
		{
			if(email[check_point_two] < 'a' ||
				email[check_point_two] > 'z')
				{
					return 0;
				}
		}
		return 1;
	}
}

//main check number functions
int check_number(char *number)
{
	int check_type_one 		= check_number_type_one(number);
	int check_type_two 		= check_number_type_two(number);
	int check_type_three 	= check_number_type_three(number);
	int check_all 			= check_type_one + check_type_two + check_type_three;
	return check_all;
}

//functions to check number format
//function for the first type
int check_number_type_one(char *number)
{
	int number_length = strlen(number);
	if(number[0] != '(' || number_length > 13)
	{
		return 0;
	}
	int i;
	for(i = 1; i < 4; i++)
	{
		if(number[i] < '0' || number[i] > '9')
		{
			return 0;
		}
	}
	if(number[4] != ')')
	{
		return 0;
	}
	int x;
	for(x = 5; i < 8; i++)
	{
		if(number[x] < '0' || number[x] > '9')
		{
			return 0;
		}
	}
	if(number[8] != '-')
	{
		return 0;
	}
	int n;
	for(n = 9; i < number_length; i++)
	{
		if(number[n] < '0' || number[n] > '9')
		{
			return 0;
		}
	}
	return 1;
}

//function for the second type
int check_number_type_two(char *number)
{
	int number_length = strlen(number);
	if(number_length > 12)
	{
		return 0;
	}
	int i;
	for(i = 0; i < 3; i++)
	{
		if(number[i] < '0' || number[i] > '9')
		{
			return 0;
		}
	}
	if(number[3] != '-')
	{
		return 0;
	}
	int x;
	for(x = 4; i < 7; i++)
	{
		if(number[x] < '0' || number[x] > '9')
		{
			return 0;
		}
	}
	if(number[7] != '-')
	{
		return 0;
	}
	int n;
	for(n = 8; i < number_length; i++)
	{
		if(number[n] < '0' || number[n] > '9')
		{
			return 0;
		}
	}
	return 1;
}

//function for the third type
int check_number_type_three(char *number)
{
	int number_length = strlen(number);
	if(number_length > 10)
	{
		return 0;
	}
	int i;
	for(i = 0; i < number_length; i++)
	{
		if(number[i] < '0' || number[i] > '9')
		{
			return 0;
		}
	}
	return 1;
}
