#include <iostream>

using namespace std;

class Base{
  public:
    Base(){
      cout << "Base constructor called." << endl;
      this->setup(); // Static binding kicks in here.
    };

    virtual ~Base(){
      clean_up();
      cout << "Base destructor called." << endl;
    };

    virtual void setup(){
      cout << "Base::setup() called "<< std::endl;
      m_value = 10;
    }
    virtual void clean_up(){
      cout << "Base::clean_up() called " << std::endl;
    }
    int get_value(){
      return m_value;
    }
  protected:
    int m_value;
};

class Derived: public Base{
  public:
    Derived(){
      cout << "Derived constructor called. " << endl;
    };
    virtual ~Derived(){
      cout << "Derived destructor called." << std::endl;
    };

    virtual void setup() override {
      cout << "Derived::setup() called "<< std::endl;
      m_value = 100;
    }
    virtual void clean_up() override {
      cout << "Derived::clean_up() called " << std::endl;
    }
    int get_value(){
      return m_value;
    }
};

int main(){

  Base* p_base = new Derived;      // The derived class constructor will call base class constructor, which calls setup() function, 
                                   // We might expect setup() function of derived class to be called but bcz of static binding the setup() function
                                   // of base class will be called instead.

  int value = p_base->get_value();         // If you want to set up the value to '100' then you should not call setup() function inside 'Base' constructor
  cout << "\n value : " << value << endl;  // Instead, call it after the object has been created and inside main fuction.

  p_base->clean_up();
  delete p_base;

  return 0;
}

