#ifndef CIVILENGINEER_H
#define CIVILENGINEER_H

#include "engineer.h"

class CivilEngineer: public Engineer{
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& obj);
  public:
    CivilEngineer();
    CivilEngineer(std::string_view fullname_arg, int age_arg, std::string_view add_arg, int cont_count_arg,
                  std::string_view spec_arg);

    CivilEngineer(const CivilEngineer& source);

    ~CivilEngineer();

    void build_road();

    //using Person::do_something; // "do_something" has already become private in 'Engineer' class, so it is not possible to resurrect it here
                                  // Compiler Error
  private:
    std::string m_speciality {"Steel Design"};
};

#endif