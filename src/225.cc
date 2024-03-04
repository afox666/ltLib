#include <iostream>
#include <queue>

// Utilize a single queue to simulate a stack
class MyStack {
public:
  MyStack() {

  }

  void push(int x) {
    q_.push(x);
    top_value_ = x;
  }

  int pop() {
    int size = q_.size();
    for(int i = 0; i < size - 1; ++i) {
      int value = q_.front();
      q_.pop();
      q_.push(value);
    }
    int res = top_value_;
    top_value_ = q_.back();
    q_.pop();
    return res;
  }

  int top() {
    return top_value_;
  }

  bool empty() {
    return q_.size() == 0;
  }

  std::queue<int> q_;
  int top_value_;
};


int main() {
  MyStack *obj = new MyStack();
  obj->push(1);
  obj->push(2);
  int param_2 = obj->top();
  int param_3 = obj->pop();
  bool param_4 = obj->empty();
  std::cout << param_2 << std::endl;
  std::cout << param_3 << std::endl;
  std::cout << param_4 << std::endl;
  return 0;
}
