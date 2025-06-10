#include "Player.hpp"
#include <string>

Player::Player(const std::string& firstName, const std::string& lastName, const int number){ 
    this->firstName = firstName;
    this->lastName = lastName;
    this->number = number;
}
