#include "person.h"

Person::Person(std::string_view fname_arg, int age_arg, std::string_view add_arg)
  : m_full_name(fname_arg), m_age(age_arg), m_address(add_arg)
{
}

Person::~Person()
{
}

std::string Person::get_full_name() const{
  return m_full_name;
}

int Person::get_age() const{
  return m_age;
}

int Person::add(int a, int b) {
  return a + b;
}

int Person::add(int a, int b, int c) {
  return a + b;
}

void Person::do_something() const {
  std::cout << "hello" << std::endl;
}

std::string Person::get_address() const{
  return m_address;
}

void Person::set_address(std::string_view fn){
  m_address = fn;
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
  out << " Person : [ full_name: " << person.m_full_name << ", m_age: " << person.m_age <<
                      ", address: " << person.m_address << "]" << std::endl;
  return out;
}