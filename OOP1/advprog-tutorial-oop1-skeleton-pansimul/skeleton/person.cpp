#include "person.h"

// 1. TODO: Implement a constructor that takes a
// location array and creates a unique_id for the
// object.
//
// 2. TODO: Implement the copy constructor
//
// 3. TODO: Implement the copy assignment operator.
//
// You can find the signatures of these functions in
// the header file. :)

std::array<double, 2> Person::get_location() const {
  return curr_location;
}

unsigned Person::get_id() const {
  return _id;
}

void Person::advance() {
  // for now, do advance doesn't
  // do anything sensible
  curr_location[0] += 0.1;
  curr_location[1] -= 0.1;
}
