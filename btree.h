#ifndef btree_include
#define btree_include
typedef struct node{
  char* name;
  struct node *leftNode;
  struct node *rightNode;
} node;

void printTree(node* root);
struct node *insert(node* root, char *newNam);
struct node *removeNode(node* root, char *newName);
struct node *removeNull(node* root);
char *maxNode(node* root);
char *minNode(node* root);
struct node *fileToTree(node* root, char *fileName);
void treeToFile(node* root, char *fileName);
void writerHelper(node* root, FILE *file);
#endif
