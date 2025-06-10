#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "Player.hpp"

class Team {
    private:
        std::vector<Player> Players;
        std::string City;
        std::string Name;

    public:
        Team(std::string City, std::string Name);
        //~Team();
};

#endif