#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Player.hpp"
#include "Team.hpp"
using namespace std;

int main() {
    srand(time(0));

    Team team1 = Team("Toronto", "Huskies");
    team1.createRoster();
    int index = 0;
    while(index < team1.getMaxSize()){
        cout << team1.getRoster().at(index) << "\n";
        index++;
    }
    return 0;
}
