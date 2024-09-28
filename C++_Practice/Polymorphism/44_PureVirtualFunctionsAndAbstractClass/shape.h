#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class Shape{
  protected:
    Shape(const std::string_view& desc);

  public:
    Shape() = default;
    ~Shape() = default;

    // Pure Virtual Functions
    virtual double perimeter() const = 0;
    virtual double area() const = 0;

  protected:
    std::string m_description{""};
};

#endif