#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <string_view>

using namespace std;

class Circle: public Shape {
  public:
    Circle() = default;
    ~Circle();
    Circle(double radius, const std::string_view description);
  
    virtual double area() const override{
      return 3.14 * m_radius * m_radius;
    }

    virtual double perimeter() const override {
      return 2 * 3.14 * m_radius;
    }

  private:
    double m_radius;
};
#endif