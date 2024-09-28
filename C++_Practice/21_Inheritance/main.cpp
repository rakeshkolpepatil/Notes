#include <iostream>
#include "player.h"
// #include "person.h"

using namespace std;

int main(){
  // In public inheritance, protected members of base class are accessible
  // in derived classes
  Player p1 {"Cricket", 23};
  cout << "Player p1: " << p1 << endl;

  // In public inheritance, public members of base class are available 
  // in derived class.
  p1.set_first_name("Mahatma");
  p1.set_last_name("Gandhi");
  cout << "Player p1: " << p1 << endl;

  return 0;
}

