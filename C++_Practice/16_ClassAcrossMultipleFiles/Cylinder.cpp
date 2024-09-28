#include "Cylinder.h"

// Parameter less constructor 
Cylinder::Cylinder(){
  base_radius = 2.0;
  height = 2.0;
}

Cylinder::Cylinder(double radius, double height){
  base_radius = radius;
  height = height;
}

double Cylinder::volume(){
  return PI * base_radius * base_radius * height;
}

// getter functions
double Cylinder::get_base_radius(){
  return base_radius;
}

double Cylinder::get_height(){
  return height;
}

// setter functions
void Cylinder::set_base_radius(double r){
  base_radius = r;
}

void Cylinder::set_height(double h){
  height = h;
}


