#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <string_view>

class Person{
    friend std::ostream& operator<<(std::ostream& out, const Person& person);

  public:
    Person();
    Person(std::string_view fname_arg, std::string_view lname_arg, int age_arg);
    
    //Getters
    std::string get_first_name() const;
    std::string get_last_name() const;

    //Setters
    void set_first_name(std::string_view fn);
    void set_last_name(std::string_view ln);
  
  protected:
    int age{18};

  private:
    std::string first_name{"Rahul"};
    std::string last_name{"Bajaj"};
};

#endif