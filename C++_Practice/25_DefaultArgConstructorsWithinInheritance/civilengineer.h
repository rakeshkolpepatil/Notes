#ifndef CIVILENGINEER_H
#define CIVILENGINEER_H

#include "engineer.h"

class CivilEngineer: public Engineer{
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& obj);
  public:
    CivilEngineer();
    ~CivilEngineer();

    void build_road();

    //using Person::do_something; // "do_something" has already become private in 'Engineer' class, so it is not possible to resurrect it here
                                  // Compiler Error
  private:
    std::string m_speciality {"Steel Design"};
};

#endif