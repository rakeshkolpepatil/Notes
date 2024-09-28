#include <iostream>

using namespace std;
const double PI {3.141'592'653'589'793'238'462'643'383'279'5};

class Cylinder {
  public:
    // Default constructor
    // Cylinder() = default; // Compiler will generate default empty constructor to the 'Cylinder()'

    // empty constructor : empty constructor is created when user does not provide any constructor explicitly.
    // Cylinder(){}

    // Parameter less constructor 
    Cylinder(){
      base_radius = 2.0;
      height = 2.0;
    }

    // Parameterized constructor
    Cylinder(double radius, double height){
      base_radius = radius;
      height = height;
    }
    double volume(){
      return PI * base_radius * base_radius * height;
    }

    // getter functions
    double get_base_radius(){
      return base_radius;
    }
    double get_height(){
      return height;
    }

    // setter functions
    void set_base_radius(double r){
      base_radius = r;
    }
    void set_height(double h){
      height = h;
    }

  private:
    // member variables
    double base_radius {};
    double height {};
};

class NewCylinder {
  public:
    double volume(){
      return PI * base_radius * base_radius * height;
    }

    // member variables
    double base_radius {5};
    double height {10};
};

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

  // The NewCylinder class members are all public. So they can be accessed directly from outside the class.
  NewCylinder nc;
  cout << endl;
  cout << " The NewCylinder details :- " << endl;
  cout << " Volume      = " << nc.volume() << endl;
  cout << " Base_radius = " << nc.base_radius << endl;
  cout << " Height      = " << nc.height << endl;

  nc.base_radius = 20;
  nc.height = 10;
  cout << endl;
  cout << " The modified NewCylinder details :- " << endl;
  cout << " Volume      = " << nc.volume() << endl;
  cout << " Base_radius = " << nc.base_radius << endl;
  cout << " Height      = " << nc.height << endl;

  return 0;
}