#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

using namespace std; 

// In dynamic binding, virtual methods of respective derived class objects can be called using the base class pointer.
void drawShape(const Shape* ptr){
  ptr->draw();
}

// In dynamic binding, virtual methods of respective derived class objects can be called using the base class reference.
void drawShape_ref(const Shape& ref){
  ref.draw();
}

int main(){

  cout << "\n ---------- Calling draw() method using objects ---------- " << endl;
  Shape shape1("Shape1");
  shape1.draw();

  Oval oval1(5.2, 3.4, "Oval1");
  oval1.draw();

  Circle circle1(4, "Circle1");
  circle1.draw();

  // Base Pointers
  cout << "\n ---------- Calling draw() method using Base Pointer ---------- " << endl;
  Shape* base_ptr;

  base_ptr = &shape1;
  base_ptr->draw();
  
  base_ptr = &oval1;
  base_ptr->draw();
  
  base_ptr = &circle1;
  base_ptr->draw();

  // Base References
  cout << "\n ---------- Calling draw() method using Base References ---------- " << endl;
  Shape& base_ref = shape1;
  base_ref.draw();

  Oval& oval_ref = oval1;        // Once defined the reference 'base_ref' can not be reassigned. So created new reference.
  oval_ref.draw();

  Circle& circle_ref = circle1;  // Once defined the reference 'base_ref' can not be reassigned. So created new reference.
  circle_ref.draw();

  cout << "\n ---------- Calling draw() method using custom function with pointer argument ---------- " << endl;
  drawShape(&shape1);
  drawShape(&oval1);
  drawShape(&circle1);

  cout << "\n ---------- Calling draw() method using custom function with reference argument ---------- " << endl;
  drawShape_ref(shape1);
  drawShape_ref(oval1);
  drawShape_ref(circle1);

  Shape* raw_ptr;
  raw_ptr = &oval1;
  // raw_ptr->get_x_rad();     // get_x_rad() is not a virtual method, so pointer of base class will not be able to access it. Compiler Error.

  // When you define virtual functions then you can create a single array to store all the objects of base class and derived class and call the
  // virtual methods using the base class pointer.
  cout << "\n ---------- Calling draw() method using array of pointers of base class ---------- " << endl;
  Shape*  shape_array[] = { &shape1, &oval1, &circle1 }; 
  for (auto i: shape_array){
    i->draw();
  }

  return 0;
}