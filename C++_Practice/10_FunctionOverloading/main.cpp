#include <iostream>

using namespace std;

int max(int a, int b) {
  cout << "(int, int) overload called " << endl;
  return a > b ? a : b;
}
/*
// The function overloading merely on return type is not allowed.
double max(int a, int b) {
  return a > b ? a : b;
}
*/

double max(double a, double b) {
  cout << "(double, double) overload called" << endl;
  return a > b ? a : b;
}

double max(int a, double b) {
  cout << "(int, double) overload called" << endl;
  return a > b ? a : b;
}

double max(double a, int b) {
  cout << "(double, int) overload called" << endl;
  return a > b ? a : b;
}

double max(double a, int b, int c) {
  cout << "(double, int, int) overload called" << endl;
  return a > b ? a : b;
}

std::string_view max(std::string_view a, std::string_view b) {
  cout << "(std::string_view, std::string_view) overload called" << endl;
  return (a > b) ? a : b;
}


int main(){
  int a{4};
  int b{8};
  double x{23.5};
  double y{9.99};


  max(a, b);
  max(x, y);
  max(a, x);
  max(x, a);
  max(x, a, b);
  max("Hello ", "world!");                                      // No function will be called bcz of ambiguity with type of parameters.
  max(std::string_view("Hello "), std::string_view("world!"));  // Though the strings like "Hello" and "world" get explicitly converted into std::string_view, this was not happening 
                                                                // automatically and the max(std::string_view, std::string_view) function was not getting called. So I am explicitly
                                                                // typecasting the strings. 

  return 0;
}

