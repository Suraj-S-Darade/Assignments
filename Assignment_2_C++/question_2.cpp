#include <iostream>
using namespace std;

class Patient {

    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

    static int ID;

public:

    // 1. Full Admission Constructor
    Patient(string n, int a, string w, string bg)
        : patientId(ID++), name(n), age(a), ward(w), bloodGroup(bg) {

        cout << "[Constructor] Full admission: "
             << name << endl;
    }


    // 2. Emergency Constructor
    Patient(string n, string w, string bg) : patientId(ID++), name(n), age(0), ward(w), bloodGroup(bg) {

        cout << "[Constructor] Emergency: " << name << endl;
    }


    // 3. Default Constructor
    Patient() : patientId(ID++), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {

        cout << "[Constructor] Default patient registered." << endl;
    }


    // Display patient record
    void displayRecord() const {

        cout << endl;
        cout << "Patient Record:" << endl;

        cout << "ID        : " << patientId << endl;
        cout << "Name      : " << name << endl;
        cout << "Age       : " << age << endl;
        cout << "Ward      : " << ward << endl;
        cout << "Blood Grp : " << bloodGroup << endl;
    }


    // Transfer patient to another ward
    void transferWard(string newWard) {

        cout << "Ward Transfer: " << name << " -> " << newWard << endl; 

        ward = newWard;
    }


    // Destructor
    ~Patient() {
        cout << "[Destructor] Patient " << name << " discharged." << endl;
    }
};


// Static variable definition
int Patient::ID = 1001;


int main() {

    // 1. Three stack objects

    Patient p1(
        "Meera Joshi",
        34,
        "Cardiology",
        "B+"
    );


    Patient p2(
        "Raj Patel",
        "Emergency",
        "O+"
    );


    Patient p3;


    // 2. Dynamic array of 4 patients

    Patient* patients = new Patient[4];


    // 3. Display all 4 patients

    for(int i = 0; i < 4; i++) {

        patients[i].displayRecord();
    }


    // 4. Transfer ward

    p2.transferWard("ICU");


    // 5. Delete dynamic array

    delete[] patients;


    // 6. Stack objects are automatically destroyed

    return 0;
}