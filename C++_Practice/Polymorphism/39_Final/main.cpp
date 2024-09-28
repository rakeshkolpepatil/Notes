#include <iostream>

// Interesting fact #1:
class Plane final{
  Plane() = default;
};

// The following syntax will generate compiler error, 
// as 'Plane' class is defined as 'final'. 
/*
class FiterJet : public Plane {

};
*/

using namespace std;

int main(){
  cout << "Hello " << std::endl;
  return 0;
}