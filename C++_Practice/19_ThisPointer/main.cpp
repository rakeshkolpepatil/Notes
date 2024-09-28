#include <iostream>
#include <string>

using namespace std;

// ------------------------------- Using 'this' keyword ---------------------------------
class Dog{
  public:
    Dog() = default;
    Dog(std::string name, std::string breed, int age);
    ~Dog();

    /*
    // Setter Functions
    void set_name(std::string_view name){
      //name = name;        // This will do nothing, we need to use 'this' pointer.
      this->name = name;
    }
    void set_breed(std::string_view breed){
      this->breed = breed; 
    }
    void set_age(int age) {
      this->age = age;
    }
    */

    /*
    // Setter Functions - Chained Calls using Pointers
    Dog* set_name(std::string_view name){
      //name = name;        // This will do nothing, we need to use 'this' pointer.
      this->name = name;
      return this;
    }
    Dog* set_breed(std::string_view breed){
      this->breed = breed; 
      return this;
    }
    Dog* set_age(int age) {
      this->age = age;
      return this;
    }
    */

    // Setter Functions - Chained Calls using References
    Dog& set_name(std::string_view name){
      //name = name;        // This will do nothing, we need to use 'this' pointer.
      this->name = name;
      return *this;
    }
    Dog& set_breed(std::string_view breed){
      this->breed = breed; 
      return *this;
    }
    Dog& set_age(int age) {
      this->age = age;
      return *this;
    }

    void print_info(){
      cout << " Dog ["<< this << "] - { name: " << this->name << ", breed: " << this->breed << ", age: " << this->age << " }" << endl;
    }

  private:
    std::string name;
    std::string breed;
    int age;
};

// ------------------------------- Using 'this' keyword ---------------------------------
// constructor
Dog::Dog(std::string name, std::string breed, int age) {
  this->name = name;
  this->breed = breed;
  this->age = age;
  cout << " The Dog object created with name: " << name << " at " << this << endl; 
}

Dog::~Dog(){
  cout << " The Dog object destructed for name: " << name << " at " << this << endl;
}

int main(int argc, char** argv){
  Dog d1 ("Tommy", "Shepherd", 2);
  d1.print_info();

  /*
  d1.set_name("Puppy");
  d1.set_breed("Indian");
  d1.set_age(4);
  */

  /*
  // Chained calls using pointers
  d1.set_name("Puppy")->set_breed("Indian")->set_age(4);
  */

  // Chained calls using references
  d1.set_name("Puppy").set_breed("Indian").set_age(4);

  d1.print_info();
  return 0;
}

