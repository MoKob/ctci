#include <algorithm>
#include <iostream>
#include <string>

void replace_whitespace(std::string &str) {
  auto ws = std::count(str.begin(), str.end(), ' ');
  if (ws == 0)
    return;

  auto last = str.size();
  str.resize(str.size() + 2 * ws);
  auto last_expanded = str.size();
  while (last > 0 && ws) {
    --last_expanded;
    --last;
    if (str[last] == ' ') {
      str[last_expanded--] = '0';
      str[last_expanded--] = '2';
      str[last_expanded] = '%';
      --ws;
    } else {
      str[last_expanded] = str[last];
    }
  }
}

int main() {
  std::string uri = "abc def geh";
  std::cout << "Uri of " << uri << " is ";
  replace_whitespace(uri);
  std::cout << uri << std::endl;
}
