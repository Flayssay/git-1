#include <iostream>
#include <string>
using namespace std;

class Horse {
protected:
    string sex;
    string breed;
    int age;

public:
    void OutInformation() {
        cout << "Sex: " << sex << endl;
        cout << "Breed: " << breed << endl;
        cout << "Age: " << age << endl;
    }

    void SetSex(string newSex) {
        sex = newSex;
    }

    void SetBreed(string newBreed) {
        breed = newBreed;
    }

    void SetAge(int newAge) {
        age = newAge;
    }

    Horse() {
        sex = "Unknown";
        breed = "Unknown";
        age = 0;
    }
};

class Race : public Horse {
private:
    int Num;
    string Track;
    float Time;
    string Location; 

public:
    void SetNum(int newNum) {
        Num = newNum;
    }

    void SetTrack(string newTrack) {
        Track = newTrack;
    }

    void SetTime(float newTime) {
        Time = newTime;
    }

    void SetLocation(string newLocation) {
        Location = newLocation;
    }

    void InfoRace() {
        OutInformation();
        cout << "Num: " << Num << endl;
        cout << "Track: " << Track << endl;
        cout << "Time: " << Time << endl;
        cout << "Location: " << Location << endl; 
    }
};


int main() {
    Race One;
    string sex, breed, Track, Location; 
    int age, num;
    float time;
    cout << "Enter sex: ";
    cin >> sex;
    One.SetSex(sex);

    cout << "Enter breed: ";
    cin >> breed;
    One.SetBreed(breed);

    cout << "Enter age: ";
    cin >> age;
    One.SetAge(age);

    cout << "Enter num: ";
    cin >> num;
    One.SetNum(num);

    cout << "Enter track: ";
    cin >> Track;
    One.SetTrack(Track);

    cout << "Enter time: ";
    cin >> time;
    One.SetTime(time);

    cout << "Enter location: "; 
    cin >> Location;
    One.SetLocation(Location);

    One.InfoRace();

    return 0;
}
