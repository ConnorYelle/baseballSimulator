#include "Player.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <ctime>


Player::Player(const std::string& firstName, const std::string& lastName, const int number, const int rating){ 
    this->firstName = firstName;
    this->lastName = lastName;
    this->number = number;
    this->rating = rating;
}

Player Player::CreateNewPlayer(const std::string& firstName, const std::string& lastName, const int number, const int rating){
    Player newPlayer = Player(firstName, lastName, number, rating);
    return newPlayer;
}

Player Player::CreateNewPlayer(){
    std::vector<std::string> name = randomName();
    Player newPlayer = Player(name[0], name[1], rand() % 100, 50 + rand() % 50);
    return newPlayer;
}

std::vector<std::string> Player::randomName() {
    // these are all static because we want the list of names to only be loaded once
    static std::vector<std::string> firstNames;
    static std::vector<std::string> lastNames;
    static bool loaded = false;

    if (!loaded) { //if the file is not loaded, load it and add the values to the static vectors
        std::ifstream file("playerNames.csv");
        if (!file.is_open()) {
            std::cerr << "Error opening file\n";
            return {"null", "null"};
        }

        std::string line;
        std::getline(file, line);  // Skip header

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string first, last;

            if (std::getline(ss, first, ',') && std::getline(ss, last)) {
                firstNames.push_back(first);
                lastNames.push_back(last);
            }
        }
        file.close();

        if (firstNames.empty() || lastNames.empty()) {
            std::cerr << "No names loaded.\n";
            return {"null", "null"};
        }

        loaded = true;
    }

    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> firstDist(0, static_cast<int>(firstNames.size()) - 1);
    std::uniform_int_distribution<> lastDist(0, static_cast<int>(lastNames.size()) - 1);

    std::string randomFirst = firstNames[firstDist(rng)];
    std::string randomLast = lastNames[lastDist(rng)];

    return {randomFirst, randomLast};
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player.firstName << " " << player.lastName
       << ", Number: " << player.number << ", Rating: " << player.rating;
    return os;
}

Player::~Player() {}
