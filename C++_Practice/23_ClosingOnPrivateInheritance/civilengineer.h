#ifndef CIVILENGINEER_H
#define CIVILENGINEER_H

#include "engineer.h"

class CivilEngineer: public Engineer{
    friend std::ostream& operator<<(std::ostream& out, const CivilEngineer& obj);
  public:
    CivilEngineer() = default;
    ~CivilEngineer();

    void build_road();

  private:
    std::string m_speciality {"Steel Design"};
};

#endif