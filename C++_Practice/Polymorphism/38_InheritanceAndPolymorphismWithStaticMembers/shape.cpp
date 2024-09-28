#include "shape.h"

int Shape::m_count = 0;

Shape::Shape()
  : m_description("NoDescription")
{
  
}

Shape::Shape(const std::string_view description)
  : m_description(description)
{
  std::cout << "Shape constructor called. " << m_description << std::endl; 
  ++Shape::m_count;
}

Shape::~Shape()
{
  --Shape::m_count;
}