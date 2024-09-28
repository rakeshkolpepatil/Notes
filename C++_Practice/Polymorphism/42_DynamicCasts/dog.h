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

    virtual void run() const override {
      std::cout << "Dog " << m_description <<" is running." << std::endl;
    }

    void do_some_dog_thingy(){
      std::cout << "Do some dog thingy! speed : " << m_speed << std::endl;
    }
  
  private:
    int m_speed{};

};

#endif // DOG_H