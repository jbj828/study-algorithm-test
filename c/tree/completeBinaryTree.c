#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
  int value;
  struct tNode *lChild;
  struct tNode *rChild;
} treeNode;

treeNode *levelOrderBinaryTreeUtil(int arr[], int size, int start) {
  treeNode *curr = (treeNode *)malloc(sizeof(treeNode));
  curr->value = arr[start];
  curr->lChild = curr->rChild = NULL;
  int left = 2 * start + 1;
  int right = 2 * start + 2;
  if (left < size) {
    curr->lChild = levelOrderBinaryTreeUtil(arr, size, left);
  }
  if (right < size) {
    curr->rChild = levelOrderBinaryTreeUtil(arr, size, right);
  }
  return curr;
}

treeNode *levelOrderBinaryTree(int arr[], int size) {
  return levelOrderBinaryTreeUtil(arr, size, 0);
}

void printPreOrder(treeNode *root) {
  if (root) {
    printf(" %d ", root->value);
    printPreOrder(root->lChild);
    printPreOrder(root->rChild);
  }
}

void printPostOrder(treeNode *root) {
  if (root) {
    printPostOrder(root->lChild);
    printPostOrder(root->rChild);
    printf(" %d ", root->value);
  }
}

void printInOrder(treeNode *root) {
  if (root) {
    printPostOrder(root->lChild);
    printf(" %d ", root->value);
    printPostOrder(root->rChild);
  }
}

int main() {
  int arr[] = {6, 4, 8, 2, 5, 7, 9, 1, 3};
  treeNode *t = levelOrderBinaryTree(arr, sizeof(arr) / sizeof(int));
  printPostOrder(t);
  return 0;
}