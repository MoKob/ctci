#include <iostream>
#include <string>
#include <unordered_map>

bool anagrams(std::string const &lhs, std::string const &rhs) {
  std::unordered_map<char, int> count;
  for (auto c : lhs)
    count[c]++;

  for (auto c : rhs)
    count[c]--;

  for (auto pair : count)
    if (pair.second != 0)
      return false;
  return true;
}

int main() {
  std::cout << "Anagrams: " << anagrams("aaa", "aa") << " and "
            << anagrams("abcde", "edcba") << std::endl;
}
