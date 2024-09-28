#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>
#include <string_view>
#include "shape.h"

class Rectangle: public Shape{
  public:
    Rectangle() = default;
    Rectangle(double width, double height, std::string_view description);
    virtual ~Rectangle();

    virtual double area() const override { return m_width * m_height; }
    virtual double perimeter() const override { return 2*(m_width + m_height); }

  private:
    double m_width{0.0};
    double m_height{0.0};

};

#endif // RECTANGLE_H