#include "Dog.h"

Dog::Dog(const std::string_view fur_style, const std::string_view description)
  : Feline(fur_style, description), m_speed(30)
{

}

Dog::~Dog(){
  std::cout << " Dog::~Dog() destructor called! " << std::endl;
}