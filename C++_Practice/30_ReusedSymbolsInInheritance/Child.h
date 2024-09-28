#ifndef CHILD_H
#define CHILD_H
#include "parent.h"

#include <iostream>
using namespace std;

class Child: public Parent {
  public:
    Child()= default;
    Child(int member_arg) : m_member_variable(member_arg){

    }
    ~Child(){}

    void print_var() const{
      cout << " The value in child is : " << m_member_variable << endl;
    }

    void show_values() const{
      cout << " The value in child is : " << m_member_variable << endl;
      cout << " The value in parent is : " << Parent::m_member_var << endl;
    } 

  protected:
    int m_member_variable{1000};
};

#endif