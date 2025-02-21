#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <cstdlib>

/* Matrix:
 * A wrapper class around raw dynamically allocated arrays to provide
 * more convenient syntax for accessing elements.
 */

template <typename T>
class Matrix {
  std::size_t _rows;
  std::size_t _cols;
  T* _arr;

public:
  Matrix(std::size_t rows, std::size_t cols)
      : _rows(rows), _cols(cols), _arr(new T[rows * cols]) {
    // Initialize to some random values
    for (auto i = 0; i < rows; i++) {
      for (auto j = 0; j < cols; j++) {
        _arr[i * cols + j] = static_cast<double>(rand() % 20);
      }
    }
  }

  Matrix() = delete;

  T& operator()(int i, int j) {
    return _arr[i * _cols + j];
  }

  const T& operator()(int i, int j) const {
    return _arr[i * _cols + j];
  }

  Matrix(const Matrix& from) = delete;
  Matrix& operator=(const Matrix& from) = delete;

  ~Matrix() {
    delete[] _arr;
  }

  T* data() {
    return _arr;
  }
};

#endif