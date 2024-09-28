#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder {
  public:
    // Default constructor
    // Cylinder() = default; // Compiler will generate default empty constructor to the 'Cylinder()'

    // empty constructor : empty constructor is created when user does not provide any constructor explicitly.
    // Cylinder(){}

    // Parameter less constructor 
    Cylinder();
    
    // Parameterized constructor
    Cylinder(double radius, double height);

    double volume();
    
    // getter functions
    double get_base_radius();
    double get_height();
    
    // setter functions
    void set_base_radius(double r);
    void set_height(double h);
    
  private:
    // member variables
    double base_radius {};
    double height {};
};

#endif
