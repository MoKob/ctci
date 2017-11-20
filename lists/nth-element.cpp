#include <iostream>
#include <list>

template <typename list_iterator>
list_iterator nth_element(list_iterator begin, list_iterator end, int n) {
  auto runner = begin;
  for (int k = 0; k < n; ++k) {
    // there is not enough elements
    if (runner == end)
      return end;
    ++runner;
  }
  while (runner != end) {
    ++begin;
    ++runner;
  }
  return begin;
}

int main() {
  std::list<int> list;
  for (int i = 1; i < 11; ++i) {
    list.push_back(i);
  }

  std::cout << "6th to last element: "
            << *nth_element(list.begin(), list.end(), 6) << std::endl;
}
