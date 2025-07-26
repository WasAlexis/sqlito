#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
  printf("r => run file \n");
  printf("c => clean console \n");
  printf("q => quit \n");
}

int main() {
  char option;
  char actions[3] = {'r', 'c', 'q'};
  
  char database[50];
  printf("Database: ");
  scanf("%s", database);
  
  printf("file name: ");
  char file[50];
  scanf("%s", file);
  
  char comando[128];
  menu();
  do {
  printf("> ");
    scanf(" %c", &option);
    
    if (option == actions[0]) {
      sprintf(comando, "PGPASSWORD=yourpassword-here psql -U your-username-here -d %s -f %s", database, file);
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