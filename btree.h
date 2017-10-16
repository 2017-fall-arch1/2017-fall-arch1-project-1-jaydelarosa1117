#ifndef btree_include
#define btree_include
typedef struct node{
  char* name;
  struct node *leftNode;
  struct node *rightNode;
} node;

void *insert(node* root, char *newNam);
struct node *removeNode(node* root, char *newName);
char *maxNode(node* root);
char *minNode(node* root);
void fileToTree(node* root, char *fileName);
void treeToFile(node* root, char *fileName);
void writerHelper(node* root, FILE *file);
#endif
