#include <iostream>
#include <string>

void print_helper(std::string &cur, int open, int close) {
  if (open == 0 && close == 0) {
    std::cout << cur << std::endl;
  } else {
    if (open) {
      cur.push_back('(');
      print_helper(cur, open - 1, close);
      cur.pop_back();
    }
    if (close && open < close) {
      cur.push_back(')');
      print_helper(cur, open, close - 1);
      cur.pop_back();
    }
  }
}

int main() {
  std::cout << "All braces of size 3:\n";
  std::string tmp;
  print_helper(tmp, 3, 3);
}
