#ifndef btree_include
#define btree_include
typedef struct node{
  int item;
  struct node *leftNode;
  struct node *rightNode;
} node;

void *insert(node* root, int num);
void *removeNode(node* root, int num);
#endif
