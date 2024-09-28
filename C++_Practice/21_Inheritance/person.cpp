#include "Person.h"

Person::Person(){}

Person::Person(std::string_view fname_arg, std::string_view lname_arg, int age_arg)
  : first_name(fname_arg), last_name(lname_arg), age(age_arg)
{
}

std::string Person::get_first_name() const{
  return first_name;
}

std::string Person::get_last_name() const{
  return last_name;
}

void Person::set_first_name(std::string_view fn){
  first_name = fn;
}
void Person::set_last_name(std::string_view ln){
  last_name = ln;
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
  out << " Person : [ first_name: " << person.first_name << 
                      ", last_name: " << person.last_name << "]" << std::endl;
  return out;
}