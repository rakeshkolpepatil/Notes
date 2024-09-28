#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

using namespace std;

int main(){

  std::cout << " ------------ Person ---------------" << std::endl;
  Person p1("Tom", 33, "New York");
  cout << " Person p1: " << p1 << std::endl;

  std::cout << " ------------ Engineer ---------------" << std::endl;
  Engineer e1("Ratan Tata", 88, "Mumbai", 44);
  cout << " Engineer e1: " << e1 << endl;

  std::cout << " ------------ CivilEngineer ---------------" << std::endl;
  CivilEngineer c1("John Martin", 59, "Texas", 100, "Road Construction");
  cout << " CivilEngineer c1: " << c1;
  return 0;
}