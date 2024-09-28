#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

using namespace std; 

int main(){
  Circle circle1 (3.14, "circle1");
  Oval   oval1   (6.6, 4.5, "oval1");
  Circle circle2 (10, "circle2");
  Oval   oval2   (2.2, 4.4, "oval2");
  Circle circle3 (8, "circle3");
  Oval   oval3   (1.1, 9.9, "oval3");

  // When we try to store derived class objects inside the base class type array, all these objects will 
  // be stripped off or sliced and only base class related data will be stored inside the array as copies.
  cout << "\n-------------------- Override --------------------" << endl;
  Shape shape_array[] {circle1, circle2, circle3, oval1, oval2, oval3};
  for (Shape& i: shape_array){
    i.draw();
  }

  // Raw Pointers
  // Polymorphism through virtual functions was designed to work with base pointers that were managing the derived objects.
  cout << "\n------------------ Polymorphism using Raw Pointers - override -------------------" << endl;
  Shape* s_ptr[] = {&circle1, &circle2, &circle3, &oval1, &oval2, &oval3};
  for(Shape* ptr: s_ptr){
    std::cout << "\nInside array: sizeof(*ptr) : " << sizeof(ptr) << std::endl;
    ptr->draw();
  }

  return 0;
}