#include <iostream>
#include <cmath>
using namespace std;

inline double distanceBetween(double x1, double y1,
                              double x2, double y2) {

    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

inline double toRadians(double degrees) {

    return degrees * (M_PI / 180.0);
}

inline double clamp(double value, double minVal, double maxVal) {

    if (value < minVal) {
        return minVal;
    }

    if (value > maxVal) {
        return maxVal;
    }

    return value;
}

inline bool isInSafeZone(double x, double y,
                         double cx, double cy,
                         double radius) {

    double distance = distanceBetween(x, y, cx, cy);

    return distance <= radius;
}


int main() {

    cout << "Distance : "
         << distanceBetween(0, 0, 3, 4) << endl;

    cout << "Radians : "
         << toRadians(180) << endl;

    cout << "Clamped value : "
         << clamp(120, 0, 100) << endl;

    cout << "Safe Zone : "
         << isInSafeZone(3, 4, 0, 0, 5) << endl;

    return 0;
}