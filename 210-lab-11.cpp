// COMSC-210 | Lab 11 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
using namespace std;

const int NUM_PATIENTS = 2;

// This is a basic info about a patient, including a list of medications they're currently taking.
struct Patient {
    string name;
    int age;
    string * medications;

    ~Patient() {
        if (medications) {
            delete [] medications;
        }
        medications = nullptr;
    }
};

// inputPatientData()...
// arguments:
// returns:
void inputPatientData(Patient *);

// displayPatientData()...
// arguments:
// returns:
void displayPatientData(Patient *);

int main(){
    // This program models patient intake at a hospital.
    Patient * patients = new Patient[NUM_PATIENTS];

    delete [] patients;

    return 0;
}
