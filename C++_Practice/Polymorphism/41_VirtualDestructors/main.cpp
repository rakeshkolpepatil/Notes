#include <iostream>
#include "animal.h"
#include "feline.h"
#include "dog.h"

using namespace std;

int main(){

  // Case 1: 
  /*
  Destructor() calls order for Animal pointer - making destructors virtual
  Animal* animal_ptr = new Dog("Black fur", "dog1");
  delete animal_ptr;
  */

  // Case 2: Destructor() calls order for Dog object
  // Dog dog1;

  // Case 3: Destructor() calls order for Animal pointer - without making destructors virtual
  // Only one destructor of Animal class will be called, which is wrong.
  Animal* animal_ptr = new Dog("Black fur", "dog1");
  delete animal_ptr;
  return 0;
}