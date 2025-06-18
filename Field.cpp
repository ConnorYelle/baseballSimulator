#include <iostream>
#include "Field.hpp"

using namespace std;

Field::Field() {
    for (int i = 0; i < 9; ++i) {
        positions[i] = nullptr;
    }
    for (int i = 0; i < 3; ++i){
        runners[i] = nullptr;
    }
}

