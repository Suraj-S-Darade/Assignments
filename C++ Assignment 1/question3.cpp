#include <iostream>
using namespace std;

const int FLOORS = 3;
const int ROOMS = 3;
const double WARNING = 30.0;

void readTemperatures(double temp[][ROOMS]) {

    for(int i = 0; i < FLOORS; i++) {

        for(int j = 0; j < ROOMS; j++) {

            cout << "Enter temperature for Floor "
                 << i + 1 << ", Room " << j + 1 << ": ";

            cin >> temp[i][j];
        }
    }
}

void displayTemperatures(double temp[][ROOMS]) {

    cout << "\n        Room1    Room2    Room3" << endl;

    for(int i = 0; i < FLOORS; i++) {

        cout << "Floor " << i + 1 << " : ";

        for(int j = 0; j < ROOMS; j++) {

            cout << temp[i][j] << "    ";
        }

        cout << endl;
    }
}

void findHottestRoom(double temp[][ROOMS]) {

    double maxTemp = temp[0][0];

    int hotFloor = 0;
    int hotRoom = 0;

    for(int i = 0; i < FLOORS; i++) {

        for(int j = 0; j < ROOMS; j++) {

            if(temp[i][j] > maxTemp) {

                maxTemp = temp[i][j];
                hotFloor = i;
                hotRoom = j;
            }
        }
    }

    cout << "\nHottest Room : Floor "
         << hotFloor + 1
         << ", Room "
         << hotRoom + 1
         << " -> "
         << maxTemp << " C" << endl;
}

void findHottestFloor(double temp[][ROOMS]) {

    double highestAverage = 0;
    int hottestFloor = 0;

    for(int i = 0; i < FLOORS; i++) {

        double sum = 0;

        for(int j = 0; j < ROOMS; j++) {

            sum = sum + temp[i][j];
        }

        double average = sum / ROOMS;

        if(average > highestAverage) {

            highestAverage = average;
            hottestFloor = i;
        }
    }

    cout << "Hottest Floor : Floor "
         << hottestFloor + 1
         << " (avg "
         << highestAverage
         << " C)" << endl;
}

void countWarningRooms(double temp[][ROOMS]) {

    int count = 0;

    for(int i = 0; i < FLOORS; i++) {

        for(int j = 0; j < ROOMS; j++) {

            if(temp[i][j] >= WARNING) {

                count++;
            }
        }
    }

    cout << "Rooms at WARNING or above : "
         << count << endl;
}

int main() {

    double temp[3][3];

    readTemperatures(temp);

    displayTemperatures(temp);

    findHottestRoom(temp);

    findHottestFloor(temp);

    countWarningRooms(temp);

    return 0;
}