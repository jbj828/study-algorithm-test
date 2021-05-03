#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
} ListNode;

int insertAtEnd(ListNode** ptrHead, int value) {
  ListNode* head = *ptrHead;
  ListNode* tempNode = (ListNode*)malloc(sizeof(ListNode));
  if (!tempNode) {
    return -1;
  }

  tempNode->value = value;
  tempNode->next = NULL;

  if (head == NULL) {
    tempNode->next = *ptrHead;
    *ptrHead = tempNode;
    return 1;
  }

  while (head->next != NULL) {
    head = head->next;
  }
  head->next = tempNode;
  return 1;
}