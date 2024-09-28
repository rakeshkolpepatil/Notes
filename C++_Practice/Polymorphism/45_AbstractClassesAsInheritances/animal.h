#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>
#include <iostream>
#include "stream_insertable.h"

class Animal: public StreamInsertable{
  public:
    Animal() = default;
    Animal(const std::string_view description);
    virtual ~Animal();

    virtual void breathe() const {
      std::cout << "Animal::breathe() called for " << m_description << std::endl;
    }

    virtual void stream_insert( std::ostream& out) const override {
      out << "Animal [ m_description: " << m_description << " ]" << std::endl;
    }

  protected:
    std::string_view m_description;
};

#endif