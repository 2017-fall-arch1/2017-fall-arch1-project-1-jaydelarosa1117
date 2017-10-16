#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include <string.h>


void printTree(node* root){
  if(root == NULL||root->name==NULL){
    return;
  }
  printTree(root->leftNode);
  printf("%s\n",root->name);
  printTree(root->rightNode);
}

node *insert(node* root,char *newName){     
  if(root == NULL||root->name==NULL){
    char *name = malloc(255);
    strcpy(name,newName);
    //printf("INSERTED: **%s**\n", name);
    root = (node*)malloc(255);
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

node *removeNull(node* root){
  return NULL;
}

node *removeNode(node* root, char *newName){
  if(root == NULL){
    return root;
  }
  else if(strcmp(newName,root->name)==0){
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

void writerHelper(node* root, FILE *file){
  if(root==NULL || root->name==NULL){
    return;
  }
  printf("%s\n",root->name);
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
    int lines = 0;
    while(feof(file)==0){
      char x[255];
      fscanf(file,"%s",x);
      lines++;
      printf("%d\n",lines);
    }
    FILE *file2 = fopen(fileName, "r");
    lines-=1;
    int i;
    for(i=0;i<lines;i++){
      char x[255];
      fscanf(file2,"%s",x);
      printf("%s",x);
      root = insert(root,x);
    }
    fclose(file);
  }
  return root;
}
