// COMSC-210 | Lab 11 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <string>
using namespace std;

const int NUM_PATIENTS = 2;

// This is a basic info about a patient, including a list of medications they're currently taking.
struct Patient {
    string name;
    int age;
    string * medications;

    ~Patient() {
        if (medications)
            delete [] medications;
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

    for (int i = 0; i < NUM_PATIENTS; i++) {
        inputPatientData(&patients[i]);
    }

    delete [] patients;

    return 0;
}

void inputPatientData(Patient * p) {
    static int patientNum = 1;
    int numMeds;

    cout << "Enter the data for patient #" << patientNum << ": \n";
    cout << "Name: ";
    getline(cin, p->name);
    cout <<  "Age: ";
    cin >> p->age;
    cout << "Enter the number of medications the patient is currently taking: ";
    cin >> numMeds;
    cin.ignore();
    // If the patient is not currently taking any medications, this should not execute.
    if (numMeds > 0) {
        p->medications = new string[numMeds];
        for (int i = 0; i < numMeds; i++) {
            cout << "Enter the name of medication #" << i + 1 << ": ";
            getline(cin, p->medications[i]);
        }
    }

    // Placing cin.ignore() here to clear the stream before the next time the function gets used
    cin.ignore();

    cout << "Patient #" << patientNum << " intake complete!\n";
    patientNum++;
}