#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>
#include <iostream>

class Animal{
  public:
    Animal() = default;
    Animal(const std::string_view description);
    virtual ~Animal();

    virtual void breathe() const {
      std::cout << "Animal::breathe() called for " << m_description << std::endl;
    }

  protected:
    std::string_view m_description;
};

#endif