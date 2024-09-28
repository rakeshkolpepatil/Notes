#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"
#include <iostream>

class Engineer: public Person{
  public:
    friend std::ostream& operator<<(std::ostream& out, const Engineer& obj);

    Engineer();
    ~Engineer();
    void build_something();
    int get_contract_count() const {
      return contract_count; 
    }

  private:
    int contract_count{0};
};

#endif  // ENGINEER_H