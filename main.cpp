#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Player.hpp"
#include "Team.hpp"
#include "League.hpp"
using namespace std;

int main() {
    srand(time(0));
    League MLB = League(30);
    MLB.listTeams();
    return 0;
}
   