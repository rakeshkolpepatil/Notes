#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <string_view>
#include <string>
#include "animal.h"

using namespace std;

class Bird: public Animal{
  public:
    Bird() = default;
    Bird(const std::string_view wing_color, const std::string_view description);
    virtual ~Bird();

    virtual void fly() const {
      std::cout << "Bird::fly() called for bird " << m_description << std::endl;
    }

    virtual void breathe() const{
      std::cout << "Bird::breathe() called for bird " << m_description << std::endl;
    }

  private:
    std::string m_wing_color;
};

#endif // BIRD_H