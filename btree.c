#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include <string.h>
void *insert(node* root,char *newName){

  if(root == NULL){
    root = (node *)malloc(sizeof(node));
    root->name = newName;
  }
  else if(strcmp(newName,root->name)==-1){
    if(root->leftNode == NULL){
      root->leftNode = (node *)malloc(sizeof(node));
      root->leftNode->name = newName;
    }
    else{
      insert(root->leftNode,newName);
    }
   }
  
  else if(strcmp(newName, root->name)){
    if(root->rightNode == NULL){
      root->rightNode = (node *)malloc(sizeof(node));
      root->rightNode->name = newName;
    }
    else{
      insert(root->rightNode,newName);
    }
  }
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


void fileToTree(node* root, char *fileName){
  FILE *file = fopen(fileName, "r");
  if(file){
    char names[255];
    char *name;
    while(fgets(names,150,file)){
      name = (char *)strtok(names,"\n");
      printf("%s",name);
      insert(root,names);
    }
    
  }
  fclose(file);
}


void ui(){
  printf("Welcome to the employee manager");
  int choice = -1;
  while(choice != 0){
  }
}
/*
int main(){
  node *n = (node *)malloc(sizeof(node));
  n->name = "";
  //printTree(n);
  printf("\n");
  insert(n,"a");
  insert(n,"b");
  insert(n,"c");
  insert(n,"d");
  fileToTree(n,"namesP.txt");
  printTree(n);
  return 0;
}

*/
