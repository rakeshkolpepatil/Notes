#include "circle.h"

using namespace std;

Circle::Circle(double radius, const std::string_view& description)
  : m_radius(radius), Oval(radius, radius, description) 
{
}

Circle::~Circle(){
  
}