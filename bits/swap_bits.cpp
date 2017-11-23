#include <bitset>
#include <cstdint>
#include <iostream>

template <typename int_type> struct SwapMask {
  const static constexpr int_type odd = 0;
  const static constexpr int_type even = 0;
};

template <> struct SwapMask<std::uint8_t> {
  const static constexpr std::uint8_t odd = 0xAA;
  const static constexpr std::uint8_t even = 0x55;
};

template <> struct SwapMask<std::uint16_t> {
  const static constexpr std::uint16_t odd = 0xAAAA;
  const static constexpr std::uint16_t even = 0x5555;
};

template <> struct SwapMask<std::uint32_t> {
  const static constexpr std::uint32_t odd = 0xAAAAAAAA;
  const static constexpr std::uint32_t even = 0x55555555;
};

template <> struct SwapMask<std::uint64_t> {
  const static constexpr std::uint64_t odd = 0xAAAAAAAAAAAAAAAA;
  const static constexpr std::uint64_t even = 0x5555555555555555;
};

template <typename int_type> int_type swap_bits(int_type const value) {
  return ((value & SwapMask<int_type>::even) << 1) |
         ((value & SwapMask<int_type>::odd) >> 1);
}

int main() {
  std::cout << "Swapping odd/even:\n";
  std::uint32_t bit_value = 10914881u;
  std::cout << std::bitset<32>(bit_value) << std::endl;
  std::cout << std::bitset<32>(swap_bits(bit_value)) << std::endl;
}

template <typename int_type> const int_type SwapMask<int_type>::odd;
template <typename int_type> const int_type SwapMask<int_type>::even;
