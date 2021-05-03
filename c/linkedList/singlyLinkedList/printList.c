#include <stdio.h>
#include <stdlib.h>

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

void printList(ListNode *head) {
  while (head) {
    printf("%d ", head->value);
    head = head->next;
  }
}

int main() {
  ListNode *head = NULL;
  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);
  printList(head);
}

/*
     이중 포인터, 포인터 모두 그냥 변수다. 이 개념을 기억해두는게 중요하다. 모두
   변수기 때문에 거기에 주소가 값에 저장되어있는지, 혹은 변수의 주소에
   저장되어있는 주소가 가지고 있는 값을 원하는지에 따라 포인터의 갯수가 달라질
   뿐이다. 포인터는 변수에 주소가 담겨있는 것. 이중 포인터는 변수의 값이 주소일
   경우 변수 자체의 주소를 전달해서 변수의 값이 포함하고 있는 주소의 값을 가져올
   때 사용된다.
*/