#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} ListNode;

int sortedInsert(ListNode **ptrHead, int value) {
  ListNode *head = *ptrHead;
  ListNode *tempNode = (ListNode *)malloc(sizeof(ListNode));
  if (!tempNode) {
    return -1;
  }

  tempNode->value = value;
  tempNode->next = NULL;

  if (head == NULL || head->value > value) {
    tempNode->next = *ptrHead;
    *ptrHead = tempNode;
    return 1;
  }

  while (head->next != NULL && head->next->value < value) {
    head = head->next;
  }

  tempNode->next = head->next;
  head->next = tempNode;

  return 1;
}

void printList(ListNode *head) {
  while (head) {
    printf("%d ", head->value);
    head = head->next;
  }
}

int main() {
  ListNode *head = NULL;
  sortedInsert(&head, 4);
  sortedInsert(&head, 3);
  sortedInsert(&head, 2);
  sortedInsert(&head, 5);
  printList(head);
}