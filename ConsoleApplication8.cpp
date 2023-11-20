#include <iostream>
#include <cstring>



class Person {
private:
    char* name;

public:
    Person() : name(nullptr) {}
    Person(const char* _name) {
        name = new char[strlen(_name) + 1];
        strcpy_s(name, strlen(_name) + 1, _name);
    }

    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
    }

    ~Person() {
        delete[] name;
    }

    const char* getName() const {
        return name;
    }
};

class Apartment {
private:
    Person* residents;
    int numResidents;

public:
    Apartment() : residents(nullptr), numResidents(0) {}
    Apartment(int _numResidents) : numResidents(_numResidents) {
        residents = new Person[numResidents];
    }

    Apartment(const Apartment& other) : numResidents(other.numResidents) {
        residents = new Person[numResidents];
        for (int i = 0; i < numResidents; ++i) {
            residents[i] = other.residents[i];
        }
    }

    ~Apartment() {
        delete[] residents;
    }

    const Person& getResident(int index) const {
        return residents[index];
    }
};

class House {
private:
    Apartment* apartments;
    int numApartments;

public:
    House(int _numApartments, int residentsPerApartment) : numApartments(_numApartments) {
        apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; ++i) {
            apartments[i] = Apartment(residentsPerApartment);
        }
    }

    House(const House& other) : numApartments(other.numApartments) {
        apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; ++i) {
            apartments[i] = other.apartments[i];
        }
    }

    ~House() {
        delete[] apartments;
    }

    const Apartment& getApartment(int index) const {
        return apartments[index];
    }
};

int main() {
    House myHouse(3, 2);

    House anotherHouse = myHouse;

    for (int i = 0; i < 2; ++i) {
        const Person& resident = myHouse.getApartment(0).getResident(i);
        std::cout << "Resident in Apartment 1, Person " << i + 1 << ": " << resident.getName() << std::endl;
    }

    return 0;
}
