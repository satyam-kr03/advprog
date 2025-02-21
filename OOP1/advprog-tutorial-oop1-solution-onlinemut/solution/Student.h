#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <string>
#include <vector>

class Student {
private:
  std::string _name;
  const std::string _registration_num;
  std::vector<Course> _courses;

  friend class StudentCard;

public:
  Student(std::string, std::string);

  void register_for(Course);

  void list_courses() const;
};

#endif // STUDENT_H
