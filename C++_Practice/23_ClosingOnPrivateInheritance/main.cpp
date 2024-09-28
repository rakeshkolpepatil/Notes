#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

using namespace std;

int main(){
  // In public inheritance, 'protected' members of base class are accessible
  // inside members of derived classes but not outside the derived class.
  Person p1 ("Rakesh Patil", 23, "Shivaji M. Chawk, Pune");
  cout << "Person p1: " << p1 << endl;

  cout << "----------- Private Inheritance -----------" << endl;
  Engineer e1;
  e1.build_something();
  //e1.m_full_name = "Sir Visvesvaraya";    // Bcz of 'private' inheritance, 'm_address' which was public in base class
                                          // will become 'private' in derived class and hence not accessible, Compiler error.
  cout << "Engineer e1: " << e1 << endl;

  // CivilEngineer class will not have access to any of the member of the base class
  CivilEngineer c1;
  cout << c1;
  return 0;
}