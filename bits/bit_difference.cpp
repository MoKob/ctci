#include <cstdint>
#include <iostream>

template <typename int_type>
std::uint32_t find_bit_difference(int_type const lhs, int_type const rhs) {
  std::uint32_t sum = 0;
  for (auto diff = lhs ^ rhs; diff > 0; diff >>= 1) {
    sum += diff & 1;
  }

  return sum;
}

int main() {
  std::cout << "Difference between 31 and 14 is: "
            << find_bit_difference(31, 14) << std::endl;
}
