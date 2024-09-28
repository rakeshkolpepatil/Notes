#include <iostream>
// #include 
#include "derived.h"

int main(){

  // Base Pointer : Uses polymorphism
  // As we are using polymorphism, and using base pointer to access derived class object, method of the derived class
  // will be called but as default variables are resolved at compile time, default values of add() function of the 
  // base class will be used.
  cout << " ------- Base Pointer ---------" << endl;
  Base* base_ptr = new Derived;
  double result = base_ptr->add();
  cout << "Result (base pointer): " << result << endl;  //12

  // Base reference : uses polymorphism
  // Behavior of default arguments is same as that of 'Base Pointer'
  cout << "\n ------- Base Reference ---------" << endl;
  Derived derived1;
  Base& base_ref = derived1;
  result = base_ref.add();
  cout << "Result (base Reference): " << result << endl;  //12

  // Raw Objects - Uses static binding
  cout << "\n ------- Raw Base Object ---------" << endl;
  Base base3;
  result = base3.add();
  cout << "Result (Raw Base Object): " << result << endl;  //11

  // Direct Objects - Uses static binding 
  // As we are using Raw objects, no polymorphism is employed while calling the add() method
  // So, default arguments will be used.
  cout << "\n ------- Raw Derived Object ---------" << endl;
  Derived derived2;
  result = derived2.add();
  cout << "Result (Raw Derived Object): " << result << endl;  //22

  // Raw Objects - Slicing 
  // Because of slicing, the 'base4' variable will contain only 'base' class related part of the 
  // 'derived3' object. So, add() method will be used of the base class.
  cout << "\n ------- Slicing ---------" << endl;
  Derived derived3;
  Base base4 = derived3;
  result = base4.add();
  cout << "Result (Sliced Derived Object): " << result << endl;  //11



  return 0;
}

