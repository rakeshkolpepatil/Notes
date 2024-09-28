#include <iostream>
#include <memory>   // For smart pointers.   
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
  cout << "\n-------------------- Storing derived class objects in array in raw format --------------------" << endl;
  Shape shape_array[] {circle1, circle2, circle3, oval1, oval2, oval3};
  for (Shape& i: shape_array){
    i.draw();
  }

  // What if we store references ? :- Array of reference objects can not be created - Compiler error.
  // Shape& shape_ref[] {circle1, circle2, circle3, oval1, oval2, oval3};   

  // Raw Pointers
  // Polymorphism through virtual functions was designed to work with base pointers that were managing the derived objects.
  cout << "\n------------------ Polymorphism using Raw Pointers -------------------" << endl;
  Shape* s_ptr[] = {&circle1, &circle2, &circle3, &oval1, &oval2, &oval3};
  for(Shape* ptr: s_ptr){
    std::cout << "\nInside array: sizeof(*ptr) : " << sizeof(ptr) << std::endl;
    ptr->draw();
  }

  // Smart Pointers - shared smart pointers
  cout << "\n------------------ Polymorphism using Smart Pointers -------------------" << endl;
  std::shared_ptr<Shape> sha_ptr_arr [] = { std::make_shared<Circle>(20, "circle20"), std::make_shared<Circle>(30, "circle30"),
                                            std::make_shared<Oval>(10, 20, "oval12"), std::make_shared<Oval>(20, 30, "oval23")};
  for( auto &s: sha_ptr_arr ){
    s->draw();
  }

  return 0;
}