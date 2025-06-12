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

Team::Team(std::string City, std::string Name){
    this->City = City;
    this->Name = Name;
}

vector<string> Team::randomTeamName(){
    static std::vector<std::string> cities;
    static std::vector<std::string> teamnames;
    static bool loaded = false;

    if (!loaded) { //if the file is not loaded, load it and add the values to the static vectors
        std::ifstream file("playerNames.csv");
        if (!file.is_open()) {
            std::cerr << "Error opening file\n";
            return {"null", "null"};
        }
        std::string line;
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string first, last;

            if (std::getline(ss, first, ',') && std::getline(ss, last)) {
                cities.push_back(first);
                teamnames.push_back(last);
            }
        }
        file.close();
        if (cities.empty() || teamnames.empty()) {
            std::cerr << "No names loaded.\n";
            return {"null", "null"};
        }

        loaded = true;
    }
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> distribution(0, static_cast<int>(cities.size()) - 1);

    //REMOVE ALL OF THIS AND ADD A LIST OF AVAILABLE CITIES INDEXES
    //MOVE THE CSV OPENING TO THE LEAGUE IN THE CONSTRUCTOR BASED ON THE NUMBER OF TEAMS IN THE PARAMETER
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

void Team::printRoster(){
    int index = 0;
    while(index < Team::MAX_ROSTER_SIZE){
        std::cout << Team::roster.at(index) << "\n";
        index++;
    }
}



