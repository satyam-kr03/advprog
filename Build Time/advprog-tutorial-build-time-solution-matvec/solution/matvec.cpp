#include <cassert>
#include <Eigen/Dense>
#include <iostream>

int main() {
  // Here we define a matrix of arbitrary (X for any size)
  // size which we initialize to size 3x3. The "d" means "double"
  // (see also "f" for float, "i" for int, etc)
  Eigen::MatrixXd matrix(3, 3);

  // We can give values to Eigen matrices using streams
  // (how cool is that?)
  matrix << 1, 0, 0, 0, 1, 0, 0, 0, 1;

  // ...and we can also print them as a stream
  std::cout << "Matrix: \n" << matrix << std::endl;

  // Eigen also gives us some matrix and vector types
  // of fixed size, for performance reasons.
  // Here vec_a is a vector of 3 doubles.
  Eigen::Vector3d vec_a;
  vec_a << 1, 2, 3;
  std::cout << "vec_a: \n" << vec_a << std::endl;

  Eigen::Vector3d vec_b;
  vec_b << 4, 5, 6;
  std::cout << "vec_b: \n" << vec_b << std::endl;

  // Casually adding two vectors
  auto vec_sum = vec_a + vec_b;
  std::cout << "vec_sum: \n" << vec_sum << std::endl;

  // Casually multiplying matrix * vector
  auto mat_vec = matrix * vec_a;
  std::cout << "mat_vec\n" << mat_vec << std::endl;
}