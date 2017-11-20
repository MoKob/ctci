#include <cstdint>
#include <iostream>

std::uint64_t nth_fibonacci(int n) {
  if (n == 0 || n == 1)
    return 1;

  std::uint64_t last = 1, cur = 1;
  --n;
  while (n--) {
    auto tmp = last;
    last = cur;
    cur = last + tmp;
  }
  return cur;
}

int main() {
  std::cout << "4th fibonacci number is: " << nth_fibonacci(4) << std::endl;
}
