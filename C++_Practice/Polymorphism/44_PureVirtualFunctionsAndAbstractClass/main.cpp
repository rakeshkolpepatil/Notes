#include <iostream>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"

using namespace std; 

int main(){
  //Shape* shape_ptr = new Shape; // You can not create an object of an abstract class. Compiler Error

  const Shape* shape_rect = new Rectangle(10, 10, "Rectangle1");
  double rect_area = shape_rect->area();
  cout << " Dynamic typeid of shape_rect is = " << typeid(*shape_rect).name() << endl;
  cout << " The area of the rectangle shape is " << rect_area << endl;

  const Shape* shape_circle = new Circle(10, "Circle1");
  double rect_circle = shape_circle->area();
  cout << " Dynamic typeid of shape_circle is = " << typeid(*shape_circle).name() << endl;
  cout << " The area of the circle shape is " << rect_circle << endl;

  return 0;
}