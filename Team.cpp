#include "Team.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
using namespace std;


Team::Team(){
    this->City = "";
    this->Name = "";
}

Team::Team(string City, string Name){
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

vector<Player> Team::getRoster(){
    return Team::roster;
}

void Team::printRoster(){
    int index = 0;
    while(index < Team::MAX_ROSTER_SIZE){
        cout << Team::roster.at(index) << "\n";
        index++;
    }
}

void Team::printTeamName(){
    cout<< Team::City+" "+Team::Name+"\n";
}



