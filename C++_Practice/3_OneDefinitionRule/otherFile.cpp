#include "person.h"
// double weight {33.6};

struct Point {
  int x;
  int y;
};

int Person::person_count = 0;

Person::Person(const std::string& name_param, int age_param)
    : name(name_param), age(age_param) {
    person_count++;
}
