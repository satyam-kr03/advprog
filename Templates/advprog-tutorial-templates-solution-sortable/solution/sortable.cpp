#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
concept Cute = requires(T m) { m.cuteness(); };

template <typename T>
concept Sortable = requires(T m, T n) { m.operator<(n); };

template <typename T>
  requires Cute<T> && Sortable<T>
void animal_sort(std::vector<T>& arr) {
  std::sort(arr.begin(), arr.end());
  std::cout << "{ ";
  for (const auto& elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << "}\n";
}

class Penguin {
private:
  int _height{};
  int _weight{};
  int _cuteness{};

public:
  Penguin() = default;
  Penguin(int height, int weight, int cuteness)
      : _height(height), _weight(weight), _cuteness(cuteness) {}

  int cuteness() const {
    return _cuteness;
  }

  bool operator<(const Penguin& from) {
    return _cuteness < from._cuteness;
  }

  friend std::ostream& operator<<(std::ostream& os, const Penguin& penguin) {
    std::cout << "{ " << penguin._cuteness << " }";
    return os;
  }
};

int main() {
  std::vector<Penguin> penguins;
  penguins.push_back(Penguin(10, 10, 5));
  penguins.push_back(Penguin(7, 13, 1));
  penguins.push_back(Penguin(9, 15, 3));

  animal_sort<Penguin>(penguins);
}