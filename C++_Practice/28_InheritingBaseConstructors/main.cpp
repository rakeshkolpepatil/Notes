#include <iostream>
#include "person.h"
#include "engineer.h"

using namespace std;

int main(int argc, char** argv){

  // It will use 'Person::Person()' constructor to initialize the 'Engineer' object.
  cout << "\n ------------- Base constructor Inheritance ------------" << endl;
  Engineer eng1;
  cout << " Engineer eng1: " << eng1 << endl;

  // It will use 'Person::Person()' constructor to initialize the 'Engineer' object.
  // Give the arguments that you will give to create 'person' object.
  Engineer eng2("Rakesh Patil", 30, "Moscow");
  cout << " Engineer eng2: " << eng2 << endl;

  // You can even call the 'Engineer' class custom constructor 
  Engineer eng3("Jayant Patil", 60, "Glosgov", 1032);
  cout << " Engineer eng3: " << eng3 << endl;
  return 0;
}