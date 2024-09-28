#ifndef CIRCLE_H
#define CIRCLE_H

#include "oval.h"
#include <string_view>

using namespace std;

class Circle: public Oval {
  public:
    Circle() = default;
    ~Circle();
    Circle(double radius, const std::string_view& description);

    virtual void draw() const override {
      cout << "Circle::draw() called. Drawing " << m_description << " with radius " 
            << m_radius << endl;
    }

    virtual void draw(int color_depth) const override{
      std::cout << "Circle::draw() method with color depth called. Drawing " << m_description << endl;
    }

    virtual void area() const override{
      std::cout << "Circle::area() method called. " << endl;
    }

  private:
    double m_radius;
};

#endif