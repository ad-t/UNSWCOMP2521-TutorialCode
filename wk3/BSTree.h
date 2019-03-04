#define TRUE 1
#define FALSE 0

/*
typedef struct BSTNode *Link;
typedef struct BSTNode {
  int  value;
  Link left, right;
} BSTNode;
*/

typedef struct Tree* SubTree;
typedef struct Tree {
  int value;
  SubTree left, right;
} Tree;

typedef int Item;

Tree* newTree();
void insertItem(Tree* t, Item item);
int countInternal(Tree* t);
int nodeDepth(Tree* t, Item key);
int maxBranchLen(Tree* t);
