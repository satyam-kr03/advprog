#include "Vec_double.h"

Vec::Vec(std::size_t capacity, double initial_val)
    : _capacity(capacity), _size(capacity), _arr(new double[capacity]) {
  // set initial value
  std::fill(_arr, _arr + _size, initial_val);
}

std::size_t Vec::capacity() const {
  return _capacity;
}

std::size_t Vec::size() const {
  return _size;
}

void Vec::push(const double& value) {
  // TODO 2: if _size < _capacity, add value directly.
  // Otherwise: size == capacity means there's no space for
  // new elements and we need to allocate
  // a new array, copy over elements from the old one
  //  and then add the new value.
}

// TODO 3: Define operator [] for Vec that returns double& at "index"
double& Vec::operator[](std::size_t index) {
  return _arr[index];
}

// TODO 4: Allow ranged based for loops by defining
// begin and end methods.
// begin: returns a pointer to the first element
// end:   return a pointer to one past the last element
double* Vec::begin() {
  // Implementation here
}
double* Vec::end() {
  // Implementation here
}