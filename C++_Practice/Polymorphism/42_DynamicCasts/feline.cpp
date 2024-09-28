#include "feline.h"

Feline::Feline(const std::string_view fur_style, const std::string_view description) 
  : m_fur_style(fur_style), Animal(description) {

}

Feline::~Feline(){
  std::cout << " Feline::~Feline() destructor called! " << std::endl;
}