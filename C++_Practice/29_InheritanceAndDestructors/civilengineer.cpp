#include "civilengineer.h"

CivilEngineer::~CivilEngineer(){
  std::cout << " The destructor for 'CivilEngineer' class called ... " << std::endl;
}

CivilEngineer::CivilEngineer(){
  std::cout << " The default constructor for 'CivilEngineer' class called ... " << std::endl;
}

// Proper Custom Constructor - Desired Code
CivilEngineer::CivilEngineer(std::string_view fullname_arg, int age_arg, std::string_view add_arg, int cont_count_arg,
                  std::string_view spec_arg)
              : Engineer(fullname_arg, age_arg, add_arg, cont_count_arg), m_speciality(spec_arg) 
{
  std::cout << " The custom constructor for 'CivilEngineer' class called ..." << std::endl;
}

/*
// Trying to initialize without using constructors - Undesired Code - Compiler Error
CivilEngineer::CivilEngineer(std::string_view fullname_arg, int age_arg, std::string_view add_arg, int cont_count_arg,
                  std::string_view spec_arg)
{
  m_full_name = fullname_arg;
  m_age = age_arg;
  m_address = add_arg;               // This is private to 'Person' class, not accessible, compiler Error.
  contract_count = cont_count_arg;   // This is private to 'Person' class, not accessible, compiler Error.
  m_speciality = spec_arg;
}
*/
/*
// Trying to initialize without using constructors, using initializer list - Undesired Code - Compiler Error
// Private members are inaccessible everywhere, whether inside constructor or inside initializer list.
CivilEngineer::CivilEngineer(std::string_view fullname_arg, int age_arg, std::string_view add_arg, int cont_count_arg,
                  std::string_view spec_arg)
          : m_full_name(fullname_arg), m_age(age_arg), m_address(add_arg), contract_count(cont_count_arg),
            m_speciality(spec_arg)
{}
*/

// Copy constructor for CivilEngineer class.
CivilEngineer::CivilEngineer(const CivilEngineer& source)
              : Engineer(source), m_speciality(source.m_speciality) 
{
  std::cout << " The custom copy constructor for 'CivilEngineer' class called ..." << std::endl;
}

void CivilEngineer::build_road(){
  //m_full_name = "Sir Goethic"; // 'CivilEngineer' class can not access any of the member of Engineer or Person class. Compiler Errors
}

std::ostream& operator<<(std::ostream& out, const CivilEngineer& obj){

  // As 'Engineer' class was privately inherited from 'Person' class, none of its function are available to 'CivilEngineer' class.
  // However, by making use of 'using' keyword, we have resurrected following functions. Thus they are again available.
  
  out << " CivilEngineer: [ fullName: " << obj.get_full_name() << ", m_age: " << obj.get_age() 
      << ", address: " << obj.get_address() << ", m_speciality: " << obj.m_speciality << "]" << std::endl;
  return out;
}

