#include <vector>
#include "Team.hpp"

using namespace std;

class League{
    private:
        vector<Team> teams;

    public:
        League();
        League(int teamNumber);
        void listTeams();
};
