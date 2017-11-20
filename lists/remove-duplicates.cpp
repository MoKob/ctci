#include <iostream>
#include <list>
#include <unordered_set>

template <typename L> void remove_duplicates(std::list<L> &lst) {
  std::unordered_set<L> seen;
  auto itr = lst.begin();
  while (itr != lst.end()) {
    if (seen.count(*itr)) {
      itr = lst.erase(itr);
    } else {
      seen.insert(*itr);
      itr++;
    }
  }
}

int main() {
  std::list<int> lst;

  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(1);
  lst.push_back(4);
  lst.push_back(4);
  lst.push_back(7);
  lst.push_back(2);
  lst.push_back(3);
  lst.push_back(7);

  std::cout << "[lst]";
  for (auto i : lst) {
    std::cout << " " << i;
  }
  std::cout << std::endl;

  remove_duplicates(lst);

  std::cout << "[lst]";
  for (auto i : lst) {
    std::cout << " " << i;
  }
  std::cout << std::endl;
}
