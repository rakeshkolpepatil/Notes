#include "Dog.h"
using namespace std;

Dog::Dog(const std::string_view fur_style, const std::string_view description)
  : Feline(fur_style, description)
{
  cout << "Dog::Dog()        constructor called. " << endl;
}

Dog::~Dog(){
  cout << "Dog::~Dog()       destructor called. " << endl;
}