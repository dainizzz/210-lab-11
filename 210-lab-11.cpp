// COMSC-210 | Lab 11 | Dainiz Almazan
// IDE used: CLion

#include <iostream>
using namespace std;

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

/*
Write a program that features a simple dynamic array of structs. The struct definition should itself include a dynamic
array as well as other member variables.
Choose a real-world scenario that would be able to be modeled by these requirements (keep it simple) and code it.
Keep it simple. Here's an example (and no, you can't use it): my application keeps track of people who come to my
booksigning. I have a struct to represent a fan. There will be a variable number of these struct objects since the
number of attendees could vary. I ask each attendee for their phone number. That'll be a member variable. I ask each
attendee for their favorite books of mine. They may have zero, one, two, or more of these favorite books. I can store
that in a dynamic array within the struct.
Heavily comment your code in your own words to explain what you're coding.
Craft your output to fully exercise your code.
*/

int main(){
    return 0;
}
