#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

void *insert(node* root,int num){
  if(root == NULL){
    root = (node *)malloc(sizeof(node));
    root->item = num;
  }
  else if(num < root->item){
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

void fileToTree(node* root){
  FILE *file;
  file = fopen("p.txt", "r");
  if(file){
    int c;
    while((c=getc(file)) != EOF){
      insert(root,(int)c);
    }
  }
  fclose(file);
}


node *removeNode(node* root, int num){
  if(root == NULL){
    return root;
  }
  else if(root->item == num){
    if(root->leftNode == NULL && root->rightNode == NULL){
      free(root);
      return NULL;
    }
    else if(root->rightNode == NULL){
      int mx = maxNode(root->leftNode);
      root->item = mx;
      root->leftNode =  removeNode(root->leftNode,mx);
    }
    else if(root->leftNode == NULL){
      int mn = minNode(root->rightNode);
      root->item = mn;
      root->rightNode =  removeNode(root->rightNode,mn);
    }
    else{
      int mn = minNode(root->rightNode);
      root->item = mn;
      root->rightNode =  removeNode(root->rightNode,mn);
    }
  }
  else if(num < root->item){
    root->leftNode = removeNode(root->leftNode,num);
  }
  else if(num > root->item){
    root->rightNode = removeNode(root->rightNode,num);
  }
  return root;
}


int maxNode(node* root){
  if(root->rightNode == NULL){
    return root->item;
  }
  return maxNode(root->rightNode);
}
int minNode(node* root){
  if(root->leftNode == NULL){
    return root->item;
  }
  return minNode(root->leftNode);
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
  n->item = 50;
  fileToTree(n);
  printTree(n);
  return 0;
}
