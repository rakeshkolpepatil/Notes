#include "player.h"
#include "person.h"

Player::Player(std::string_view game_arg, int age_arg)
              : m_game(game_arg)
{
  //first_name = "Mahatma"; // In 'public inheritance' derived class can not access
  //last_name = "Gandhi";   // private members of base class. Compiler error.

  age = age_arg;  // protected members of base class can be accessed 
                  // in derived classes
}

std::ostream& operator<<(std::ostream& out, const Player& player){
  out << "Player [ game: "<< player.m_game << ", first_name: " << player.get_first_name() 
      << ", last_name: " << player.get_last_name() << ", age: " << player.age << " ]";
  return out;
}