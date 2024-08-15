#include <memory>
#include "person.h"
#include "player.h"
#include "owner.h"
#include "refree.h"
#include "GeneralFunctions.h"

class PersonFactory {
public:
    enum class PersonType { PLAYER, REFEREE, OWNER };

    static std::unique_ptr<Person> createPerson(PersonType type) {
        switch (type) {
        case PersonType::PLAYER:
            return std::unique_ptr<Person>(createPlayer());
        case PersonType::REFEREE:
            return std::unique_ptr<Person>(createRefree());
        case PersonType::OWNER:
            return std::unique_ptr<Person>(createOwner());
        default:
            return nullptr;
        }
    }

    static void createPerson(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address)
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

    static void createEmployee(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address, float* salary)
    {
        createPerson(pid, name, date, gender, address);
        *salary = getFloatWithPrompt("Please enter salary:");
    }

    static Owner* createOwner()
    {
        float budget;
        int pid;
        std::string name, address;
        Person::eGenderType gender;
        Date* date = new Date();

        createPerson(&pid, name, date, &gender, address);
        budget = getFloatWithPrompt("Please enter budget:");
        return new Owner(pid, name, *date, gender, address, budget);
    }

    static Player* createPlayer()
    {
        Owner* o;
        float salary;
        int selection, playerNumber, numOfTitles, numOfMatches;
        Player::ePositionType position;

        playerNumber = getIntWithPrompt("Please enter player's number:");
        position = static_cast<Player::ePositionType>(getEnumSelection("Please choose player's position:", Player::positionNames, Player::eNumOfTypes));
        numOfTitles = getIntWithPrompt("Please enter player's number of titles:");
        numOfMatches = getIntWithPrompt("Please enter player's number of games:");
        cout << "Is the player an owner? (1: Yes, 2: No)" << endl;
        cin >> selection;
        if (selection % 2 == 1) //Player is an owner
        {
            o = createOwner();
            salary = getFloatWithPrompt("Please enter salary:");
            return new Player(Employee(o->getPID(), o->getName(), o->getDOB(), o->getGender(), o->getAddress(), salary), *o, playerNumber, position, numOfTitles, numOfMatches, true);
        }
        else //Player is a new employee
        {
            int pid;
            std::string name, address;
            Person::eGenderType gender;
            Date* date = new Date();
            createEmployee(&pid, name, date, &gender, address, &salary);
            return new Player(Employee(pid, name, *date, gender, address, salary), playerNumber, position, numOfTitles, numOfMatches, false);
        }
    }

    static Refree* createRefree()
    {
        int pid, numOfMatches;
        float rank, salary;
        std::string name, address;
        Person::eGenderType gender;
        Date* date = new Date();
        createEmployee(&pid, name, date, &gender, address, &salary);
        rank = getFloatWithPrompt("Please enter rank:");
        numOfMatches = getIntWithPrompt("Please enter number of matches:");
        return new Refree(Employee(pid, name, *date, gender, address, salary), rank, numOfMatches);
    }
};