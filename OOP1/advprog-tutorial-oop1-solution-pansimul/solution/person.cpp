#include "person.h"

Person::Person(std::array<double, 2> initial_loc)
    : _curr_location(initial_loc), _id(Person::counter++) {}

Person::Person(const Person& other)
    : _id(Person::counter++) {
  // TODO: Implement the copy constructor.
  // Make sure to handle the const _id
  // member in the member initialization list.
  _curr_location = other._curr_location;
  _status = other._status;
}

Person& Person::operator=(const Person& other) {
  // TODO: Implement the copy assignment operator.
  _curr_location = other._curr_location;
  _status = other._status;
  return *this;
}

std::array<double, 2> Person::get_location() const {
  return _curr_location;
}

unsigned int Person::get_id() const {
  return _id;
}

void Person::advance() {
  _curr_location[0] += 0.1;
  _curr_location[1] -= 0.1;
}
