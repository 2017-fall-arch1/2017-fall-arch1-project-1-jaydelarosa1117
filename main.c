#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

int main(){
  node *root = (node*)malloc(sizeof(node));
  root->name = "mine";
  insert(root,"his");
  return 0;
}
