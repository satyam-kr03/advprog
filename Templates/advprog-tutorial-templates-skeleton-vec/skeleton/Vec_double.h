#ifndef __VEC_DOUBLE_H_
#define ___VEC_DOUBLE_H_
#include <algorithm>
#include <cstddef>

class Vec {
private:
  std::size_t _capacity{};
  std::size_t _size{};
  double* _arr = nullptr;

public:
  Vec() = default;

  Vec(std::size_t capacity, double initial_val);

  ~Vec() {
    delete[] _arr;
  }

  std::size_t capacity() const;

  std::size_t size() const;

  void push(const double& value);

  double& operator[](std::size_t index);

  double* begin();
  double* end();
};

#endif
