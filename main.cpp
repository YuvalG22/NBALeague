#pragma warning(disable: 4996)
#include "league.h"
#include "LinkedList.h"
#include "general.h"
#include <string>
#include <iostream>
#include <limits>
#include <list>
#include <memory>
#include "PersonFactory.h"

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
void createTestEntities(League& l, District& d);

// Creators
Team* createTeam(std::list<Person*>& allWorkers, list<Owner*>& allOwners);
Match* createMatch(std::list<Team>& teams, std::list<Person*>& allWorkers);

enum eChoise { NEW_TEAM = 1, NEW_WORKER, NEW_MATCH, PRINT_TEAM, PRINT_WORKER, PRINT_MATCH, GO_BACK };
enum eChoiseInner { NEW_OWNER = 1, NEW_PLAYER, NEW_REFREE };

int main()
{
    League& l1 = League::getInstance();
    showLeagueMenu(l1);
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
    createTestEntities(l, d);
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
                Team* t = createTeam(l.getAllWorkers(), l.getAllOwners());
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
            for (const Team& team : d.getTeams())
                cout << team << endl;
            break;
        }

        case PRINT_WORKER:
        {
            for (Person* worker : l.getAllWorkers()) {
                if (Player* player = dynamic_cast<Player*>(worker)) {
                    std::cout << "Player name: " << player->getName() << ", Matches Played: " << player->getPlayerMatches() << std::endl;
                }
                else {
                    std::cout << *worker << std::endl;
                }
            }

            for (Owner* owner : l.getAllOwners()) {
                if (Player* player = dynamic_cast<Player*>(owner)) {
                    std::cout << "Player name: " << player->getName() << ", Matches Played: " << player->getPlayerMatches() << std::endl;
                }
                else {
                    std::cout << *owner << std::endl;
                }
            }

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
        std::unique_ptr<Person> person;
        switch (selection)
        {
        case NEW_OWNER:
        {
            person = PersonFactory::createPerson(PersonFactory::PersonType::OWNER);
            if (person) {
                Owner* o = dynamic_cast<Owner*>(person.release());
                l.addOwner(o);
            }
            break;
        }
        case NEW_PLAYER:
        {
            person = PersonFactory::createPerson(PersonFactory::PersonType::PLAYER);
            if (person) {
                Player* p = dynamic_cast<Player*>(person.release());
                l.addWorker(p);
            }
            break;
        }

        case NEW_REFREE:
        {
            person = PersonFactory::createPerson(PersonFactory::PersonType::REFEREE);
            if (person) {
                Refree* r = dynamic_cast<Refree*>(person.release());
                l.addWorker(r);
            }
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

Team* createTeam(list<Person*>& allWorkers, list<Owner*>& allOwners) {
    int selected = 0;
    int numOfSeats = 0;
    string teamName;
    Owner* o = nullptr;

    // Get the team name from the user
    cout << "Please enter team's name: ";
    cin.ignore();
    getline(cin, teamName);
    cout << endl;

    int index = 1;
    for (Owner* owner : allOwners) {
        cout << index++ << ") " << owner->getName() << endl;
    }
    do {
        selected = getIntWithPrompt("Please enter the number corresponding to the owner:") - 1;
        auto it = allOwners.begin();
        advance(it, selected);
        if (it != allOwners.end()) {
            o = *it;
        }
    } while (selected < 0 || selected >= allOwners.size());

    // Get the court name and number of seats
    string courtName;
    cout << "Please enter court's name: ";
    getline(cin, courtName);
    numOfSeats = getIntWithPrompt("Please enter court's number of seats:");
    cout << endl;

    // Collect all available players
    list<Player*> teamPlayers;
    for (Person* worker : allWorkers) {
        if (Player* p = dynamic_cast<Player*>(worker)) {
            teamPlayers.push_back(p);
        }
    }

    // Ask user to add players to the team
    int option;
    do {
        int playerIndex = 1;
        for (const Player* player : teamPlayers) {
            cout << playerIndex++ << ") " << player->getName() << endl;
        }
        selected = getIntWithPrompt("Please enter the number corresponding to the player:") - 1;

        // Add player to the team if selected
        if (selected >= 0 && selected < teamPlayers.size()) {
            auto it = teamPlayers.begin();
            advance(it, selected);
            // Do nothing if player is already in the team
        }

        option = getIntWithPrompt("Add more players? 1 - yes, 0 - no");
        cout << endl;
    } while (option != 0);

    // Create and return the new Team
    return new Team(teamName, *o, Court(courtName, numOfSeats), teamPlayers);
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
    do {
        homeScore = getIntWithPrompt("Choose home team score:");
        awayScore = getIntWithPrompt("Choose away team score:");
        if (homeScore == awayScore) {
            cout << "Scores cant be the same number!" << endl;
        }
    } while (homeScore == awayScore);

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
    int index = 1;
    for (Refree* ref : referees) {
        cout << index++ << ") " << ref->getName() << endl;
    }
    do {
        selected = getIntWithPrompt("Please enter the number corresponding to the referee:") - 1;
        auto it = referees.begin();
        std::advance(it, selected);
        if (it != referees.end()) {
            Refree* r = *it;

            // Set court
            Court c = homeTeam->getCourt();

            // Create match subject and attach observers
            MatchSubject match(*homeTeam, *awayTeam, *r);

    return nullptr;
}