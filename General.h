#pragma once
#ifndef __GENERAL_H
#define __GENERAL_H

#include <iostream>
#include <string>
#include "date.h"
#include "person.h"

// Function declarations
void createEmployee(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address, float* salary);
int getIntWithPrompt(const char* message);
int getIdWithPrompt(const char* message);
float getFloatWithPrompt(const char* message);
int getEnumSelection(const char* message, const char* const types[], const int numOfTypes);
std::string getStrExactName(const char* msg);
char* myGets(char* buffer, int size, FILE* source);
void createPerson(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address);

#endif // __GENERAL_H
