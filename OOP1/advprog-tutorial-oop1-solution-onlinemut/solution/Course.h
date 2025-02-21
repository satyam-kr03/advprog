#ifndef COURSE_H
#define COURSE_H

#include <string>

enum class CourseType { Lecture, Seminar, Practical };

class Course {
private:
  std::string _id;
  CourseType _type;

public:
  Course(std::string, CourseType);

  std::string id() const;
};

#endif // COURSE_Η