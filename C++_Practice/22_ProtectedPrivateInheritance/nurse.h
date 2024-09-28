#ifndef NURSE_H
#define NURSE_H

#include <iostream>
#include "person.h"

class Nurse: protected Person{
    friend std::ostream& operator<<(std::ostream& out, const Nurse& n);
  public:
    Nurse() = default;
    ~Nurse();
    void treat_unwell_person();

  private:
    int m_practice_certificate_id{0};
};

#endif