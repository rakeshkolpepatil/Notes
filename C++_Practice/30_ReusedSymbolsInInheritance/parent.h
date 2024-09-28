#ifndef PARENT_H
#define PARENT_H

#include <iostream>
using namespace std;

class Parent {
  public:
    Parent() = default;
    ~Parent(){};
    Parent(int mVar) : m_member_var(mVar){

    }  

    void print_var() const{
      cout << "The value of the parent is " << m_member_var << endl;
    }

  protected:
    int m_member_var{100};
};

#endif