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

int searchList(ListNode *head, int value) {
  while (head) {
    if (head->value == value) {
      printf("Found %d", value);
      return 1;
    }
    head = head->next;
  }

  printf("Cannot Find %d", value);
  return 0;
}

void deleteFirstNode(ListNode **ptrHead) {
  ListNode *currNode = *ptrHead;
  ListNode *nextNode;

  if (currNode == NULL) {
    return;
  }

  nextNode = currNode->next;
  free(currNode);
  *ptrHead = nextNode;
}

void deleteNode(ListNode **ptrHead, int delValue) {
  ListNode *currNode = *ptrHead;
  ListNode *nextNode;
  if (currNode->value == delValue) {
    nextNode = currNode->next;
    *ptrHead = nextNode;
    free(currNode);
    return;
  }

  while (currNode->next->value != delValue) {
    currNode = currNode->next;
  }

  nextNode = currNode->next;
  currNode->next = nextNode->next;
  free(nextNode);
  return;
}


int main() {
  ListNode *head = NULL;
  sortedInsert(&head, 4);
  sortedInsert(&head, 3);
  sortedInsert(&head, 2);
  sortedInsert(&head, 5);
  printList(head);

  printf("\n");
  //   searchList(head, 6);

  printf("\n");
  //   deleteFirstNode(&head);

  deleteNode(&head, 5);
  printList(head);
}