#include <iostream>
#include <vector>

int coins(std::vector<int> &cache, int n) {
  if (n <= 1)
    return 1;

  if (cache[n] != -1)
    return cache[n];

  int sum = 0;
  sum += coins(cache, n - 1);
  if (n >= 5)
    sum += coins(cache, n - 5);
  if (n >= 10)
    sum += coins(cache, n - 10);
  if (n >= 25)
    sum += coins(cache, n - 25);
  cache[n] = sum;
  return sum;
}

int main() {
  std::vector<int> cache(101, -1);
  std::cout << "Can represent 100 in: " << coins(cache, 100)
            << " ways using 1, 5, 10, 25." << std::endl;
}
