#include "dog.h"

#include <iostream>
using namespace std;

Dog::Dog(std::string_view argName, std::string_view argBreed, int age){
  name = argName;
  breed = argBreed;
  p_age = new int{age};
  cout << "Dog constructor called for : "<< name << endl;
}

Dog::~Dog(){
  delete p_age;
  p_age = nullptr;
  cout << "Dog destructor called for  : " << name << endl;
}