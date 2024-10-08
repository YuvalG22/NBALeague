#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "person.h"


Person::Person() : person_id(0), name("nullptr"), dateOfBirth(Date()), gender(MALE), address(nullptr) {
    
}

Person::Person(const int pid, const std::string& name, const Date dob, const eGenderType gender, const std::string& address)
    : person_id(pid), name(name), dateOfBirth(dob), gender(gender), address(address) {}

void Person::setPID(const int id) {
    person_id = id;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setDate(const Date& date) {
    dateOfBirth = date;
}

void Person::setGender(const eGenderType gen) {
    gender = gen;
}

void Person::setAddress(const std::string& address) {
    this->address = address;
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