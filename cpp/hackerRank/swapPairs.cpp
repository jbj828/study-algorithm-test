/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr->next != nullptr) {
      if (prev == nullptr) {
        head = curr->next;
      } else {
        prev->next = curr->next;
      }

      ListNode* after = curr->next;
      curr->next = curr->next->next;
      after->next = curr;

      if (curr->next == nullptr) {
        break;
      }
      prev = curr;
      curr = curr->next;
    }

    return head;
  }
};