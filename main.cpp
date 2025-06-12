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
    team1.printRoster();
    return 0;
}
   