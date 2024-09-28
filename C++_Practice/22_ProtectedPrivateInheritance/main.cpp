#include <iostream>
#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"

using namespace std;

int main(){
  // In public inheritance, 'protected' members of base class are accessible
  // inside members of derived classes but not outside the derived class.
  Person p1 ("Rakesh Patil", 23, "Shivaji M. Chawk, Pune");
  cout << "Person p1: " << p1 << endl;

  // In public inheritance, public members of base class are available 
  // in derived class.
  cout << "----------- Public Inheritance -----------" << endl;
  Player pl1("Basket Ball", 44);
  pl1.m_full_name = "Baba Blackship";
  // pl1.m_age = 28;                                    // Protected members are not accessible outside. Compiler error.
  // pl1.m_address = "St. Thomas street, chennai.";     // Compiler error

  pl1.set_address("St. Thomas street, chennai.");
  cout << "Player pl1: " << pl1 << endl;

  cout << "\n----------- Protected Inheritance -----------" << endl;
  Nurse n1;
  //n1.m_full_name = "Mrs Bregenza";      // Bcz of 'protected' inheritance, 'm_full_name' which was public in base class
                                           // has now become 'protected' in derived class and hence not accessible.
  cout << "Nurse n1: " << n1 << endl;

  cout << "----------- Private Inheritance -----------" << endl;
  Engineer e1;
  e1.build_something();
  //e1.m_full_name = "Sir Visvesvaraya";    // Bcz of 'private' inheritance, 'm_address' which was public in base class
                                          // will become 'private' in derived class and hence not accessible, Compiler error.
  cout << "Engineer e1: " << e1 << endl;

  return 0;
}