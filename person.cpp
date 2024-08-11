#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "person.h"

Person::Person() : person_id(0), name(nullptr), dateOfBirth(Date()), gender(MALE), address(nullptr) {
    
}

Person::Person(const int pid, const char* name, const Date dob, const eGenderType gender, const char* address)
    : person_id(pid), dateOfBirth(dob), gender(gender) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

Person::Person(const Person& other)
    : person_id(other.person_id), dateOfBirth(other.dateOfBirth), gender(other.gender) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->address = new char[strlen(other.address) + 1];
    strcpy(this->address, other.address);
}

Person::Person(Person&& other)
    : person_id(other.person_id), name(other.name), dateOfBirth(other.dateOfBirth),
    gender(other.gender), address(other.address) {
    other.name = nullptr;
    other.address = nullptr;
}

Person::~Person() {
    delete[] name;
    delete[] address;
}

void Person::setPID(const int id) {
    person_id = id;
}

void Person::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Person::setDate(const Date& date) {
    dateOfBirth = date;
}

void Person::setGender(const eGenderType gen) {
    gender = gen;
}

void Person::setAddress(const char* address) {
    delete[] this->address;
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] name;
        delete[] address;

        person_id = other.person_id;
        dateOfBirth = other.dateOfBirth;
        gender = other.gender;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
    }
    return *this;
}

ostream& operator<<(std::ostream& os, const Person& s) {
    const char* name = typeid(s).name();
    os << "Name: " << s.name << endl;
    os << "Date of Birth: " << s.dateOfBirth << endl;
    os << "Gender: " << s.genders[s.getGender()] << endl;
    os << "Role: " << name + 6 << endl;
    os << "\n";
    s.toOs(os);
    return os;
}