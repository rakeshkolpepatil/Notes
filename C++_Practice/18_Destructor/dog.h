#ifndef DOG_H
#define DOG_H

#include <string>
#include <string_view>

class Dog{

  public:
    Dog() = default;
    Dog(std::string_view argName, std::string_view argBreed, int argAge);
    ~Dog();

  private:
    std::string name;
    std::string breed;
    int* p_age{nullptr};
};

#endif