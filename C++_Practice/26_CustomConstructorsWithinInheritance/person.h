#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <string_view>

class Person{
    friend std::ostream& operator<<(std::ostream& out, const Person& person);

  public:
    Person();
    Person(std::string_view fname_arg, int age_arg, std::string_view add_arg);
    ~Person();

    //Getters
    std::string get_full_name() const;
    int get_age() const;
    std::string get_address() const;

    //Setters
    void set_address(std::string_view fn);
   
  public:
    std::string m_full_name{"None"};

  protected:
    int m_age{18};

  private:
    std::string m_address{"None"};
};

#endif