#include "engineer.h"

Engineer::~Engineer(){}

/*
Engineer::Engineer(){
  std::cout << " The default constructor for 'Engineer' class called ... " << std::endl;
}

Engineer::Engineer(const Engineer& source)
  : Person(source), contract_count(source.contract_count)  // Here, we are making use of copy constructor of base class.
{
  std::cout << " The custom copy constructor for 'Engineer' class called ..." << std::endl;
}
*/

Engineer::Engineer(std::string_view fullname_arg, int age_arg, std::string_view add_arg, int cont_count_arg)
  : Person(fullname_arg, age_arg, add_arg), contract_count(cont_count_arg)
{
  std::cout << " The custom constructor for 'Engineer' class called ..." << std::endl;
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