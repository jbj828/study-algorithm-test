#include <stdio.h>
#include <stdlib.h>

// Insert Node in singly linked list
typedef struct node {
  int value;
  struct node *next;
} ListNode;

int insertNode(ListNode **ptrHead, int value) {
  ListNode *tempNode = (ListNode *)malloc(sizeof(ListNode));
  if (!tempNode) {
    return -1;
  }

  tempNode->value = value;
  tempNode->next = *ptrHead;
  *ptrHead = tempNode;
  return 1;
}
