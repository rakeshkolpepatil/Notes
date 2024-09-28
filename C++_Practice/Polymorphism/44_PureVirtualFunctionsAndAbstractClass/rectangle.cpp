#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(double width, double height, string_view description)
    :Shape(description), m_width(width), m_height(height)
{

}

Rectangle::~Rectangle(){
    
}