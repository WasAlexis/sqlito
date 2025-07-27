#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
  printf("r => run file \n");
  printf("c => clean console \n");
  printf("q => quit \n");
}

int main() {
  // setup
  char user[50], database[50], user_password[100], file[50];
  printf("user: ");
  scanf("%s", user);

  printf("password: ");
  scanf("%s", user_password);

  char option;
  char actions[3] = {'r', 'c', 'q'};
  
  printf("Database: ");
  scanf("%s", database);
  
  printf("file name: ");
  scanf("%s", file);
  
  char comando[128];
  menu();
  do {
  printf("> ");
    scanf(" %c", &option);
    
    if (option == actions[0]) {
      sprintf(comando, "PGPASSWORD=%s psql -U %s -d %s -f %s", user_password, user, database, file);
      system(comando);
    } else if (option == actions[1]) {
      system("clear");
      menu();
    } else if (option == actions[2]) {
      printf("closing \n");
    } else {
      printf("that option doesn't exist \n");
    }
  } while (option != actions[2]);
  return 0;
}