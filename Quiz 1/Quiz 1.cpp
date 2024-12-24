#include "CircleList.h"
#include <iostream>
using namespace std;

int main() {
    CircleList Ameer;
    Ameer.add("I am a Developer");
    Ameer.add("I am a Problem Solver");

    CircleList Hamza;
    Hamza.add("I am a Developer");
    Hamza.add("I am a Problem Solver");

    CircleList Nexus;
    Nexus.add("I am Genius");
    Nexus.add("My aim to conquer the world!");



    cout << "compare 2 lists" << endl;
    if (Ameer.isEqual(Nexus)) {
        cout << "Lists are equal" << endl;
    }
    else {
        cout << "Lists are not equal" << endl;
    }

    cout << "compare 2 lists" << endl;
    if (Ameer.isEqual(Hamza)) {
        cout << "Lists are equal" << endl;
    }
    else {
        cout << "Lists are not equal" << endl;
    }


    return 0;
}