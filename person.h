#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include "Date.h"
using namespace std;

class Person
{
	public:
		enum  eGenderType { MALE, FEMALE, OTHER, eNumOfTypes };
		static constexpr const char* genders[eNumOfTypes] = { "Male", "Female", "Other" };

		Person();
		Person(const int pid, const char* name, const Date dob, const eGenderType gender, const char* address);
		Person(const Person& other);
		Person(Person&& other);
		virtual ~Person();

		const int getPID() const { return person_id; }
		const char* getName() const { return name; }
		const Date getDOB() const { return dateOfBirth; }
		const eGenderType getGender() const { return gender; }
		const char* getAddress() const { return address; }

		void setPID(const int id);
		void setName(const char* name);
		void setDate(const Date& date);
		void setGender(const eGenderType gen);
		void setAddress(const char* address);

		Person& operator=(const Person& other);
		virtual void toOs(ostream& os) const = 0 {
			
		}
		friend ostream& operator<<(ostream& os, const Person& s);


	protected:
		int person_id;
		char* name;
		Date dateOfBirth;
		eGenderType gender;
		char* address;
};

#endif // __PERSON_H