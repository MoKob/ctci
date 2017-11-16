#include <iostream>
#include <vector>

void four_way_rotate(int i, int j, std::vector<std::vector<int>> &data) {
  auto tmp = data[i][j];
  auto s = data.size() - 1;
  data[i][j] = data[j][s - i];
  data[j][s - i] = data[s - i][s - j];
  data[s - i][s - j] = data[s - j][i];
  data[s - j][i] = tmp;
}

void rotate(std::vector<std::vector<int>> &data) {
  for (int row = 0; 2 * row < data.size(); ++row) {
    for (int col = row; col + row + 1 < data.size(); ++col) {
      four_way_rotate(row, col, data);
    }
  }
}

int main() {
  std::vector<std::vector<int>> data;
  data.push_back({0, 1, 2, 3, 4});
  data.push_back({5, 6, 7, 8, 9});
  data.push_back({10, 11, 12, 13, 14});
  data.push_back({15, 16, 17, 18, 19});
  data.push_back({20, 21, 22, 23, 24});

  rotate(data);
  for (auto r : data) {
    for (auto c : r)
      std::cout << " " << c;
    std::cout << std::endl;
  }
}
