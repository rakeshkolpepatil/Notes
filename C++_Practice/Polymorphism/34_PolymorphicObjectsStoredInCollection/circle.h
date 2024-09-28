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

    // void draw() const {
    virtual void draw() const {
      cout << "Circle::draw() called. Drawing " << m_description << " with radius " 
            << m_radius << endl;
    }
  
  private:
    double m_radius;
};

#endif