#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <algorithm>
#include "League.hpp"

using namespace std;

League::League(){
}

League::League(int teamNumber){
    static vector<string> teamNames;
    static bool loaded = false;
    if (!loaded) { //if the file is not loaded, load it and add the values to the static vector
        ifstream file("teamNames.csv");
        if (!file.is_open()) {
            cerr << "Error opening file\n";
        }
        string line;
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string city;
            string name;
            if (getline(ss, city, ',') && getline(ss, name)) {
                teamNames.push_back(city+","+name);
            }
        }
        file.close();
        if (teamNames.empty()) {
            cerr << "No team names loaded.\n";
        }
        loaded = true;
    }

    vector<int> teamIndexes;
    for(int i = 0; i < 40;  i++){
        teamIndexes.push_back(i);
    }
    static mt19937 rng1(static_cast<unsigned int>(time(nullptr))); //create random object
for (int i = 0; i < teamNumber; i++) {
    std::uniform_int_distribution<> distribution(0, static_cast<int>(teamIndexes.size() - 1));
    int randomPosInIndexList = distribution(rng1);         // index in teamIndexes
    int actualIndex = teamIndexes[randomPosInIndexList];   // actual index in teamNames
    teamIndexes.erase(teamIndexes.begin() + randomPosInIndexList);

    string selectedTeam = teamNames.at(actualIndex);
    size_t commaPos = selectedTeam.find(",");
    string selectedCity = selectedTeam.substr(0, commaPos);
    string selectedName = selectedTeam.substr(commaPos + 1);        
    Team newTeam(selectedCity, selectedName);
    League::teams.push_back(newTeam);
}
}

void League::listTeams(){
    cout << "Current Teams:" <<"\n";
    int i = 1;
    for (size_t i = 0; i < League::teams.size(); ++i) {
        cout << i + 1 << ". ";
        League::teams[i].printTeamName();
    }
}

