#include <iostream>
#include <iterator>
#include <string>

template <typename forward_iterator>
forward_iterator unique(forward_iterator begin, forward_iterator end) {
  if (begin == end)
    return end;

  auto last = begin;
  std::advance(begin, 1);

  while (begin != end) {
    if (*begin != *last) {
      std::advance(last, 1);
      if (begin != last)
        std::swap(*begin, *last);
    }
    std::advance(begin, 1);
  }
  std::advance(last, 1);
  return last;
}

template <typename forward_iterator>
forward_iterator unique_k(forward_iterator begin, forward_iterator end,
                          int const k) {
  if (begin == end)
    return end;

  auto last = begin;
  std::advance(begin, 1);

  auto count = 1;
  while (begin != end) {
    if (*begin == *last)
      ++count;
    else
      count = 1;
    if (count <= k) {
      std::advance(last, 1);
      if (begin != last)
        std::swap(*begin, *last);
    }
    std::advance(begin, 1);
  }
  std::advance(last, 1);
  return last;
}

int main() {
  std::string str("abcdeeffghhijjjkl");
  std::cout << "Unique of: " << str;
  auto itr = unique(str.begin(), str.end());
  str.erase(itr, str.end());
  std::cout << " is " << str << std::endl;
  std::string str2("abcdeeffghhijjjkl");
  std::cout << "Unique 2 of: " << str2;
  auto itr2 = unique_k(str2.begin(), str2.end(), 2);
  str2.erase(itr2, str2.end());
  std::cout << " is " << str2 << std::endl;
}
