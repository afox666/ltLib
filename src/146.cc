#include <iostream>
#include <unordered_map>

class LRUCache {
public:
  struct Node {
    Node* pre;
    Node* next;
    int key;
    int value;
    Node() {}
    Node(int k, int v) :  key(k), value(v) {}
  };
  
public:
  LRUCache(int capacity) : capacity_(capacity) {
    head = new Node();
    tail = new Node();
    size_ = 0;
    head->next = tail;
    tail->pre = head;
  }

  ~LRUCache() {
    Node* node = head->next;
    while(size_ > 0) {
      Node* cur = node;
      node = node->next;
      delete cur;
      -- size_;
    }
    delete head;
    delete tail;
  }

  int get(int key) {
    if(hashmap_.find(key) != hashmap_.end()) {
      // update lrucache
      move2tail(hashmap_[key]);
      return hashmap_[key]->value;
    }
    return -1;
  }

  void set(int key, int value) {
    if(hashmap_.find(key) != hashmap_.end()) {
      // need update lrucache?
      move2tail(hashmap_[key]);
      hashmap_[key]->value = value;
      return ;
    }

    if(size_ >= capacity_) {
      // drop the head node
      Node* drop_node = head->next;
      drop_node->next->pre = head;
      head->next = drop_node->next;
      hashmap_.erase(drop_node->key);
      delete drop_node;
      -- size_;
    }

    // insert to tail
    Node* new_node = new Node(key, value);
    add2tail(new_node);
    
    ++ size_;
  }

private:
  void add2tail(Node* node) {
    node->next = tail;
    node->pre = tail->pre;

    tail->pre->next = node;
    tail->pre = node;
  }

  void move2tail(Node* node) {
    node->next->pre = node->pre;
    node->pre->next = node->next;

    add2tail(node);
  }
  
private:
  int capacity_{0};
  int size_{0};
  Node* head;
  Node* tail;
  std::unordered_map<int, Node*> hashmap_;
};

int main() {
  // maybe need to write some test code
  return 0;
}
