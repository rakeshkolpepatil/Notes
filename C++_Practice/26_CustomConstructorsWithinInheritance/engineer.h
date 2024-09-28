#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"
#include <iostream>

class Engineer: public Person{
  public:
    friend std::ostream& operator<<(std::ostream& out, const Engineer& obj);

    Engineer();
    Engineer(std::string_view fullname_arg, int age_arg, std::string_view add_arg, int cont_count_arg);
    ~Engineer();
    void build_something();
    int get_contract_count() const {
      return contract_count; 
    }

  private:
    int contract_count{0};
};

#endif  // ENGINEER_H