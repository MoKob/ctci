#include <algorithm>
#include <iostream>
#include <vector>

void inplace_merge(std::vector<int> &a, std::vector<int> &b) {
  auto num_a = a.size(), num_b = b.size();
  auto merged_end = num_a + num_b;
  a.resize(merged_end);
  while (num_a > 0 && num_b > 0) {
    // next element is in b
    if (a[num_a - 1] < b[num_b - 1]) {
      a[--merged_end] = b[--num_b];
    } else {
      a[--merged_end] = a[--num_a];
    }
  }
  std::copy(b.begin(), b.begin() + num_b, a.begin());
}

int main() {
  std::vector<int> a{1, 3, 4, 5}, b{2, 4, 6};
  inplace_merge(a, b);
  std::cout << "Merged:";
  for (auto v : a)
    std::cout << " " << v;
  std::cout << std::endl;
}
