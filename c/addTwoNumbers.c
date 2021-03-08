#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  struct ListNode *res = NULL, *start = NULL;
  int x, y, c = 0;

  if (!l1 && !l2) {
    return NULL;
  } else if (!l1) {
    return l2;
  } else if (!l2) {
    return l1;
  }

  while (l1 || l2 || c) {
    x = l1 ? l1->val : 0;
    y = l2 ? l2->val : 0;
    if (!res) {
      res = malloc(sizeof(struct ListNode));
      start = res;
    } else {
      res->next = malloc(sizeof(struct ListNode));
      res = res->next;
    }
    res->next = NULL;
    res->val = (x + y + c) % 10;
    c = (x + y + c) / 10;
    l1 = l1 ? l1->next : NULL;
    l2 = l2 ? l2->next : NULL;
  }
  return start;
}