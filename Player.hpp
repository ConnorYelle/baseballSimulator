#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    private:
        std::string firstName;
        std::string lastName;
        int number;
        std::string primaryPosition;
        std::string secondaryPosition;

    public:
        Player(const std::string& firstName, const std::string& lastName, const int number);
        ~Player();

};

#endif