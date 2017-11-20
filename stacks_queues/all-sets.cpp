#include <cstddef>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> all_subsets(std::vector<int> const &set) {
  std::vector<std::vector<int>> result;
  // creating the empty set
  result.push_back(std::vector<int>());
  for (auto val : set) {
    for (std::size_t cur = 0, size = result.size(); cur < size; ++cur) {
      result.push_back(result[cur]);
      result.back().push_back(val);
    }
  }
  return result;
}

int main() {
  std::vector<int> data{1, 2, 3};
  auto sets = all_subsets(data);
  for (auto set : sets) {
    std::cout << "{";
    for (auto val : set)
      std::cout << " " << val;
    std::cout << " }" << std::endl;
  }
}
