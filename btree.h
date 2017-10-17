#ifndef btree_include
#define btree_include
//new struct that is used to create a node type that can point to other nodes and contains a string
typedef struct node{
  char* name;
  struct node *leftNode;
  struct node *rightNode;
} node;
//header for printing tree
void printTree(node* root);
//header for inserting to tree
struct node *insert(node* root, char *newNam);
//header to remove given element from tree
struct node *removeNode(node* root, char *newName);
//header for returning the rightmost element
char *maxNode(node* root);
//header for returning the leftmost element
char *minNode(node* root);
//header to read file and turn into binary tree
struct node *fileToTree(node* root, char *fileName);
//writes contents from the tree onto a file depth first
void treeToFile(node* root, char *fileName);
//helper method for writing
void writerHelper(node* root, FILE *file);
#endif
