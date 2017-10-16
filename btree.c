#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include <string.h>

node *insert(node* root,char *newName){
  if(root == NULL){
    char *name = malloc(sizeof(newName));
    strcpy(name,newName);
    root = (node*)malloc(sizeof(node));
    root->name = name;
    return root;
  }
  else if(strcmp(newName,root->name)==-1){
     root->leftNode = insert(root->leftNode,newName);
   }
  
  else if(strcmp(newName, root->name)){
    root->rightNode = insert(root->rightNode,newName);
  }
  return root;
}  


node *removeNode(node* root, char *newName){
  if(root == NULL){
    return root;
  }
  else if(~strcmp(newName,root->name)){
    if(root->leftNode == NULL && root->rightNode == NULL){
      free(root);
      return NULL;
    }
    else if(root->rightNode == NULL){
      char *mx = maxNode(root->leftNode);
      root->name = mx;
      root->leftNode =  removeNode(root->leftNode,mx);
    }
    else if(root->leftNode == NULL){
      char *mn = minNode(root->rightNode);
      root->name = mn;
      root->rightNode =  removeNode(root->rightNode,mn);
    }
    else{
      char *mn = minNode(root->rightNode);
      root->name = mn;
      root->rightNode =  removeNode(root->rightNode,mn);
    }
  }
  else if(strcmp(newName,root->name)==-1){
    root->leftNode = removeNode(root->leftNode,newName);
  }
  else if(strcmp(newName,root->name)){
    root->rightNode = removeNode(root->rightNode,newName);
  }
  return root;
}


char* maxNode(node* root){
  if(root->rightNode == NULL){
    return root->name;
  }
  return maxNode(root->rightNode);
}
char* minNode(node* root){
  if(root->leftNode == NULL){
    return root->name;
  }
  return minNode(root->leftNode);
}
  


void printTree(node* root){
  if(root == NULL){
    return;
  }
  printTree(root->leftNode);
  printf("%s\n",root->name);
  printTree(root->rightNode);
 }

void writerHelper(node* root, FILE *file){
  if(root==NULL){
    return;
  }
  fprintf(file,"%s\n",root->name);
  writerHelper(root->leftNode,file);
  writerHelper(root->rightNode,file);
  
}
void treeToFile(node* root, char* fileName){
  FILE *file = fopen(fileName,"w");
  writerHelper(root,file);
}


node *fileToTree(node* root, char *fileName){
  FILE *file = fopen(fileName, "r"); 
  if(file!=NULL){
    char line[100];
    char name[100];
    int i = 1;
    while(fgets(line,255,file)!=NULL){
      sscanf(line,"%s", name);
      root = insert(root,name);
      i++;
    }
    
    fclose(file);
  }
  return root;
}


void ui(){
  printf("Welcome to the employee manager\nWhat would you like to do\n");
  int choice = -1;
  node *employees = NULL;
  while(choice != 0){
    printf("0 quit\n1 print employees\n2 add employee\n3 delete employee\n");
    printf("4 read from file\n5 store on file\n");
    scanf("%d",&choice);

    if(choice == 1){
      printf("\n");
      printTree(employees);
      printf("\n");
    }
    else if(choice == 2){
      char newName[150];
      printf("enter new employee name\n");
      scanf("%[^\t\n]s",newName);
      employees = insert(employees, newName);
    }
    else if(choice == 3){
      char name[150];
      printf("enter employee to remove\n");
      scanf("%s",name);
      removeNode(employees,name);
    }
    else if(choice == 4){
      char fileName[150];
      printf("enter file to read from\n");
      scanf("%s",fileName);
      employees = fileToTree(employees,fileName);
    }
    else if(choice == 5){
      char fileName[150];
      printf("enter file to write to\n");
      scanf("%s",fileName);
      treeToFile(employees,fileName);
    }
  }
}

int main(){
  //ui();
  node *n;// = (node*)malloc(sizeof(node));
  n = insert(n,"thing of dreams");
  printTree(n);
  return 0;
}

