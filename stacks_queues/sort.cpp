#include <iostream>
#include <stack>

template <typename value_type> void sort_stack(std::stack<value_type> &stk) {
  // an empty stack is sorted
  if (stk.empty())
    return;

  auto value = stk.top();
  stk.pop();
  sort_stack(stk);

  if (stk.empty() || !(stk.top() < value)) {
    stk.push(value);
  } else {
    auto tmp = stk.top();
    stk.pop();
    stk.push(value);
    sort_stack(stk);
    stk.push(tmp);
  }
}

int main() {
  std::stack<int> stk;
  for (int i = 0; i < 10; ++i)
    stk.push(rand() % 20);

  sort_stack(stk);

  std::cout << "Sorted:";
  while (!stk.empty()) {
    std::cout << " " << stk.top();
    stk.pop();
  }
  std::cout << std::endl;
}
