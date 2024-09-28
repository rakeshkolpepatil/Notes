#include <iostream>
#include "civilengineer.h"

using namespace std;

int main(int argc, char** argv){

  std::cout << " ------------ CivilEngineer ---------------" << std::endl;
  CivilEngineer c1("John Martin", 59, "Texas", 100, "Road Construction");
  cout << endl;
  cout << " CivilEngineer c1: " << c1;
  cout << endl;

  return 0;
}