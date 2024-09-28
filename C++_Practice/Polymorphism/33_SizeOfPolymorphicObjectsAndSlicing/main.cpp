#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

using namespace std; 

int main(){

  // Remove the 'virtual' keyword from the classes and run this code.
  cout << "\n---------- Object Sizes with Static Polymorphism ---------- " << endl;
  cout << "sizeof(Shape)  : " << sizeof(Shape)   << " bytes. " << endl; // 32 bytes.
  cout << "sizeof(Oval)   : " << sizeof(Oval)    << " bytes. " << endl; // 48 bytes.
  cout << "sizeof(Circle) : " << sizeof(Circle)  << " bytes. " << endl; // 56 bytes.

  /*
  // Run following code when classes have 'virtual' keyword.
  // Comparing Object Sizes
  cout << " ---------- Object Sizes with Dynamic Polymorphism  ---------- " << endl;
  cout << "sizeof(Shape)  : " << sizeof(Shape)   << " bytes. " << endl; // 40 bytes. 
  cout << "sizeof(Oval)   : " << sizeof(Oval)    << " bytes. " << endl; // 56 bytes.
  cout << "sizeof(Circle) : " << sizeof(Circle)  << " bytes. " << endl; // 64 bytes.
  */

  // Slicing
  cout << "\n-------- Slicing -------- " << endl;
  Circle c3(3.4, "circle3");
  Shape  s3 = c3;              // Only 'Shape-class' part of the circle object will be assigned to the s3 object.
  s3.draw();                   // This will invoke draw() method of the "Shape" class.

  return 0;
}