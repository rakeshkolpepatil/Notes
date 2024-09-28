#include "engineer.h"

Engineer::~Engineer(){}

Engineer::Engineer(){
  std::cout << " The default constructor for 'Engineer' class called ... " << std::endl;
}

void Engineer::build_something(){
  m_full_name = "Sir M Visvesvaraya";
  m_age = 55;
  //m_address = "Bengaluru";     // private members of base class can not be acccessed
                                 // inside derived class. Compiler Error.'
  contract_count = 1000;
}

std::ostream& operator<<(std::ostream& out, const Engineer& obj){
  out << " Engineer: [ name: " << obj.get_full_name() << ", age: " << obj.get_age() 
      << ", address: " << obj.get_address() << ", contract_count: "
      << obj.contract_count << "]" << std::endl;
  return out;
}

