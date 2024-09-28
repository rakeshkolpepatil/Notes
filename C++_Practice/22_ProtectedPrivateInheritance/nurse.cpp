#include "nurse.h"

Nurse::~Nurse(){

}

std::ostream& operator<<( std::ostream& out, const Nurse& n){
  out << "Nurse [ Fullname: " << n.get_full_name() << ", age: " << n.get_age() << ", address: " << n.get_address() 
      << ", practice_certificate_id: " << n.m_practice_certificate_id << " ]" << std::endl; 
  return out;
}

void Nurse::treat_unwell_person(){
  m_full_name = "Ravi Shinde";
  m_age = 23;
  //m_address = "Indore";           // Private member of base class is not accessible in any case.
}
