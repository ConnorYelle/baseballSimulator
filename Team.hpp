#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "Player.hpp"
using namespace std;

class Team {
    private:
        vector<Player> roster;
        string City;
        string Name;
        const int MAX_ROSTER_SIZE = 30;

    public:
        Team();
        Team(string City, string Name);
        void createRoster();
        int getSize();
        int getMaxSize();
        vector<Player> getRoster();
        vector<string> randomTeamName();
        void printRoster();
        
        //~Team();
};

#endif