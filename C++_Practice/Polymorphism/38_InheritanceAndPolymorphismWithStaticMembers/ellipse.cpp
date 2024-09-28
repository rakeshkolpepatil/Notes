#include "ellipse.h"

int Ellipse::e_m_count = 0;

Ellipse::Ellipse(): Ellipse("NoDescription", 1.0, 1.0)
{

}

Ellipse::Ellipse(std::string_view description, double xRadius, double yRadius)
  : Shape(description), m_x_radius(xRadius), m_y_radius(yRadius)
{
  ++Ellipse::e_m_count;
}

Ellipse::~Ellipse(){
  --Ellipse::e_m_count;
}