#include "BSTree.h"

#include <stdlib.h>
#include <assert.h>

int main (int argc, char* argv[]) {
  Tree *t = newTree();
  insertItem(t, 5);
  insertItem(t, 2);
  insertItem(t, 8);
  insertItem(t, 7);
  insertItem(t, 1);
  insertItem(t, 5);
  insertItem(t, 10);
  return EXIT_SUCCESS;
} 

Tree* newNode(Item value) {
  Tree* new = malloc(sizeof(struct Tree));
  new->left = NULL;
  new->right = NULL;
  new->value = value;
  return new;
}

Tree* newTree(Item initialValue) {
  return newNode(initialValue);
}

void insertItem(Tree* t, Item item) {
  if (t == NULL) {
    return;
  }
  if (item == t->value) {
    // exit, cannot store duplicates
    return;
  } else if (item < t->value) {
    // left hand side
    if (t->left == NULL) {
      t->left = newNode(item);
      return;
    } else {
      insertItem(t->left, item);
      return;
    }
  } else {
    // right hand side
    if (t->right == NULL) {
      t->right = newNode(item);
      return;
    } else {
      insertItem(t->right, item);
      return;
    }
  }
}

int countInternal(Tree* t) {
  if (t == NULL) {
    return 0;
  }
  return 1 + countInternal(t->left) + countInternal(t->right);
}

int nodeDepthRecursive(Tree* t, Item key, unsigned int depth) {
  if (t == NULL) {
    return -1;
  } else if (t->value == key) {
    return depth;
  } else if (t->value < key) {
    // traverse left
    return nodeDepthRecursive(t->left, key, depth + 1);
  } else {
    // traverse right
    return nodeDepthRecursive(t->right, key, depth + 1);
  }
}

int nodeDepth(Tree *t, Item key) {
  if (t == NULL) {
    return -1;
  } else if (t->value == key) {
    // key is at global tree root
    return 0;
  } else if (t->value < key) {
    // traverse on left side
    return nodeDepthRecursive(t->left, key, 1);
  } else {
    // traverse on right side
    return nodeDepthRecursive(t->right, key, 1);
  }
}

int maxBranchLenRecursive(Tree* t, unsigned int depth) {
  if (t == NULL) {
    return depth - 1;
  }
  int maxDepthLeft = maxBranchLenRecursive(t->left, depth + 1);
  int maxDepthRight = maxBranchLenRecursive(t->right, depth + 1);
  return maxDepthLeft > maxDepthRight ? maxDepthLeft : maxDepthRight;
}

int maxBranchLen(Tree *t) {
  if (t == NULL) {
    return -1;
  } 
  int maxDepthLeft = maxBranchLenRecursive(t->left, 1);
  int maxDepthRight = maxBranchLenRecursive(t->right, 1);
  return maxDepthLeft > maxDepthRight ? maxDepthLeft + 1 : maxDepthRight + 1;
}
