#ifndef CYLINDER_H
#define CYLINDER_H

class Cylinder{
  public:
    Cylinder() = default;
    Cylinder(double r, double h);
    double volume();
    
    // getter functions
    double getRadius();
    double getHeight();

    // setter functions
    void setRadius(double arg_radius);
    void setHeight(double arg_height);

  private:
    double radius;
    double height;
};

#endif