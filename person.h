#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Person
{
	public:
		enum  eGenderType { MALE, FEMALE, OTHER, eNumOfTypes };
		static constexpr const char* genders[eNumOfTypes] = { "Male", "Female", "Other" };
		static constexpr int MAX_STR_LEN = 255;

		Person();
		Person(const int pid, const string& name, const Date dob, const eGenderType gender, const string& address);
		Person(const Person& other);
		Person(Person&& other);
		virtual ~Person();

		const int getPID() const { return person_id; }
		const string& getName() const { return name; }
		const Date getDOB() const { return dateOfBirth; }
		const eGenderType getGender() const { return gender; }
		const string& getAddress() const { return address; }

		void setPID(const int id);
		void setName(const string& name);
		void setDate(const Date& date);
		void setGender(const eGenderType gen);
		void setAddress(const string& address);

		Person& operator=(const Person& other);
		virtual void toOs(ostream& os) const = 0 {
			
		}
		friend ostream& operator<<(ostream& os, const Person& s);


	protected:
		int person_id;
		string name;
		Date dateOfBirth;
		eGenderType gender;
		string address;
};

#endif // __PERSON_H