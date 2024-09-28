#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

using namespace std;

int main(){

  std::cout << " ------------ Engineer ---------------" << std::endl;
  Engineer e1;
  e1.build_something();
  //e1.m_full_name = "Sir Visvesvaraya";    // Bcz of 'private' inheritance, 'm_address' which was public in base class
                                          // will become 'private' in derived class and hence not accessible, Compiler error.
  cout << " Engineer e1: " << e1 << endl;

  // CivilEngineer class will not have access to any of the member of the base class
  std::cout << " ------------ CivilEngineer ---------------" << std::endl;
  CivilEngineer c1;
  cout << c1;
  return 0;
}