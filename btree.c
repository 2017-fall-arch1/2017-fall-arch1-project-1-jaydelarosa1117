#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void *insert(node* root,int num){
  if(root == NULL){
    root = (node *)malloc(sizeof(node));
    root->item = num;
    printf("im in side the assign\n");
  }
  else if(num < root->item){
    printf("going left\n");
    if(root->leftNode == NULL){
      root->leftNode = (node *)malloc(sizeof(node));
      root->leftNode->item = num;
    }
    else{
      insert(root->leftNode,num);
    }
   }
  
  else if(num > root->item){
    if(root->rightNode == NULL){
      root->rightNode = (node *)malloc(sizeof(node));
      root->rightNode->item = num;
    }
    else{
      insert(root->rightNode,num);
    }
  }
}  

void *removeNode(node* root, int num){
}

void printTree(node* root){
  if(root == NULL){
    return;
  }
  printTree(root->leftNode);
  printf("%d\n",root->item);
  printTree(root->rightNode);
}

int main(){
  node *n = (node *)malloc(sizeof(node));
  n->item = 1010;
  node *ln  =(node *)malloc(sizeof(node));
  node *rn  =(node *)malloc(sizeof(node));
  //ln->item = 1009;
  //rn->item = 1011;
  //n->leftNode = ln;
  //n->rightNode = rn;
  insert(n,0);
  insert(n,12);
  insert(n,42);
  insert(n,3000);
  insert(n,2000);
  insert(n,6000);
  insert(n,6000);
  insert(n,6000);
  printTree(n);
  if(n->leftNode == NULL){
    //  printf("it is null\n");
  }
  return 0;
}
