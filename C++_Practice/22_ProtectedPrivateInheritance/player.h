#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"
#include <string_view>
#include <string>

class Player: public Person{
    friend std::ostream& operator<<(std::ostream& out, const Player& player);

  public:
    Player() = default;
    Player(std::string_view game_arg, int age_arg);
    void play();
  private:
    std::string m_game{"None"};
};

#endif  // PLAYER_H