#ifndef DOG_H
#define DOG_H

#include "feline.h"

class Dog : public Feline{
  public:
    Dog() = default;
    Dog(const std::string_view fur_style, const std::string_view description);
    virtual ~Dog();

    virtual void bark() const {
      std::cout << " Dog::bark()   called : woof!" << std::endl;
    }

    virtual void breathe() const override {
      std::cout << "Dog::breathe()    called for " << m_description << std::endl;
    }

    // Because of 'final' keyword, the run() method can not be overrided in the derived class of the class 'Dog',
    // further, derived classes are forced to use the implementation in Dog class. 
    virtual void run() const override final{
      std::cout << "Dog::run() is called." << std::endl;
    }

};

#endif // DOG_H