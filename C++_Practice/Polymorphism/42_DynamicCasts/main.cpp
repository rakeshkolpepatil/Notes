#include <iostream>
#include <string>
#include "dog.h"

using namespace std;

void do_something_with_animal_ptr(Animal* animal){
  std::cout << "In function taking base pointer ... " << std::endl;
  Feline* feline_ptr = dynamic_cast<Feline*>(animal);

  if(feline_ptr){
    feline_ptr->do_some_feline_thingy();
  }
  else{
    cout << "Couldn't cast to Feline pointer, sorry" << endl;
  }
}

void do_something_with_animal_ref(Animal & animal){
  std::cout << "In function taking base reference ... " << std::endl;
  Feline* feline_ptr = dynamic_cast<Feline*>(&animal);

  if(feline_ptr){
    feline_ptr->do_some_feline_thingy();
  }
  else{
    cout << "Couldn't cast to Feline reference, sorry" << endl;
  }
}


int main(){

  // Base class pointer
  Animal* animal1 = new Feline("stripes", "Feline1"); 

  // Since, 'do_some_feline_thingy()' is not a virtual function, we can not call it using 'Animal' class type pointer
  // animal1->do_some_feline_thingy();


  // If the cast succeeds, then we get a valid pointer back, if it fails then nullptr is returned. So, we can check
  // the pointer before calling members on the returned pointer.
  cout << "\n-------- Dynamic cast of pointers -------- " << endl;
  Feline* feline_ptr = dynamic_cast<Feline*>(animal1);
  if(feline_ptr){
    feline_ptr->do_some_feline_thingy();
  }
  else{
    cout << "Couldn't do the transformation from Animal* to Feline*" << endl;
  }

  Dog* dog_ptr = dynamic_cast<Dog*>(animal1);
  if(dog_ptr){
    dog_ptr->do_some_dog_thingy();
  }
  else{
    cout << "Couldn't do the transformation from Animal* to Dog*" << endl;
  }

  // Can do downstream transformation for references 
  // Base class references
  cout << "\n-------- Dynamic cast of references -------- " << endl;
  Feline feline2("strides", "feline2");
  Animal& animal_ref = feline2;

  // calling non virtual method on animal_ref will not work
  // animal_ref.do_some_feline_thingy();

  // Feline& feline_ref {dynamic_cast<Feline&>(animal_ref)};
  // OR
  Feline& feline_ref = dynamic_cast<Feline&>(animal_ref);
  feline_ref.do_some_feline_thingy();

  // In dynamic cast of reference, we do not have any way to check whether the 
  // transformation was successful or not.

  // Doing proper checks with references
  cout << "\n-------- Doing proper checks with references -------- " << endl;
  Feline* feline_ptr1 = dynamic_cast<Feline*>(&animal_ref);
  if(feline_ptr1){
    feline_ptr1->do_some_feline_thingy();
  }else{
    cout << "Couldn't do the transformation from (Animal&)* to Feline*" << endl;
  }

  // Doing proper checks with references for Dog class
  cout << "\n-------- Doing proper checks with references Dog Class -------- " << endl;
  Dog* dog_ptr1 = dynamic_cast<Dog*>(&animal_ref);
  if(dog_ptr1){
    dog_ptr1->do_some_dog_thingy();
  }else{
    cout << "Couldn't do the transformation from (Animal&)* to Dog*" << endl;
  }

  cout << "\n--------- Using dynamic casting in Functions ---------" << endl;
  do_something_with_animal_ptr(animal1);
  do_something_with_animal_ref(animal_ref);

  /*
  cout << "\n--------- dynamic casting of non inheritance hierarchies will not work ---------" << endl;
  int total = 10;
  std::string total_str = dynamic_cast<std::string> (total);
  */

  cout << "\n-------- Done! -------- " << endl;
  delete animal1;
  return 0;
}