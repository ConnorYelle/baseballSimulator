#include "Player.hpp"
using namespace std;

class Field{
    private:
        
        Player* positions[9];

        //0: First base runner      1: Second base runner      2: Third base runner
        Player* runners[3];

    public:
        Field();
        Player getPositionPlayer(int index);
};