#include <iostream>
#include <stack>

template <typename value_type> class StackQueue {
public:
  void push(value_type value) { in_buffer.push(value); }

  value_type pop() {
    // possibly transfer input buffer to the output buffer
    if (out_buffer.empty()) {
      while (!in_buffer.empty()) {
        out_buffer.push(in_buffer.top());
        in_buffer.pop();
      }
    }
    auto top = out_buffer.top();
    out_buffer.pop();
    return top;
  }

  bool empty() { return in_buffer.empty() && out_buffer.empty(); }

private:
  std::stack<value_type> in_buffer, out_buffer;
};

int main() {
  StackQueue<int> que;
  que.push(1);
  que.push(2);
  que.push(3);
  std::cout << "Queue: " << que.pop();
  que.push(4);
  que.push(5);
  std::cout << " " << que.pop();
  std::cout << " " << que.pop();
  que.push(6);
  std::cout << " " << que.pop();
  std::cout << " " << que.pop();
  std::cout << " " << que.pop();
  std::cout << std::endl;
}
