#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Player.hpp"
using namespace std;

int main() {
    srand(time(0));

    Player player1 = Player::CreateNewPlayer();
    Player player2 = Player::CreateNewPlayer();

    std::cout << player1 << std::endl;
    std::cout << player2 << std::endl;

    return 0;
}
