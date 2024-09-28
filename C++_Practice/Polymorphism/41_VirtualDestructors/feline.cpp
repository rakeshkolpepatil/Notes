#include "feline.h"

using namespace std;

Feline::Feline(const std::string_view fur_style, const std::string_view description) 
  : m_fur_style(fur_style), Animal(description) 
{
  cout << "Feline::Feline()  constructor called. " << endl;
}

Feline::~Feline(){
  cout << "Feline::~Feline() destructor called. " << endl;
}