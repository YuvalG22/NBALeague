#include "general.h"
#include <iostream>
#include <limits>
#include <cstring>
#include <cctype>

void createEmployee(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address, float* salary)
{
    createPerson(pid, name, date, gender, address);
    *salary = getFloatWithPrompt("Please enter salary:");
}

void createPerson(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address)
{
    int day, month, year;
    *pid = getIdWithPrompt("Please enter person ID:");
    getchar();
    cout << "Please enter person name" << endl;
    getline(cin, name);
    cout << "Date of Birth" << endl;
    day = getIntWithPrompt("Please enter day");
    month = getIntWithPrompt("Please enter month");
    year = getIntWithPrompt("Please enter year");
    *date = Date(day, month, year);
    *gender = static_cast<Person::eGenderType>(getEnumSelection("Please choose gender:", Person::genders, Person::eNumOfTypes));
    getchar();
    cout << "Please enter person address" << endl;
    getline(cin, address);
}

int getIntWithPrompt(const char* message)
{
    int num;
    while (true) {
        std::cout << message << std::endl;
        std::cin >> num;

        // Check if the input is an integer
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return num;
        }
    }
}

int getIdWithPrompt(const char* message)
{
    char input[10];  // One extra space for the null-terminator
    bool valid = false;

    while (!valid) {
        std::cout << message << std::endl;
        std::cin.clear();
        std::cin >> input;

        int length = 0;
        valid = true;
        for (int i = 0; input[i] != '\0'; ++i) {
            if (!isdigit(input[i])) {
                valid = false;
                break;
            }
            length++;
        }

        if (length != 9) {
            valid = false;
        }

        if (!valid) {
            std::cout << "Invalid input. Please enter a 9-digit number." << std::endl;
        }
    }

   // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return atoi(input);  // Convert the valid 9-digit string to an integer
}

float getFloatWithPrompt(const char* message)
{
    float num;
    while (true) {
        std::cout << message << std::endl;
        std::cin >> num;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a float." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return num;
        }
    }
}

int getEnumSelection(const char* message, const char* const types[], const int numOfTypes)
{
    int enumChoice;
    do
    {
        std::cout << message << std::endl;
        for (int i = 0; i < numOfTypes; ++i)
        {
            std::cout << i + 1 << ") " << types[i] << std::endl;
        }
        std::cin >> enumChoice;
    } while (enumChoice < 1 || enumChoice > numOfTypes);
   // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    return enumChoice - 1;  // Adjust to zero-based index
}

std::string getStrExactName(const char* msg)
{
    std::string str;
    std::cout << msg << "\t";
    std::getline(std::cin, str);
    return str;
}

char* myGets(char* buffer, int size, FILE* source)
{
    char* ok;
    if (buffer != NULL && size > 0)
    {
        do {
            ok = fgets(buffer, size, source);
        } while (ok && ((std::strlen(buffer) <= 1) || (isspace(buffer[0]))));
        if (ok)
        {
            char* back = buffer + std::strlen(buffer);
            while ((buffer < back) && (isspace(*--back)));
            *(back + 1) = '\0';
            return buffer;
        }
        buffer[0] = '\0';
    }
    return NULL;
}
