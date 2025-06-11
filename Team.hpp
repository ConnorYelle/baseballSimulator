#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "Player.hpp"

class Team {
    private:
        std::vector<Player> roster;
        std::string City;
        std::string Name;
        const int MAX_ROSTER_SIZE = 30;

    public:
        Team();
        Team(std::string City, std::string Name);
        void createRoster();
        int getSize();
        int getMaxSize();
        std::vector<Player> getRoster();

        //~Team();
};

#endif