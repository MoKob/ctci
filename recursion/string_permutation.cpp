#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

void pp_helper(std::string &str, std::size_t next) {
  if (next >= str.size()) {
    std::cout << str << std::endl;
  } else {
    for (auto pos = next; pos < str.size(); ++pos) {
      std::swap(str[pos], str[next]);
      pp_helper(str, next + 1);
      std::swap(str[pos], str[next]);
    }
  }
}

void print_permutations(std::string str) { pp_helper(str, 0); }

int main() {
  std::cout << "All permutations of \"Hello\"" << std::endl;
  print_permutations("Helo");
}
