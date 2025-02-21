#include <cassert>
#include <iostream>

// We would normally include our own program headers here to test.
// Well... Eigen already implemented everything for us, so we
// are only testing Eigen here...
#include <Eigen/Dense>

bool test_matrix_vector_product() {
  /*
   * Test implementation of operator* for Matrix-vector product.
   */
  bool tests_passed = true;

  Eigen::Matrix2d matrix;
  matrix << 1, 2, 3, 4;

  Eigen::Vector2d vec;
  vec << 1, 1;

  Eigen::Vector2d mat_vec;
  mat_vec << matrix * vec;

  Eigen::Vector2d reference;
  reference << 3, 7;

  double tol = 1e-8;
  for (auto i = 0; i < reference.size(); i++) {
    // floating point values are "equal" if their
    // difference is small
    if ((reference[i] - mat_vec[i]) > tol) {
      tests_passed = false;
    }
  }
  if (tests_passed) {
    std::cout << "Tests passed!\n";
  } else {
    std::cout << "Tests failed \n";
    std::cout << "Reference: ";
    std::cout << reference;
    std::cout << "Computed: ";
    std::cout << mat_vec;
  }
  return tests_passed;
}

int main() {
  if (test_matrix_vector_product()) return 0;
  return 1;
}