#include <iostream>
#include <memory>
#include "animal.h"
#include "feline.h"
#include "cat.h"
#include "dog.h"
#include "bird.h"
#include "pigeon.h"
#include "crow.h"

#include "stream_insertable.h"

using namespace std;

class Point: public StreamInsertable {
  public:
    Point() = default;
    Point(double x, double y) : m_x(x), m_y(y) {

    };

    virtual void stream_insert( std::ostream& out) const override {
      out << "Point [" << m_x << ", " << m_y << "]" << std::endl;
    }

  private:
    double m_x;
    double m_y;
};

int main(){

  Point p1(1, 4);
  std::cout << " P1: " << p1 << std::endl;    // Because of the operator overloading, the compiler is going to convert this line of code to the next line of code.
  operator <<(std::cout, p1);

  Animal animal1("Animal1");
  std::cout << "Animal1 :- " << animal1 <<  std::endl;

  Feline feline1("Black", "Feline1");
  std::cout << "Feline1 :- " << feline1 << std::endl; 

  Dog dog1("black spots", "dog1");
  std::cout << "dog1 :- " << dog1 << std::endl; 

  Cat cat1("white", "cat1");
  std::cout << "cat1 :- " << cat1 << std::endl; 

  cout << " -------- Unique Pointer --------- " << std::endl;
  std::unique_ptr<Animal> animal2 = std::make_unique<Dog>("Stripes", "dog2");
  std::cout << *animal2 << std::endl;

  std::unique_ptr<Animal> animal3 = std::make_unique<Dog>("BlackWhite", "dog3");
  std::cout << *animal3 << std::endl;

  cout << " -------- Can put Animals in a Pointer and print them polymorphically --------- " << std::endl;
  std::shared_ptr<Animal> animals[] = {
    std::make_shared<Dog> ("white", "dog3"),  
    std::make_shared<Cat> ("Pink", "cat4"),
    std::make_shared<Crow> ("Black wings", "crow4"),
    std::make_shared<Pigeon> ("white wings", "pigeon4"),
  };

  std::cout << std::endl;
  std::cout << "Printing out animals array : \n" << std::endl;
  for(const auto& animal: animals){
    cout << *animal;
  }


  return 0;
}