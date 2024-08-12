#pragma warning(disable: 4996)
#include "league.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
#include <limits>
#include <list>

/*
* C++ project- NBA league
*/

// Statics
static constexpr int MAX_STR_LEN = 255;
static constexpr int EXIT = -1;
// Helpers
void showLeagueMenu(League& l);
void showDistrictMenu(League& l, District& d, const std::string& districtName);
void showNewWorkerMenu(League& l);
void printTeams(const std::list<Team>& teams);

// Creators

void createPerson(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address);
void createEmployee(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address, float* salary);
Owner* createOwner();
Player* createPlayer();
Refree* createRefree();
Team* createTeam(std::list<Person*>& allWorkers, Owner* owner);
Match* createMatch(std::list<Team>& teams, std::list<Person*>& allWorkers);



// General Read Functions
int getIntWithPrompt(const char* message);
int getIdWithPrompt(const char* message);
float getFloatWithPrompt(const char* message);
int getEnumSelection(const char* message, const char* const types[], const int numOfTypes);
std::string getStrExactName(const char* msg);
char* getDynStr(char* str);
char* myGets(char* buffer, int size, FILE* source);

enum eChoise { NEW_TEAM = 1, NEW_WORKER, NEW_MATCH, PRINT_TEAM, PRINT_WORKER, PRINT_MATCH, GO_BACK };
enum eChoiseInner { NEW_OWNER = 1, NEW_PLAYER, NEW_REFREE };

int main()
{
    League* l1 = new League();
    showLeagueMenu(*l1);
    delete l1; // Properly clean up
    return 0;
}

/* Helpers */

void showLeagueMenu(League& l)
{
    int choice;
    list<District>& districts = l.getDistricts();
    auto east = districts.begin();
    auto west = ++districts.begin();

    cout << "*** NBA League Creator ***" << endl;
    cout << "*** each NBA League has 2 districts (East, West) ***" << endl;
    do
    {
        cout << "Select district:" << endl;
        cout << "1) East" << endl;
        cout << "2) West" << endl;
        cout << "-1) Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            showDistrictMenu(l, *east, "East");
            break;
        }

        case 2:
        {
            showDistrictMenu(l, *west, "West");
            break;
        }

        case EXIT:
            break;

        default:
        {
            cout << "Invalid input, please enter the correct number" << endl;
            break;
        }
        }
    } while (choice != -1);
}

void showDistrictMenu(League& l, District& d, const std::string& districtName)
{
    int selection;
    cout << "*** NBA League Creator ***" << endl;
    cout << "*** Current District: " << districtName << " ***" << endl;
    do
    {
        cout << "1) Create a new Team" << endl;
        cout << "2) Create a new Worker (Owner | Refree | Player)" << endl;
        cout << "3) Create a new Match" << endl;
        cout << "4) Print Teams" << endl;
        cout << "5) Print Workers" << endl;
        cout << "6) Print Matches" << endl;
        cout << "-1) Back" << endl;
        cin >> selection;
        cout << "-----------------------------" << endl;

        switch (selection)
        {
        case NEW_TEAM:
        {
            cout << "*** Team Creation ***" << endl;
            if (l.getCurrentNumberOfOwners() == 0 || l.getCurrentNumberOfPlayers() == 0) {
                if (l.getCurrentNumberOfOwners() == 0) {
                    cout << "No owners available. Please create an owner before creating a team." << endl;
                }
                if (l.getCurrentNumberOfPlayers() == 0) {
                    cout << "No players available. Please create players before creating a team." << endl;
                }
                cout << endl;
                showDistrictMenu(l, d, districtName);
            }
            else {
                // Get the first owner
                Owner* owner = l.getAllOwners().front(); // Assuming getAllOwners() returns a list of Owner* 

                // Create the team using the first owner
                Team* t = createTeam(l.getAllWorkers(), owner);
                // Get the first owner
                d + *t;
                break;
            }
        }

        case NEW_WORKER:
        {
            showNewWorkerMenu(l);
            break;
        }

        case NEW_MATCH:
        {
            cout << "*** Match Creation ***" << endl;
            if (d.getNumOfTeams() < 2 || l.getCurrentNumberOfReferees() == 0) {
                if (d.getNumOfTeams() < 2) {
                    cout << "No teams available. Please create at least 2 teams before creating a match." << endl;
                }
                if (l.getCurrentNumberOfReferees() == 0) {
                    cout << "No referees available. Please create a referee before creating a match." << endl;
                }
                cout << endl;
                showDistrictMenu(l, d, districtName);
            }
            else {
                Match* m = createMatch(d.getTeams(), l.getAllWorkers());
                d + *m;
                break;
            }
        }

        case PRINT_TEAM:
        {
            const std::list<Team>& teams = d.getTeams();
            for (const auto& team : teams)
                cout << team << endl;
            break;
        }

        case PRINT_WORKER:
        {
            for (Person* worker : l.getAllWorkers())
                cout << *worker << endl;

            for (Owner* owner : l.getAllOwners())
                cout << *owner << endl;

            break;
        }

        case PRINT_MATCH:
        {
            LinkedList<Match>* matches = d.getMatches();
            Node<Match>* current = matches->getHead();
            while (current != nullptr) {
                cout << current->data << endl;
                current = current->next;
            }
            break;
        }

        case GO_BACK:
        {
            showLeagueMenu(l);
            break;
        }

        case EXIT:
            break;

        default:
        {
            cout << "Invalid input, please enter the correct number" << endl;
            break;
        }
        }
    } while (selection != -1);
}

void showNewWorkerMenu(League& l)
{
    int selection;
    cout << "*** Worker Creation ***" << endl;
    cout << "Enter kind of worker:" << endl;
    do
    {
        cout << "1) Owner" << endl;
        cout << "2) Player" << endl;
        cout << "3) Refree" << endl;
        cout << "-1) Exit" << endl;
        cin >> selection;
        switch (selection)
        {
        case NEW_OWNER:
        {
            Owner* o = createOwner();
            l.addOwner(o);
            break;
        }
        case NEW_PLAYER:
        {
            Player* p = createPlayer();
            l.addWorker(p);
            break;
        }

        case NEW_REFREE:
        {
            Refree* r = createRefree();
            l.addWorker(r);
            break;
        }

        case EXIT:
            break;

        default:
        {
            cout << "Invalid input, please enter the correct number" << endl;
            break;
        }
        }
    } while (selection < 1 || selection > 3);
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

void createEmployee(int* pid, std::string& name, Date* date, Person::eGenderType* gender, std::string& address, float* salary)
{
    createPerson(pid, name, date, gender, address);
    *salary = getFloatWithPrompt("Please enter salary:");
}

Owner* createOwner()
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

Player* createPlayer()
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

Refree* createRefree()
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


// Assume the relevant headers and other necessary code are already included.

Team* createTeam(std::list<Person*>& allWorkers, Owner* owner) {
    int selected = 0;
    int numOfSeats = 0;
    std::string teamName;

    // Get the team name from the user
    std::cout << "Please enter team's name: ";
    std::cin.ignore();
    std::getline(std::cin, teamName);

    // Get the court name and number of seats
    std::string courtName;
    std::cout << "Please enter court's name: ";
    std::getline(std::cin, courtName);
    numOfSeats = getIntWithPrompt("Please enter court's number of seats:");
    std::cout << std::endl;

    // Collect all available players
    std::list<Player> teamPlayers;
    for (Person* worker : allWorkers) {
        if (Player* p = dynamic_cast<Player*>(worker)) {
            teamPlayers.push_back(*p);
        }
    }

    // Ask user to add players to the team
    int option;
    do {
        int playerIndex = 1;
        for (const Player& player : teamPlayers) {
            std::cout << playerIndex++ << ") " << player.getName() << std::endl;
        }
        selected = getIntWithPrompt("Please enter the number corresponding to the player:") - 1;

        // Add player to the team if selected
        if (selected >= 0 && selected < teamPlayers.size()) {
            auto it = teamPlayers.begin();
            std::advance(it, selected);
            // Do nothing if player is already in the team
        }

        option = getIntWithPrompt("Add more players? 1 - yes, 0 - no");
        std::cout << std::endl;
    } while (option != 0);

    // Create and return the new Team
    return new Team(teamName, *owner, Court(courtName, numOfSeats), teamPlayers);
}


Match* createMatch(std::list<Team>& teams, std::list<Person*>& allWorkers)
{
    int selected = 0;
    Team* homeTeam = nullptr;
    Team* awayTeam = nullptr;
    int homeScore;
    int awayScore;
    int day, month, year;
    int numOfReferees = 0;

    // Set match teams
    cout << "Select 2 teams from the list below:" << endl;
    do {
        int i = 1;
        for (auto& team : teams) {
            cout << i++ << ") " << team.getName() << endl;
        }
        selected = getIntWithPrompt("Please choose the home team:") - 1;
        auto it = teams.begin();
        std::advance(it, selected);
        if (it != teams.end()) {
            homeTeam = &(*it);
        }
        cout << endl;
    } while (homeTeam == nullptr);

    do {
        int i = 1;
        for (auto& team : teams) {
            cout << i++ << ") " << team.getName() << endl;
        }
        selected = getIntWithPrompt("Please choose the away team:") - 1;
        auto it = teams.begin();
        std::advance(it, selected);
        if (it != teams.end()) {
            awayTeam = &(*it);
        }
        if (awayTeam == homeTeam) {
            cout << "The away team cannot be the same as the home team. Please choose a different team." << endl;
            awayTeam = nullptr;
        }
        cout << endl;
    } while (awayTeam == nullptr);

    // Set match score
    homeScore = getIntWithPrompt("Choose home team score:");
    awayScore = getIntWithPrompt("Choose away team score:");

    // Set match date
    cout << "Choose the date of the match:" << endl;
    day = getIntWithPrompt("Please enter day");
    month = getIntWithPrompt("Please enter month");
    year = getIntWithPrompt("Please enter year");
    Date date(day, month, year);

    // Collect all available referees
    std::list<Refree*> referees;
    for (Person* worker : allWorkers) {
        if (Refree* r = dynamic_cast<Refree*>(worker)) {
            referees.push_back(r);
        }
    }

    // Set referee
    cout << "Select a referee from the list below:" << endl;
    for (Refree* ref : referees) {
        cout << ref->getName() << endl;
    }
    do {
        selected = getIntWithPrompt("Please enter the number corresponding to the referee:") - 1;
        auto it = referees.begin();
        std::advance(it, selected);
        if (it != referees.end()) {
            Refree* r = *it;

            // Set court
            Court c = homeTeam->getCourt();

            // Set match
            return new Match(*r, *homeTeam, *awayTeam, homeScore, awayScore, c, date);
        }
    } while (selected < 0 || selected >= referees.size());

    return nullptr;
}

//General Functions
int getIntWithPrompt(const char* message)
{
    int num;
    while (true) {
        cout << message << endl;
        cin >> num;

        // Check if the input is an integer
        if (cin.fail()) {
            // If not, clear the error flag
            cin.clear();
            // Ignore the rest of the input until a newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
        }
        else {
            // Valid input, consume the newline character and return the number
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

int getIdWithPrompt(const char* message)
{
    char input[10];  // One extra space for the null-terminator
    bool valid = false;

    while (!valid) {
        cout << message << endl;
        cin.clear();
        cin >> input;

        // Check if the input has exactly 9 digits and consists only of digits
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
            cout << "Invalid input. Please enter a 9-digit number." << endl;
        }
    }

    return atoi(input);  // Convert the valid 9-digit string to an integer
}

float getFloatWithPrompt(const char* message)
{
    float num;
    while (true) {
        cout << message << endl;
        cin >> num;

        // Check if the input is a float
        if (cin.fail()) {
            // If not, clear the error flag
            cin.clear();
            // Ignore the rest of the input until a newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a float." << endl;
        }
        else {
            // Valid input, consume the newline character and return the number
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

int getEnumSelection(const char* message, const char* const types[], const int numOfTypes)
{
    int enumChoice;
    do
    {
        cout << message << endl;
        for (int i = 0; i < numOfTypes; ++i)
        {
            cout << i + 1 << ") " << types[i] << endl;
        }
        cin >> enumChoice;
    } while (enumChoice < 1 || enumChoice > numOfTypes);

    return enumChoice - 1;  // Adjust to zero-based index
}

std::string getStrExactName(const char* msg)
{
    std::string str;
    cout << msg << "\t";
    getline(cin, str);
    return str;
}

char* myGets(char* buffer, int size, FILE* source)
{
    char* ok;
    if (buffer != NULL && size > 0)
    {
        do { //skip only '\n' strings
            ok = fgets(buffer, size, source);
        } while (ok && ((strlen(buffer) <= 1) || (isspace(buffer[0]))));
        if (ok)
        {
            char* back = buffer + strlen(buffer);
            //trim end spaces
            while ((buffer < back) && (isspace(*--back)));
            *(back + 1) = '\0';
            return buffer;
        }
        buffer[0] = '\0';
    }
    return NULL;
}
