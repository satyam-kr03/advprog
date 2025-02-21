#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

Student::Student(std::string name, std::string id)
    : _name(name), _registration_num(id) {
  std::cout << "Hi! My name is " << _name << " and my registration number is " << _registration_num << "." << std::endl;
}

void Student::register_for(Course course) {
  _courses.push_back(course);
  std::cout << "I am so excited to be taking " << course.id() << " this semester! :-D" << std::endl;
}

void Student::list_courses() const {
  std::cout << _name << " is taking these courses this semester: ";
  for (const auto& course : _courses) {
    std::cout << course.id() << " ";
  }
  std::cout << std::endl;
}
