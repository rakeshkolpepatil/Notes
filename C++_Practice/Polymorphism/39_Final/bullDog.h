#ifndef BULLDOG_H
#define BULLDOG_H

#include "dog.h"

using namespace std;

class BullDog: public Dog {
  public:
    BullDog();
    virtual ~BullDog();

    // As run() method was defined as 'final' in 'Dog' class which is base class for 
    // 'BullDog' class, it is not accessible here. Compiler Error.
    /*
    virtual void run() const override{
      cout << "BullDog::run() method called. " << endl;
    }
    */
};

#endif