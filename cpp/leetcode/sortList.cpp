#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // T.C: O(nlogn)
  // S.C: O(n)
  //   ListNode* sortList2(ListNode* head) {
  //     // 1. vector에 값을 쭉 넣는다.
  //     vector<int> list;
  //     ListNode* curr = head;
  //     while (curr != nullptr) {
  //       list.push_back(curr->val);
  //       curr = curr->next;
  //     }

  //     // 2. 벡터를 정렬시킨다
  //     sort(list.begin(), list.end());

  //     // 3. 벡터를 돌면서 ListNode에 넣는다.
  //     curr = head;
  //     for (int i = 0; i < list.size(); ++i) {
  //       curr->val = list.at(i);
  //       curr = curr->next;
  //     }

  //     return head;
  //   }

  ListNode* findMid(ListNode* head) {
    // DIVIDE
    // 1. find the middle of the linked list by using fast&slow pointer strategy
    ListNode *fast = head, *slow = nullptr;

    while (fast && fast->next) {
      //   slow = slow->next;
      slow = (slow == nullptr) ? head : slow->next;
      fast = fast->next->next;
    }

    // now slow pointer is on the middle of the list
    ListNode* mid = slow->next;

    // cut the next pointer from the firstList to secondList
    slow->next = nullptr;

    return mid;
  }

  ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode dummyHead(0);
    ListNode* ptr = &dummyHead;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        ptr->next = list1;
        list1 = list1->next;
      } else {
        ptr->next = list2;
        list2 = list2->next;
      }
      ptr = ptr->next;
    }
    if (list1)
      ptr->next = list1;
    else
      ptr->next = list2;

    return dummyHead.next;
  }

  // T.C: O(nlogn)
  // S.C: O(1)
  // using TopDown-MergeSort
  ListNode* sortList(ListNode* head) {
    // base case
    if (!head || !head->next) {
      return head;
    }

    // DIVIDE
    ListNode* mid = findMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    // CONQUER
    return merge(left, right);
  }
};