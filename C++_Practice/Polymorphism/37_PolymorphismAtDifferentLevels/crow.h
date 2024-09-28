#ifndef CROW_H
#define CROW_H

#include "bird.h"

class Crow : public Bird{
  public:
    Crow() = default;
    Crow(const std::string_view wing_color, const std::string_view description);
    virtual ~Crow();

    virtual void cow() const {
      std::cout << "Crow::cow() called for crow: " << m_description << std::endl;
    }

    virtual void breathe() const {
      std::cout << "Crow::breathe()   called for crow: " << m_description << std::endl;
    }

    virtual void fly() const{
      std::cout << "Crow::fly()   called for bird " << m_description << std::endl;
    }
};

#endif // CROW_H