#ifndef PERSON_H
#define PERSON_H
#endif

#include "iostream"

using namespace std;

class Person {
  public:
    Person(const std::string& name_param, int age_param);

    void print_info(){
      cout << "Person: " << name << " age: " << age << endl;
    }

    // static variable declaration
    static int person_count;

  private:
    std::string name;
    int age;
};