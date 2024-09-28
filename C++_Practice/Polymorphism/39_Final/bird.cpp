#include "bird.h"

Bird::Bird(const std::string_view wing_color, const std::string_view description)
  : m_wing_color(wing_color), Animal(description)
{

}

Bird::~Bird()
{

}