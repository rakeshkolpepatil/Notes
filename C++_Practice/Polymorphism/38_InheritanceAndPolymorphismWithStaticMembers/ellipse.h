#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse: public Shape {
  public:
    Ellipse();
    Ellipse(const std::string_view description, double xRadius, double yRadius);
    ~Ellipse();

    virtual int getCount() const override { 
      return e_m_count; 
    }

    static int e_m_count;
  private:
    double m_x_radius;
    double m_y_radius;
};

#endif // ELLIPSE_H