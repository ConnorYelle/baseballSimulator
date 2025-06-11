#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
    private:
        std::string firstName;
        std::string lastName;
        int number;
        int rating;
        std::string primaryPosition;
        std::string secondaryPosition;
        Player(const std::string& firstName, const std::string& lastName, const int number, const int rating);
        static std::vector<std::string> randomName();

    public:
        Player CreateNewPlayer(const std::string& firstName, const std::string& lastName, const int number, const int rating);
        static Player CreateNewPlayer(); //uses RandomName();
        ~Player();

        friend std::ostream& operator<<(std::ostream& os, const Player& player); //the operator<< function is a non-member
        //and can not access the private attributes of the player class, this is why we define the method as a friend so that it can 
        //access the private members of the class.

};

#endif