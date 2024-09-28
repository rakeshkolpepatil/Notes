#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"
#include <iostream>

class Engineer: private Person{
  public:
    friend std::ostream& operator<<(std::ostream& out, const Engineer& obj);

    Engineer() = default;
    ~Engineer();
    void build_something();
    int get_contract_count() const {
      return contract_count; 
    }

  // As 'Engineer' class is a 'private' inheritance of the 'Person' class, none of the members of 'Person' class will be available to
  // the class derived from 'Engineer' class. To make them available i.e. to resurrect these functions we use following syntax. 
  protected:
    using Person::get_full_name;
    using Person::get_age;
    using Person::get_address;
    using Person::add;          // Resurrecting the overloaded function will resurrect all its variants.
    //using Person::m_address;    // Resurrecting of private variables of base class is not supported. Compiler error.

  private:
    int contract_count{0};
};

#endif  // ENGINEER_H