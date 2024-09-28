#include <iostream>
#include "dog.h"

using namespace std;

void street_dog(){
  Dog street_dog ("Kalu", "German-Shepard", 7);   // The 'street_dog' object will be created when 'street_dog()' is called 
                                                  // and is deleted when control leaves the 'street_dog()' function.
}

void tommy_dog(Dog d){                                         // This is not a good practice. As we are copying localDog data into 'Dog d' instance, which will copy age pointer address of 'localDog'  
  cout << "tommy_dog() function is called for dog : " << endl; // Thus when 'localDog' is deleted, age variable from 'd' will keep on pointing to the deleted variable.
}

void without_explicit_delete(){
  Dog* d1 = new Dog("name1", "breed1", 1);        // We created a variable 'Dog' on 'heap' in function, so constructor will be called. However, as we did not explicitly delete 
}                                                 // the d1 before exiting the function. This will lead to memory leak and d1 memory will be leaked and destructor is also not called for 'd1' as 
                                                  // d1 is still existing but is not accessible.  

void with_explicit_delete(){
  Dog* d2 = new Dog("name2", "breed2", 2);
  delete d2;
}

int main(){
  Dog myDog ("Tipu", "Indian", 5);
  street_dog();

  Dog localDog ("Tommy", "Alsatian", 8);
  tommy_dog(localDog);

  without_explicit_delete();
  with_explicit_delete();

  // Constructors are executed in the order of declaration however destructors 
  // are executed in the reverse order of object creation
  cout << "\n Order of execution of constructor/destructor " << endl;
  Dog dog1 ("dog1", "Alsatian", 1);
  Dog dog2 ("dog2", "Alsatian", 2);
  Dog dog3 ("dog3", "Alsatian", 3);
  Dog dog4 ("dog4", "Alsatian", 4);

  cout << " Main Ended! " << endl;
  return 0;
}

