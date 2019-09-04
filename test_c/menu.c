/* compile: gcc -Wall -c "%f" -L c:/sqlite -l sqlite3 -I "include"
 * build: gcc -Wall -o "%e" "%f" -L c:/sqlite -l sqlite3 -I "include"
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void initDB(){
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
	sqlite3_close(db);
	return;
}

void addAccount() {
	char *fname=NULL;
	char *lname=NULL;
	char *account=NULL;
	char *routing=NULL;
	char *ans=NULL;
	printf("First Name: ");
	scanf("%s", fname);
	printf("Last Name: ");
	scanf("%s", lname);
	printf("Account Number: ");
	scanf("%s", account);
	printf("Routing Number: ");
	scanf("%s", routing);
	printf("add another routing number?(y/n): ");
	scanf("%s", ans);
}

int main() {
	int choice;
	int loop = 1;

	while(loop == 1) {
		printf("Please select a menu item: \n");
		printf("1. Add Account \n");
		printf("2. Delete Account \n");
		printf("3. Edit Account \n");
		printf("4. Create Database With Table \n");
		printf("5. exit program \n");
		scanf("%d",&choice); //replace with fgets

		switch(choice) {
			case 1: {
				addAccount();
				break;
			}
			case 2: {
				printf("Delete Account \n");
				break;
			}
			case 3: {
				printf("Edit Account \n");
				break;
			}
			case 4: {
				initDB();
				break;
			}
			case 5: {
				printf("Exiting program... \n");
				loop = 0;
				break;
			}
			default: {
				printf("Invalid input... \n");
			}
		}
	}
	return(0);
}
