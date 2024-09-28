#include "civilengineer.h"

CivilEngineer::~CivilEngineer(){}

void CivilEngineer::build_road(){
  //m_full_name = "Sir Goethic"; // 'CivilEngineer' class can not access any of the member of Engineer or Person class. Compiler Errors
}

std::ostream& operator<<(std::ostream& out, const CivilEngineer& obj){

  // As 'Engineer' class was privately inherited from 'Person' class, none of its function are available to 'CivilEngineer' class.
  // Compiler Error
  /*
  out << " CivilEngineer: [ fullName: " << obj.get_full_name() << ", m_age: " << obj.get_age() 
      << ", address: " << obj.get_address() << ", m_speciality: " << obj.m_speciality << "]" << std::endl;
  */
  out << " CivilEngineer: [ Speciality: " << obj.m_speciality << " ]" << std::endl;
  return out;
}

