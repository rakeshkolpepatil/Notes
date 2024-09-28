#include <iostream>
#include "Cylinder.h"

using namespace std;

int main(){
  Cylinder c;
  cout << endl;
  cout << " The Cylinder details :- " << endl;
  cout << " Volume      = " << c.volume() << endl;

  // Accessing the private variables outside of the class will throw errors
  // cout << " The base_radius = " << c.base_radius << endl;
  // cout << " The height = " << c.height << endl;

  // However, we can make use of getter/setter functions to access private variables
  cout << endl;
  cout << " Using getter functions :- " << endl;
  cout << " The base_radius = " << c.get_base_radius() << endl;
  cout << " The height      = " << c.get_height() << endl;
  
  c.set_base_radius(11);
  c.set_height(22);
  cout << "\n After setter functions use :- " << endl;
  cout << " The base_radius = " << c.get_base_radius() << endl;
  cout << " The height      = " << c.get_height() << endl;
  cout << " Volume          = " << c.volume() << endl;

  return 0;
}