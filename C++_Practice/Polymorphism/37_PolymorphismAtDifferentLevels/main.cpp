#include <iostream>
#include "animal.h"
#include "feline.h"
#include "cat.h"
#include "dog.h"
#include "bird.h"
#include "pigeon.h"
#include "crow.h"

using namespace std;

int main(){

  // Animal polymorphism
  cout << "\n----------------- Animal Polymorphism ---------------" << endl;
  Animal animal1("animal1");
  Dog dog1("dark gray", "dog1");
  Cat cat1("black stripes", "cat1");
  Pigeon pigeon1("white", "pigeon1");
  Crow crow1("black", "crow1");

  Animal* animals[] {&dog1, &cat1, &pigeon1, &crow1};

  for(auto& animal: animals) {
    animal->breathe();
  }

  // Feline polymorphism
  cout << "\n----------------- Feline Polymorphism ---------------" << endl;
  Dog dog2("dark gray", "dog2");
  Cat cat2("black stripes", "cat2");
  Pigeon pigeon2("white", "pigeon2"); 

  Feline* felines[] {&dog2, &cat2};
  // Feline* felines1[] {&dog2, &cat2, &animal1};     // You can not store the objects of base class in the pointer of derived class.
  // Feline* felines1[] {&dog2, &cat2, pigeon1};   // This will give a compiler error as 'pigeon1' is not a feline.

  for(const auto& feline: felines){
    feline->run();
  }

  // Bird polymorphism
  cout << "\n----------------- Bird Polymorphism ---------------" << endl;
  Pigeon pigeon3("white", "pigeon3");
  Crow   crow3("black", "crow3");

  Bird* birds[] = {&pigeon3, &crow3};
  for(const auto& bird: birds) {
    bird->fly();
  }

  return 0;
}