#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include <string.h>
#include <ctype.h>

//recieves btree as parameter and prints tree in ascending order
void printTree(node* root){
  //if node or value is null return withouth printing
  if(root == NULL||root->name==NULL){
    return;
  }
  printTree(root->leftNode);
  printf("%s\n",root->name);
  printTree(root->rightNode);
}

// recieves tree and string as parameter and inserts it into the tree in an orderly manner
node *insert(node* root,char *newName){
  //when reaching an empty node assign it the string value and return the node
  if(root == NULL||root->name==NULL){
    char *name = malloc(255);
    strcpy(name,newName); // create new variable and copy value from original to remove the pointer 
    root = (node*)malloc(255); //allocate memory for new node
    root->name = name; //assign name and return node
    return root;
  }
  else if(strcmp(newName,root->name)==-1){ // if string is before the current node value then go left
     root->leftNode = insert(root->leftNode,newName);
   }
  
  else if(strcmp(newName, root->name)){ // if string is after the current node value then go right
    root->rightNode = insert(root->rightNode,newName);
  }
  
  return root;
}  

node *removeNode(node* root, char *newName){
  if(root == NULL){//if the node is null return the user was not found
    return root;
  }
  else if(strcmp(newName,root->name)==0){
    if(root->leftNode == NULL && root->rightNode == NULL){//if value  matches current node and no children free allocated memory and return null
      free(root);
      return NULL;
    }
    else if(root->rightNode == NULL){//if only has left node replace current value with max of left node and remove max of left node
      char *mx = maxNode(root->leftNode);//find max value and return
      root->name = mx; //assign max value to current node
      root->leftNode =  removeNode(root->leftNode,mx); //delete max value
    }
    else if(root->leftNode == NULL){//if only has right node replace current value with min of right node and remove min of right node
	char *mn = minNode(root->rightNode);// find min value and return
	root->name = mn; // assign min value to current node
	root->rightNode =  removeNode(root->rightNode,mn); //remove min value
      }
    else{//same as above in the case that it has both children
      char *mn = minNode(root->rightNode);
      root->name = mn;
      root->rightNode =  removeNode(root->rightNode,mn);
    }
  }
  else if(strcmp(newName,root->name)==-1){//if before than current node search on the left side 
    root->leftNode = removeNode(root->leftNode,newName);
  }
  else if(strcmp(newName,root->name)){//if after than current node search on right side
    root->rightNode = removeNode(root->rightNode,newName);
  }
  return root;
}

  //find max value in tree and return
char* maxNode(node* root){
  if(root->rightNode == NULL){
    return root->name;
  }
  return maxNode(root->rightNode);
}
  //find min value in tree and return
char* minNode(node* root){
  if(root->leftNode == NULL){
    return root->name;
  }
  return minNode(root->leftNode);
}

//recursivly prints writes tree to file
void writerHelper(node* root, FILE *file){
  if(root==NULL || root->name==NULL){
    return;
  }
  fprintf(file,"%s\n",root->name);//writes to file
  writerHelper(root->leftNode,file);//goes to left node
  writerHelper(root->rightNode,file);//goes to right node
}
//main file writer, opens file and calls helper method
void treeToFile(node* root, char* fileName){
  FILE *file = fopen(fileName,"w");
  if(file){
    writerHelper(root,file);
    fclose(file);
  }
}
//reads file and stores into tree
node *fileToTree(node* root, char *fileName){
  FILE *file = fopen(fileName,"r");
  if(file){
    char c;
    char *str = malloc(255);
    int i = 0;
    //checks file until EOF marker
    for(c = fgetc(file);c != EOF;c = fgetc(file)){
      if(c != '\n'){//if read character isnt new line
	str[i] = c;
	i++;
      }
      else{//if it is replace with a 0 and insert to tree
	str[i] = 0;
	root = insert(root,str);
	i = 0;
      }
    }
    fclose(file);
  }
  return root;
}
