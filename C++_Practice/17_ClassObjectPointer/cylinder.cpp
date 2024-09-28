#include "cylinder.h"
#include "constants.h"

Cylinder::Cylinder(double r, double h){
  radius = r;
  height = h;
}

double Cylinder::volume(){
  return PI * radius * radius * height;
}

// getter functions
double Cylinder::getRadius(){
  return radius;
}

double Cylinder::getHeight(){
  return height;
}

// setter functions
void Cylinder::setRadius(double arg_radius){
  radius = arg_radius;
}

void Cylinder::setHeight(double arg_height){
  height = arg_height;
}
