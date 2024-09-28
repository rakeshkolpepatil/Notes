#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

using namespace std; 

// In static binding, to call the methods of specific objects we need to create separate instances of the 
// draw() method for each object. 
void drawCircle(const Circle& circle){
  circle.draw();
}

void drawOval(const Oval& oval){
  oval.draw();
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

  base_ref = oval1;
  base_ref.draw();

  base_ref = circle1;
  base_ref.draw();

  cout << "\n ---------- Calling draw() method using custom functions ---------- " << endl;
  drawOval(oval1);
  drawCircle(circle1);

  // Also, you need to create a separate array for both base class and derived class.
  Shape   shape_array[] = { shape1, Shape("shape2"), Shape("shape3") }; 
  Circle  circle_array[] {circle1, Circle(10.3, "circle2"), Circle(20.3, "circle3") };
  Oval    oval_array[] {oval1, Oval(2.2, 3.3, "oval2"), Oval(2.2, 3.3, "oval3")};

  return 0;
}

