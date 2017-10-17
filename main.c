#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include <string.h>

void ui(){
  printf("Welcome to the employee manager\nWhat would you like to do\n");
  int choice = -1;
  node *employees = NULL;
  while(1){
    printf("0 quit\n1 print employees\n2 add employee\n3 delete employee\n");
    printf("4 read from file\n5 store on file\n");
    scanf("%d",&choice);
    
    if(choice == 0){
      printf("\nsave before quitting?\n0 no\n1 yes\nanykey to cancel\n");
      scanf("%d", &choice);
      if(choice == 0){
	return;
      }
      else if(choice == 1){
	char fileName[255];
	printf("enter file to write to\n");
	scanf("%s",fileName);
	treeToFile(employees,fileName);
	return;
      }
    }
    else if(choice == 1){
      printf("\n");
      printTree(employees);
      printf("\n");
    }
    else if(choice == 2){
      char newName[255];
      printf("enter new employee name\n");
      scanf(" %[^\t\n]s",&newName);
      employees = insert(employees, newName);
    }
    else if(choice == 3){
      char name[255];
      printf("enter employee to remove\n");
      scanf(" %[^\t\n]s",&name);
      employees = removeNode(employees,name);
    }
    else if(choice == 4){
      char fileName[255];
      printf("enter file to read from\n");
      scanf("%s",fileName);
      employees = fileToTree(employees,fileName);
    }
    else if(choice == 5){
      char fileName[255];
      printf("enter file to write to\n");
      scanf("%s",fileName);
      treeToFile(employees,fileName);
    }
    choice = 0;
  }
}

int main(){
  ui();
  return 0;
}
