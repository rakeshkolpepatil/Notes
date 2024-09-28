#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

using namespace std; 

int main(){
  Circle circle1 (3.14, "circle1");
  Oval   oval1   (6.6, 4.5, "oval1");

  circle1.draw();
  //circle1.draw(5);  // Inside 'Oval' class, which is a base class for 'Circle' class, draw(int color_depth) method is not defined as 
                      // an 'override' method, so it will not be available in 'Circle' class. - Compiler Error.

  // Since, 'override' keyword is attached to the 'draw(int color_depth)' method, it is available now in 'Circle' class
  circle1.draw(5);

  oval1.draw(); 
  oval1.draw(5); 

  Shape* shape1 = new Oval(22, 33, "oval2");  // Be
  //shape1->area();         // As the method 'area()' is defined in the 'Oval' class it is not available in the 'Shape' class.
                          // If you want to make use of the 'polymorphism' you need to define the method in the topmost base class.

  return 0;
}