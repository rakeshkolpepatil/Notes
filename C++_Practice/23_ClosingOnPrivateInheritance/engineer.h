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

  private:
    int contract_count{0};
};

#endif  // ENGINEER_H