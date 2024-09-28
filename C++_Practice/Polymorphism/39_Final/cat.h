#ifndef CAT_H
#define CAT_H

#include "feline.h"

// Since 'Cat' class is defined as final, it is not possible to derive a new class from it.

class Cat final: public Feline {
  public:
    Cat() = default;
    Cat(const std::string_view fur_style, const std::string_view description);
    virtual ~Cat();

    // Interesting Fact #2:
    // Useless virtual method. Cat is final class, so no one will be deriving from this class and have a chance to 
    // specialize the miaw() method.
    virtual void miaw() const{
      std::cout << "Cat::miaw() called for cat " << m_description << std::endl;
    }

    virtual void breathe() const override {
      std::cout << "Cat::breathe()    called for " << m_description << std::endl;
    }

    virtual void run() const {
      std::cout << "Cat " << m_description <<" is running." << std::endl;
    }

};

#endif // CAT_H