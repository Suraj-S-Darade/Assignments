#include <iostream>
using namespace std;


namespace Physics {

    double clamp(double val, double min, double max) {

        if(val < min)
            return min;

        if(val > max)
            return max;

        return val;
    }


    double lerp(double a, double b, double t) {

        return a + (b - a) * t;
    }
}


namespace GameMath {

    int clamp(int val, int min, int max) {

        if(val < min)
            return min;

        if(val > max)
            return max;

        return val;
    }


    double lerp(double a, double b, double t) {

        return a + (b - a) * t;
    }
}


int main() {

    double velocity = Physics::clamp(120.5, 0.0, 100.0);

    int health = GameMath::clamp(120, 0, 100);


    cout << "Physics Clamp : " << velocity << endl;


    cout << "GameMath Clamp : " << health << endl;


    double physicsResult = Physics::lerp(0.0, 100.0, 0.5);

    double uiResult = GameMath::lerp(0.0, 100.0, 0.5);


    cout << "Physics Lerp : " << physicsResult << endl;


    cout << "GameMath Lerp : " << uiResult << endl;


    // Limited block scope

    {
        using namespace GameMath;

        cout << "Using namespace inside block : " << clamp(150, 0, 100) << endl;
    }


    return 0;
}