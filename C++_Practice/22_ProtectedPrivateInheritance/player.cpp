#include "player.h"
#include "person.h"

Player::Player(std::string_view game_arg, int age_arg)
              : m_game(game_arg)
{
  //m_address = "SP Road, Pune";  // In any type of inheritance derived class can not access
                                  // private members of base class. Compiler error.

  m_age = age_arg;  // protected members of base class can be accessed 
                    // in derived classes
}

void Player::play(){
  m_full_name = "Sanju Baba";
  m_age = 44;
  //m_address = "Virar Mumbai";  // Private members of base class can not be accessed. Compiler error.
}

std::ostream& operator<<(std::ostream& out, const Player& player){
  out << "Player [ game: " << player.m_game << ", full_name: " << player.m_full_name
      << ", age: " << player.m_age << ", address: " << player.get_address() << " ]";
  return out;
}