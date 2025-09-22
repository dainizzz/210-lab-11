// COMSC-210 | Lab 11 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
#include <string>
using namespace std;

const int NUM_PATIENTS = 2;

// This is a basic info about a patient, including a list of medications they're currently taking.
struct Patient {
	string firstName;
	string lastName;
	int age;
	int numMeds;
	string *medications;

	~Patient() {
		if (medications)
			delete [] medications;
		medications = nullptr;
	}
};

// inputPatientData() prompts the user to enter information about a patient
// arguments: a pointer to a Patient struct
// returns: nothing
void inputPatientData(Patient *);

// displayPatientData() displays a patient's information
// arguments: a pointer to a Patient struct
// returns: nothing
void displayPatientData(Patient *);

// This program models patient intake at a hospital.
int main() {
	Patient *patients = new Patient[NUM_PATIENTS];

	for (int i = 0; i < NUM_PATIENTS; i++) {
		inputPatientData(&patients[i]);
	}

	for (int i = 0; i < NUM_PATIENTS; i++) {
		displayPatientData(&patients[i]);
	}

	delete [] patients;

	return 0;
}

void inputPatientData(Patient *p) {
	static int patientNum = 1;

	cout << "Enter the data for patient #" << patientNum << ":" << endl;
	cout << "First Name: ";
	cin >> p->firstName;
	cout << "Last Name: ";
	cin >> p->lastName;
	cout << "Age: ";
	cin >> p->age;
	cout << "Enter the number of medications the patient is currently taking: ";
	cin >> p->numMeds;
	// If the patient is currently taking medications, a dynamic array will be created to store the list of medications
	if (p->numMeds > 0) {
		p->medications = new string[p->numMeds];
		for (int i = 0; i < p->numMeds; i++) {
			cout << "Enter the name of medication #" << i + 1 << ": ";
			cin >> p->medications[i];
		}
	// If the patient is not taking any medications, the medications pointer is set to nullptr
	} else
		p->medications = nullptr;

	cout << "Patient #" << patientNum << " intake complete!" << endl << endl;
	patientNum++;
}

void displayPatientData(Patient *p) {
	static int patientNum = 1;
	cout << "Patient #" << patientNum << ":" << endl;
	cout << "Name: " << p->firstName << " " << p->lastName << endl;
	cout << "Age: " << p->age << endl;
	cout << "Medications: ";
	// If the patient is taking medications, this will display a comma separated list
	if (p->numMeds > 0) {
		for (int i = 0; i < p->numMeds; i++) {
			cout << p->medications[i];
			if (i < p->numMeds - 1)
				cout << ", ";
		}
	} else
		cout << "None";

	cout << endl << endl;
	patientNum++;
}
