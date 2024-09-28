#ifndef OVAL_H
#define OVAL_H

#include <iostream>
#include <string>
#include <string_view>
#include "shape.h"

class Oval: public Shape{
  public:
    Oval() = default;
    Oval(double x_radius, double y_radius, std::string_view description);
    ~Oval();

    // override: As we have used 'override' keyword, compiler will try to find matching function signature
    // in base class, and as it will not find it because of spelling mistake in 'DraW()', compiler will throw an error.
    virtual void draw() const override{
    // void draw() const {
      std::cout << "Oval::draw()   called. Drawing " << m_description << " with m_x_radius : " 
                << m_x_radius << " and m_y_radius : "<< m_y_radius << std::endl;
    }

    virtual void draw(int color_depth) const override{
    // void draw() const {
      std::cout << "Oval::draw()   method with color depth called. Drawing " << m_description << endl;
    }

    virtual void area() const {
      std::cout << "Oval::area() method called. " << endl;
    }

  protected:
    double get_x_rad() const { return m_x_radius; }
    double get_y_rad() const { return m_y_radius; }

  private:
    double m_x_radius{0.0};
    double m_y_radius{0.0};

};

#endif