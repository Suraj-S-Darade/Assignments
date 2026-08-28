#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2) {

    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV2(int& reading1, int& reading2) {

    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorPairV3(int* reading1, int* reading2) {

    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}


int main() {

    int A = 55;
    int B = 12;


    /*
       V1 fails because it uses Call by Value.
       A copy of A and B is passed to the function.
       The function swaps only those copies, not the original variables.
       Therefore, A and B remain unchanged after the function call.
    */

    cout << "--- V1: Call by Value ---" << endl;

    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV1(A, B);

    cout << "After  : A=" << A << "  B=" << B << endl;


    cout << "\n--- V2: Call by Reference ---" << endl;

    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV2(A, B);

    cout << "After  : A=" << A << "  B=" << B << endl;


    cout << "\n--- V3: Call by Pointer ---" << endl;

    cout << "Before : A=" << A << "  B=" << B << endl;

    resetSensorPairV3(&A, &B);

    cout << "After  : A=" << A << "  B=" << B << endl;


    return 0;
}