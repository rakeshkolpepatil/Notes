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

    virtual void fly() const{
      std::cout << "Pigeon::fly() called for bird " << m_description << std::endl;
    }
        
    virtual void stream_insert( std::ostream& out) const override {
      out << "Pigeon [ wing_color: " << m_wing_color << ", m_description: " << m_description << " ]" << std::endl;
    }

};

#endif // PIGEON_H