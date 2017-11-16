#include <algorithm>
#include <iostream>

char *reverse(char *str) {
  char *begin = str;
  char *end = str;
  while (*end != '\0')
    ++end;

  while (begin + 1 < end) {
    --end;
    std::swap(*begin, *end);
    ++begin;
  }

  return str;
}

int main() {
  char data[] = {'a', 'b', 'c', 'd', 'e', '\0'};
  std::cout << "Reverse of: " << data << " is " << reverse(data) << std::endl;
}
