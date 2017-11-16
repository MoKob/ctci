#include <iostream>
#include <string>
#include <unordered_set>

bool hasUniqueChars(std::string const &str) {
  std::unordered_set<char> contained;
  for (auto c : str) {
    if (contained.count(c))
      return false;
    contained.insert(c);
  }
  // no repeated char found
  return true;
}

int main() {
  std::cout << "Checks: " << hasUniqueChars("abcdefgh") << " "
            << hasUniqueChars("hallo") << std::endl;
}
