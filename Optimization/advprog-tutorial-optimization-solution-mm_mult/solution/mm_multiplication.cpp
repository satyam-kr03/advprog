#include "Matrix.h"
#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <stdlib.h>

// Base version: row - column - k
// C[rows,columns] = A [rows,k] * B [k,columns]
void mm_mult_rck(std::size_t size, Matrix<double>& A, Matrix<double>& B, Matrix<double>& C) {
  for (auto row = 0; row < size; ++row) {
    for (auto col = 0; col < size; ++col) {
      for (auto k = 0; k < size; ++k) {
        C(row, col) += A(row, k) * B(k, col);
      }
    }
  }
}

// Solution: row - k - column
void mm_mult_rkc(std::size_t size, Matrix<double>& A, Matrix<double>& B, Matrix<double>& C) {
  for (auto row = 0; row < size; ++row) {
    for (auto k = 0; k < size; ++k) {
      for (auto col = 0; col < size; ++col) {
        C(row, col) += A(row, k) * B(k, col);
      }
    }
  }
}

// Solution: column - k - row
void mm_mult_ckr(std::size_t size, Matrix<double>& A, Matrix<double>& B, Matrix<double>& C) {
  for (auto col = 0; col < size; ++col) {
    for (auto k = 0; k < size; ++k) {
      for (auto row = 0; row < size; ++row) {
        C(row, col) += A(row, k) * B(k, col);
      }
    }
  }
}

// Solution: column - row - k
void mm_mult_crk(std::size_t size, Matrix<double>& A, Matrix<double>& B, Matrix<double>& C) {
  for (auto col = 0; col < size; ++col) {
    for (auto row = 0; row < size; ++row) {
      for (auto k = 0; k < size; ++k) {
        C(row, col) += A(row, k) * B(k, col);
      }
    }
  }
}

// Solution: k - row - column
void mm_mult_krc(std::size_t size, Matrix<double>& A, Matrix<double>& B, Matrix<double>& C) {
  for (auto col = 0; col < size; ++col) {
    for (auto row = 0; row < size; ++row) {
      for (auto k = 0; k < size; ++k) {
        C(row, col) += A(row, k) * B(k, col);
      }
    }
  }
}

// Solution: k - row - column
void mm_mult_kcr(std::size_t size, Matrix<double>& A, Matrix<double>& B, Matrix<double>& C) {
  for (auto k = 0; k < size; ++k) {
    for (auto col = 0; col < size; ++col) {
      for (auto row = 0; row < size; ++row) {
        C(row, col) += A(row, k) * B(k, col);
      }
    }
  }
}

// Just a short name for the type of our mm_mult functions
using mm_mult_func = std::function<void(std::size_t size, Matrix<double>& A, Matrix<double>& B, Matrix<double>& C)>;

// Here we time an mm_mult function for a given number of samples
void testFunction(mm_mult_func mm_mult, std::size_t size, std::size_t samples, Matrix<double>& A, Matrix<double>& B,
    Matrix<double>& C) {
  for (int sample = 0; sample < samples; ++sample) {
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    start = std::chrono::system_clock::now();

    mm_mult(size, A, B, C);

    end = std::chrono::system_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    const double total_flop = size * size * size * 2; // One * and one + per iteration
    const double flop_per_second = total_flop / elapsed_time.count();
    const double gflop_per_second = flop_per_second / 1e3;

    std::cout << "sample " << sample << " elapsed time: " << elapsed_time.count() << "ms"
              << " MFLOP/s: " << gflop_per_second << std::endl;
  }
}

void reset_matrix(std::size_t N, Matrix<double>& matrix) {
  std::memset(matrix.data(), 0, N * N * sizeof(double));
}

int main(int argc, char** argv) {
  const std::size_t samples = 4;

  // NOTE: if you run into "out of memory" problems, reduce this number.
  // If you have a lot of memory, feel free to increase this number.
  std::size_t N = 1024;

  // We are using here our own Matrix class for convenience
  Matrix<double> A(N, N), B(N, N), C(N, N);

  for (std::size_t size = 64; size <= N; size *= 2) {
    std::cout << " ================== " << size << " ================ " << std::endl;
    std::cout << "== loop order: row - column - k ==" << std::endl;
    // Reset all elements of C to zero before each new implementation
    reset_matrix(N, C);
    testFunction(mm_mult_rck, size, samples, A, B, C);

    std::cout << "== loop order: row - k - column ==" << std::endl;
    reset_matrix(N, C);
    testFunction(mm_mult_rkc, size, samples, A, B, C);

    std::cout << "== loop order: row - column - k ==" << std::endl;
    reset_matrix(N, C);
    testFunction(mm_mult_rck, size, samples, A, B, C);

    std::cout << "== loop order: column - k - row ==" << std::endl;
    reset_matrix(N, C);
    testFunction(mm_mult_ckr, size, samples, A, B, C);

    std::cout << "== loop order: column - row - k ==" << std::endl;
    reset_matrix(N, C);
    testFunction(mm_mult_crk, size, samples, A, B, C);

    std::cout << "== loop order: k - row - column ==" << std::endl;
    reset_matrix(N, C);
    testFunction(mm_mult_krc, size, samples, A, B, C);

    std::cout << "== loop order: k - column - row ==" << std::endl;
    reset_matrix(N, C);
    testFunction(mm_mult_kcr, size, samples, A, B, C);
  }

  return 0;
}
