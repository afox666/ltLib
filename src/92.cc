#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* Init(vector<int> &vals) {
  if(vals.empty()) return nullptr;
  ListNode *node = new ListNode(vals[0]);
  ListNode *head = node;
  for(int i = 1; i < vals.size(); ++ i) {
    ListNode *next = new ListNode(vals[i]);
    node->next = next;
    node = next;
  }
  node->next = nullptr;
  return head;
}

void Print(ListNode *head) {
  ListNode *node = head;
  while(node != nullptr) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

ListNode* reverse(ListNode *head) {
  if(head == nullptr) {
    return nullptr;
  }
  ListNode* cur = head;
  ListNode* next = head->next;
  cur->next = nullptr;
  
  while (next != nullptr) {
    ListNode *pre = cur;
    cur = next;
    next = next->next;
    cur->next = pre;
  }
  return cur;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if(head == nullptr) {
    return nullptr;
  }
  ListNode* dummy = new ListNode();
  dummy->next = head;
  ListNode* left_node = dummy;
  for(int i = 0; i < left - 1; ++ i) {
    left_node = left_node->next;
  }

  ListNode* start = left_node->next;

  ListNode* end = dummy;
  for(int i = 0; i < right; ++ i) {
    end = end->next;
  }

  ListNode* right_node = end->next;

  end->next = nullptr;
  ListNode* reversed = reverse(start);
  Print(reversed);
  left_node->next = reversed;
  start->next = right_node;
  return dummy->next;
}

int main() {
  std::vector<int> values = {1, 2, 3, 4, 5};
  ListNode *head = Init(values);
  //  Print(head);
  //  Print(reverse(head));
  Print(reverseBetween(head, 2, 5));
  return 0;
}
