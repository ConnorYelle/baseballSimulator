#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Player.hpp"
#include "Team.hpp"
#include "League.hpp"
#include "field.cpp"
using namespace std;

int main() {
    srand(time(0));
    cout << "===========================================================================\n";
    cout << "                     WELCOME TO BASEBALL SIM 2025\n";
    cout << "===========================================================================\n";
    bool selection = false;
    char command;
    while(selection == false){
        cout << "\nMain Menu:\n";
        cout << "(S) Start new game\n";
        cout << "(L) Load existing game\n";
        cout << "(D) Delete save\n";
        cout << "(E) Exit\n";

        cout << "Enter Command: ";
        cin >> command;

        if(command == 'S' || command == 's'){
            selection == true;
        }
        else if(command == 'L' || command == 'l'){
            selection == true;
        }
        else if(command == 'D' || command == 'd'){
            selection == true;
        }
        else if(command == 'E' || command == 'e'){
            selection == true;
            cout << "\nThank you for playing! Have a nice day!\n";
            return 0;
        }
        else {
            cout << "Please enter a valid command or (E) to exit";
        }
    }
}
   