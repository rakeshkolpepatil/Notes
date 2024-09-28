#include "animal.h"

using namespace std;

Animal::Animal(const std::string_view description) 
  : m_description(description)
{
  cout << "Animal::Animal()  constructor called. " << endl;
}

Animal::~Animal(){
  cout << "Animal::~Animal() destructor called. " << endl;
}