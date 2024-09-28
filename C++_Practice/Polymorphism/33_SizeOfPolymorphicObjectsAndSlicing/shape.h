#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

class Shape{
  public:
    Shape() = default;
    Shape(const std::string_view& desc);
    ~Shape();

    // virtual void draw () const {
    void draw() const {
      std::cout << "Shape::draw() method was called. Drawing " << m_description << endl;
    }
    
  protected:
    std::string m_description{""};
};

#endif