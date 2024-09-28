#include <iostream>

using namespace std;

class Dog{
    std::string name; 
  public:             // We can specify public member variables if required.
    int age;
};

struct Cat{
    std::string name;
  private:            // we can explicitly create private member variables
    int age;
};

struct Point{
  double x, y;
};

class Man{
  size_t leg_count;
  size_t arm_count;
};

class Man1{
  public:
    Man1(size_t legs, size_t arms){
      this->leg_count = legs;
      this->arm_count = arms;
    }

  private:
    size_t leg_count;
    size_t arm_count;
};

int main(int argc, char **argv){
  Dog d1;
  Cat c1;

  // d1.name = "Tommy";  // Compilation error as we are trying to access private member variable
  d1.age = 1;          
  cout << "The age of dog is : " << d1.age << endl;

  c1.name = "Money";
  //  c1.age = 1;         // Compilation error as we are trying to access private member variable
  cout << "The name of cat is : " << c1.name << endl;

  Point p;
  p.x = 11.11;
  p.y = 22.22;
  cout << " The point : (" << p.x <<", "<< p.y << ")" << endl;

  p.x = 55.55;
  p.y = 66.66;
  cout << " The point : (" << p.x <<", "<< p.y << ")" << endl;

  p.x = 77.77;
  p.y = 99.99;
  cout << " The point : (" << p.x <<", "<< p.y << ")" << endl;

  cout << "\n----------- Size of Class Objects ----------- " << endl;
  cout << " The size of class(Dog) : " << sizeof(Dog) << endl;
  cout << " The size of Dog object d1 : " << sizeof(d1) << endl;
  cout << " The size of int : " << sizeof(int) << endl;
  cout << " The size of std::string : " << sizeof(std::string) << endl;

  Man m1;
  cout << "\n The size of class(Man) : " << sizeof(Man) << endl;
  cout << " The size of Man class m1 : " << sizeof(m1) << endl;
  cout << " The size of size_t : " << sizeof(size_t) << endl;

  Man1 m2(2, 2);
  cout << "\nFunctions do not change the size of the class or class object" << endl;
  cout << " The size of class(Man1) : " << sizeof(Man1) << endl;
  cout << " The size of Man class m2 : " << sizeof(m2) << endl;
  cout << " The size of size_t : " << sizeof(size_t) << endl;

  // The std::string is implemented as a class, which internally stores data as a char* pointer irrespective of the 
  // size of the data to be stored.
  cout << "\n----------- Size of the String ----------- " << endl;
  std::string s1 {"Hello World!"};
  std::string s2 {"Earth rotates around its own axis."};
  cout << "sizeof(s1) : " << sizeof(s1) << endl;
  cout << "sizeof(s2) : " << sizeof(s2) << endl;

  return 0;
}