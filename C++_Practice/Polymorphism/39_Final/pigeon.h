#ifndef PIGEON_H
#define PIGEON_H

#include "bird.h"

class Pigeon: public Bird {
  public:
    Pigeon()= default;
    Pigeon(const std::string_view wing_color, const std::string_view description);
    virtual ~Pigeon();

    virtual void breathe() const{
      std::cout << "Pigeon::breathe() called for bird " << m_description << std::endl;
    }

    // This is contradictory: virtual and final have counter acting effects. // Final wins here.
    virtual void fly() const final{
      std::cout << "Pigeon::fly() called for bird " << m_description << std::endl;
    }
};

#endif // PIGEON_H