#include <iostream>
#include "shape.h"
#include "ellipse.h"
#include <memory>

using namespace std;

int main(){
  // Shape
  std::cout << "------------------- Define Shape ------------------" << std::endl;
  Shape shape1("shape1");
  std::cout << "shape count : " << Shape::m_count << std::endl;

  Shape shape2("shape2");
  std::cout << "shape count : " << Shape::m_count << std::endl;

  Shape shape3("shape3");
  std::cout << "shape count : " << Shape::m_count << std::endl;

  // Ellipse
  std::cout << "------------------- Define Ellipse ------------------" << std::endl;
  Ellipse ellipse1("ellipse1", 10, 20);
  std::cout << "Shape count       : " << Shape::m_count << std::endl;

  // m_count is inherited from 'Shape' to 'Ellipse' class, so 'Ellipse::m_count' will show same value as 'Shape::m_count'
  std::cout << "Ellipse m_count   : " << Ellipse::m_count << std::endl;

  // 'Ellipse::e_m_count' will keep track of how many objects of type 'Ellipse' got created 
  std::cout << "Ellipse e_m_count : " << Ellipse::e_m_count << std::endl;


  std::cout << "------------------- Nested Scope ------------------" << std::endl;
  // Polymorphic behaviour
  {
    // Nested scope: using shared pointers so that objects are destroyed automatically without us directly calling delete.
    std::shared_ptr<Shape> shapes1[]
    {
      std::make_shared<Ellipse>("ellipse_at_0", 10, 12),
      std::make_shared<Ellipse>("ellipse_at_1", 11, 22)
    };
    cout << "\n ------- Inside nested scope " << std::endl;    
    std::cout << "  Shape count       : " << Shape::m_count << std::endl;
    std::cout << "  Ellipse m_count   : " << Ellipse::m_count << std::endl;
    std::cout << "  Ellipse e_m_count : " << Ellipse::e_m_count << std::endl;
  }
  cout << "\n ------- Outside nested scope " << std::endl;    
  std::cout << "  Shape count       : " << Shape::m_count << std::endl;
  std::cout << "  Ellipse m_count   : " << Ellipse::m_count << std::endl;
  std::cout << "  Ellipse e_m_count : " << Ellipse::e_m_count << std::endl;

  std::cout << "\n------------------- Shape Polymorphism ------------------" << std::endl;
  // Shape Polymorphism
  Shape* shapes[] {&shape1, &ellipse1};
  for(auto& shape: shapes){
    cout << shape->getCount() << std::endl;
  }

  return 0;
}

