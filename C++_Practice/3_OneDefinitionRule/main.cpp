#include <iostream>
#include "person.h"

using namespace std;

double weight {33.6};
// double weight {33.6};          // redeclaration of a variable is not allowed.

double add(double x, double y);   // declaration of 'add' function

struct Point {         // Multiple defintions of a data type are allowed but in different translation units.
  int x{};               // 'Point' type is also defined in file 'otherfile.cpp'.
  int y{};
};

/*
// Multiple defintions of class 'Person' are not allowed.
class Person{
};
*/

int main(){
  /*
  // One definition rule
  */
  double result = add(10, 20);
  cout << "result: " << result << endl;

  Point p;
  cout << "p.x = " << p.x << ", p.y = " << p.y << endl;
  
  Person manager("John Trump", 67);
  manager.print_info();
}

double add(double x, double y) {  // definition of 'add' function
  return x + y;
}

/*
double add(double x, double y) {  // Multiple definitions of 'add' function are not allowed.
  return x + y;
}
*/
