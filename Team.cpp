#include "Team.hpp"
#include <vector>
#include <string>

Team::Team(){
    this->City = "";
    this->Name = "";
}

Team::Team(std::string City, std::string Name){
    this->City = City;
    this->Name = Name;
}

void Team::createRoster(){
    int current_num = 0;
    while(current_num < Team::MAX_ROSTER_SIZE){
        Player newPlayer = Player::CreateNewPlayer();
        Team::roster.push_back(newPlayer);
        current_num++;
    }
}

int Team::getSize(){
    return Team::roster.size();
}

int Team::getMaxSize(){
    return Team::MAX_ROSTER_SIZE;
}

std::vector<Player> Team::getRoster(){
    return Team::roster;
}



