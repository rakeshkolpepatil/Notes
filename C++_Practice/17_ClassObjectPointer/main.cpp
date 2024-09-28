#include <iostream>
#include "cylinder.h"

using namespace std;

int main(int argc, char** argv){

  // Stack variable
  Cylinder c1 (10, 20);
  cout << "\n Stack class variables " << endl;
  cout << " The volume of the stack variable Cylinder c1 = " << c1.volume() << endl;

  // Pointer to the stack variable
  Cylinder * p_c1 = &c1;
  cout << " The volume of the stack variable Cylinder c1 using pointer (*p_c1).volume() = " << p_c1->volume() << endl;
  cout << " The volume of the stack variable Cylinder c1 using pointer p_c1->volume()   = " << p_c1->volume() << endl;


  // Heap variable
  Cylinder* c2 = new Cylinder(10, 100);
  cout << "\n Heap class variables " << endl;
  cout << " The volume of the Heap  variable Cylinder c2 = (*c2).volume() = " << (*c2).volume() << endl;
  cout << " The volume of the Heap  variable Cylinder c2 = c2->volume()   = " << c2->volume() << endl;

  delete c2;    // release the memory pointed by c2
  c2 = nullptr; // store null value in pointer variable c2

  return 0;
}

