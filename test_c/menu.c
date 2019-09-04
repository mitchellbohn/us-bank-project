/* compile: gcc -Wall -c "%f" -L c:/sqlite -l sqlite3 -I "include"
 * build: gcc -Wall -o "%e" "%f" -L c:/sqlite -l sqlite3 -I "include"
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void openDB(){
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;
	
	rc = sqlite3_open("bank.db", &db);

	if( rc ) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return;
	} else {
		fprintf(stderr, "Opened database successfully\n");
	}
	
	/* Create SQL statement */
	sql = "CREATE TABLE ACCT_HOLDERS("  \
	"ID INT PRIMARY KEY     NOT NULL," \
	"NAME           TEXT    NOT NULL," \
	"ROUTING        INT     NOT NULL," \
	"CHECK_NUMS     CHAR(50)," \
	"BIOMETRICS     REAL );";
	
	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	
	if( rc != SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		fprintf(stdout, "Table created successfully\n");
	}
	return;
}

void addAccount() {
	char fname[5];
	char lname[50];
	char account[12];
	char routing[9];
	printf("First Name: ");
	gets(fname);
	printf(fname);
	printf("Last Name: ");
	scanf("%s", lname);
	printf("Account Number: ");
	scanf("%s", account);
	printf("%s \n", account);
	printf("Routing Number: ");
	scanf("%s", routing);
}

void editAccount() {
	return;
}

int main() {
	int choice;
	bool loop = true;

	while(loop == true) {
		printf("Please select a menu item: \n");
		printf("1. Create/Open Database With Table \n");
		printf("2. Add Account \n");
		printf("3. Edit Account \n");
		printf("4. Delete Account \n");
		printf("5. exit program \n");
		scanf("%d",&choice); //replace with gets

		switch(choice) {
			case 1: {
				openDB();
				break;
			}
			case 2: {
				addAccount();
				break;
			}
			case 3: {
				editAccount();
				break;
			}
			case 4: {
				printf("Delete Account \n");
				break;
			}
			case 5: {
				printf("Exiting program... \n");
				loop = false;
				break;
			}
			default: {
				printf("Invalid input... \n");
			}
		}
	}
	return(0);
}
