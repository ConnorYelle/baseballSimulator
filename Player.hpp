#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
    private:
        std::string firstName;
        std::string lastName;
        int number;
        std::string primaryPosition;
        std::string secondaryPosition;
        Player(const std::string& firstName, const std::string& lastName, const int number);
        static std::vector<std::string> randomName();

    public:
        Player CreateNewPlayer(const std::string& firstName, const std::string& lastName, const int number);
        static Player CreateNewPlayer(); //uses RandomName();
        ~Player();

        friend std::ostream& operator<<(std::ostream& os, const Player& player);

};

#endif