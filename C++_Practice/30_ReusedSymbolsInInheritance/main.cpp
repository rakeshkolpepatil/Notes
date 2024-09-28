#include <iostream>
#include "parent.h"
#include "child.h"

using namespace std; 

int main(){
  cout << "------ Parent ------ " << endl;
  Parent p1;
  p1.print_var();

  cout << "\n----- Child ------ " << endl;
    Child c1;
    cout << "Child print_var()  :- " << endl;
    c1.print_var();
    cout << "\nParent print_var() :- " << endl;
    c1.Parent::print_var();

    cout << "\nChild show_values() :- " << endl;
    c1.show_values();

  return 0;
}

