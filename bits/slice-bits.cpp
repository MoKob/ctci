#include <bitset>
#include <iostream>

using namespace std;

int slice_in(int N, int M, int i, int j) {
  // j = 6: 1000000 -> 111111 / i = 1 -> 10 -> 1
  int mask = ~(((1 << (j + 1)) - 1) ^ ((1 << i) - 1));

  M <<= i;

  // remove bits from N
  N = N & mask;
  // Slice in M
  N |= M;
  return N;
}

int main() {
  cout << std::bitset<32>(slice_in(1 << 15, 1 | (1 << 2) | (1 << 4), 2, 6))
       << endl;

  return 0;
}
