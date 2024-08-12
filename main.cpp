#pragma warning(disable: 4996)
#include "league.h"

/*
* C++ project- NBA league
*/

// Statics
static constexpr int MAX_STR_LEN = 255;
static constexpr int EXIT = -1;
// Helpers
void showLeagueMenu(League& l);
void showDistrictMenu(League& l, District* d, const char* districtName);
void showNewWorkerMenu(League& l);
void printTeams(const Team* teams);

// Creators

void createPerson(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address);
void createEmployee(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address, float* salary);
Owner* createOwner();
Player* createPlayer();
Refree* createRefree();
Team* createTeam(Person** allPlayers, const int numberOfPlayers, Owner** allOwners, const int numberOfOwners);
Match* createMatch(Team* teams, int numOfTeams, Person** allWorkers, const int numberOfWorkers);



// General Read Functions
int getIntWithPrompt(const char* message);
int getIdWithPrompt(const char* message);
float getFloatWithPrompt(const char* message);
int getEnumSelection(const char* message, const char* const types[], const int numOfTypes);
char* getStrExactName(const char* msg);
char* getDynStr(char* str);
char* myGets(char* buffer, int size, FILE* source);

enum eChoise { NEW_TEAM = 1, NEW_WORKER, NEW_MATCH, PRINT_TEAM, PRINT_WORKER, PRINT_MATCH, GO_BACK };
enum eChoiseInner { NEW_OWNER = 1, NEW_PLAYER, NEW_REFREE };


int main()
{
	League* l1 = new League();
	showLeagueMenu(*l1);
	return 0;
}

/* Helpers */

void showLeagueMenu(League& l)
{
	int choise;
	District* east = l.getDistricts()[0];
	District* west = l.getDistricts()[1];
	cout << "*** NBA League Creator ***" << endl;
	cout << "*** each NBA League has 2 districts (East, West) ***" << endl;
	do
	{
		cout << "Select district:" << endl;
		cout << "1) East" << endl;
		cout << "2) West" << endl;
		cout << "-1) Exit" << endl;
		cin >> choise;

		switch (choise)
		{
		case (District::EAST + 1):
		{
			showDistrictMenu(l, east, "East");
			break;
		}

		case District::WEST + 1:
		{
			showDistrictMenu(l, west, "West");
			break;
		}

		case EXIT:
			break;

		default:
		{
			cout << "Invalid input ,please enter the correct number" << endl;
			break;
		}
		}
	} while (choise != -1);
}

void showDistrictMenu(League& l, District* d, const char* districtName)
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
					cout << "No owners available. Please create owner before creating a team." << endl;
				}
				if (l.getCurrentNumberOfPlayers() == 0) {
					cout << "No players available. Please create players before creating a team." << endl;
				}
				cout << endl;
				cout << endl;
				showDistrictMenu(l, d, districtName);
			}
			else {
				Team* t = createTeam(l.getAllWorkers(), l.getCurrentNumberOfWorkers(), l.getAllOwners(), l.getCurrentNumberOfOwners());
				*d + *t;
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
			if ((*d).getNumOfTeams() < 2 || l.getCurrentNumberOfReferees() == 0) {
				if ((*d).getNumOfTeams() < 2) {
					cout << "No teams available. Please create at least 2 teams before creating a match." << endl;
				}
				if (l.getCurrentNumberOfReferees() == 0) {
					cout << "No referees available. Please create a referee before creating a match." << endl;
				}
				cout << endl;
				cout << endl;
				showDistrictMenu(l, d, districtName);
			}
			else {
				Match* m = createMatch((*d).getTeams(), (*d).getNumOfTeams(), l.getAllWorkers(), l.getCurrentNumberOfWorkers());
				*d + *m;
				break;
			}
		}

		case PRINT_TEAM:
		{
			const Team* teams = (*d).getTeams();
			for (int i = 0; i < (*d).getNumOfTeams(); i++)
				cout << (teams[i]) << endl;
			break;
		}

		case PRINT_WORKER:
		{
			Person** workers = l.getAllWorkers();
			for (int i = 0; i < l.getCurrentNumberOfWorkers(); i++)
				cout << *(workers[i]) << endl;

			Owner** owners = l.getAllOwners();
			for (int i = 0; i < l.getCurrentNumberOfOwners(); i++)
				cout << *(owners[i]) << endl;

			break;
		}

		case PRINT_MATCH:
		{
			const Match* matches = (*d).getMatches();
			for (int i = 0; i < (*d).getNumOfMatches(); i++)
				cout << matches[i] << endl;
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
			cout << "Invalid input ,please enter the correct number" << endl;
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
			cout << "Invalid input ,please enter the correct number" << endl;
			break;
		}
		}
	} while (selection < 1 || selection > 3);
}


void createPerson(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address)
{
	int day, month, year;
	*pid = getIdWithPrompt("Please enter person ID:");
	cout << "Please enter person name" << endl;
	cin.getline(name, MAX_STR_LEN);
	cout << "Date of Birth" << endl;
	day = getIntWithPrompt("Please enter day");
	month = getIntWithPrompt("Please enter month");
	year = getIntWithPrompt("Please enter year");
	*date = Date(day, month, year);
	*gender = static_cast<Person::eGenderType>(getEnumSelection("Please choose gender:", Person::genders, Person::eNumOfTypes));
	getchar();
	cout << "Please enter person address" << endl;
	cin.getline(address, MAX_STR_LEN);
}

void createEmployee(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address, float* salary)
{
	createPerson(pid, name, date, gender, address);
	*salary = getFloatWithPrompt("Please enter salary:");
}

Owner* createOwner()
{
	float budget;
	int pid;
	char name[MAX_STR_LEN], address[MAX_STR_LEN];
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
	if (selection % 2 == 1)		//Player is an owner
	{
		o = createOwner();
		salary = getFloatWithPrompt("Please enter salary:");
		return new Player(Employee(o->getPID(), o->getName(), o->getDOB(), o->getGender(), o->getAddress(), salary), *o, playerNumber, position, numOfTitles, numOfMatches, true);
	}
	else						//Player is a new employee
	{
		int pid;
		char name[MAX_STR_LEN], address[MAX_STR_LEN];
		Person::eGenderType gender;
		Date* date = new Date();
		createEmployee(&pid, name, date, &gender, address, &salary);
		return new Player(Employee(pid,name,*date,gender,address,salary), playerNumber, position, numOfTitles, numOfMatches, false);
	}
}

Refree* createRefree()
{
	int pid, numOfMatches;
	float rank, salary;
	char name[MAX_STR_LEN], address[MAX_STR_LEN];
	Person::eGenderType gender;
	Date* date = new Date();
	createEmployee(&pid, name, date, &gender, address, &salary);
	rank = getFloatWithPrompt("Please enter rank:");
	numOfMatches = getIntWithPrompt("Please enter number of matches:");
	return new Refree(Employee(pid,name,*date,gender,address,salary), rank, numOfMatches);
}

#include <iostream>
#include "league.h"
#include "team.h"

Team* createTeam(Person** allWorkers, const int numberOfWorkers, Owner** allOwners, const int numberOfOwners) {
	int numOfPlayers = 0;
	int numOfTeamPlayers = 0;
	int selected = 0;
	int numOfSeats = 0;
	char teamName[MAX_STR_LEN];
	cout << "Please enter team's name: ";
	cin.ignore();
	cin.getline(teamName, MAX_STR_LEN);

	// List all available owners
	cout << "Select an owner from the list below:" << endl;
	for (int i = 0; i < numberOfOwners; i++) {
		cout << i + 1 << ") " << allOwners[i]->getName() << endl;
	}
	do {
		selected = getIntWithPrompt("Please enter the number corresponding to the owner:") - 1;
	} while (selected < 0 || selected >= numberOfOwners);
	Owner o = *allOwners[selected];

	// Set court
	char courtName[MAX_STR_LEN];
	cout << "Please enter court's name: ";
	cin.getline(courtName, MAX_STR_LEN);
	numOfSeats = getIntWithPrompt("Please enter court's number of seats:");
	cout << endl;

	// Collect all available players
	for (int i = 0; i < numberOfWorkers; i++) {
		if (Player* p = dynamic_cast<Player*>(allWorkers[i])) {
			numOfPlayers++;
		}
	}
	Player** players = new Player * [numOfPlayers];
	int playerIndex = 0;
	for (int i = 0; i < numberOfWorkers; i++) {
		if (Player* p = dynamic_cast<Player*>(allWorkers[i])) {
			players[playerIndex++] = p;
		}
	}

	//Add players to team
	int option;
	int selectedPlayer;
	Player** teamPlayers = new Player * [numOfPlayers];
	cout << "Please add players to the team" << endl;
	do {
		for (int i = 0; i < numOfPlayers; i++) {
			cout << i + 1 << ") " << players[i]->getName() << endl;
		}
		selected = getIntWithPrompt("Please enter the number corresponding to the player:") - 1;
		if (selected >= 0 && selected < numOfPlayers) {
			bool isPicked = false;
			for (int i = 0; i < numOfTeamPlayers; ++i) {
				if (teamPlayers[i] == players[selected]) {
					isPicked = true;
					break;
				}
			}
			if (!isPicked) {
				teamPlayers[numOfTeamPlayers++] = players[selected];
			}
			else {
				cout << "Player already selected. Please choose another player." << endl;
			}
		}
		option = getIntWithPrompt("Add more players? 1 - yes, 0 - no");
		cout << endl;
	} while (option != 0);
	
	Team* newTeam = new Team(teamName, o, Court(courtName, numOfSeats), teamPlayers, numOfTeamPlayers);
	delete[] players;
	delete[] teamPlayers;
	return newTeam;
}


Match* createMatch(Team* teams, int numOfTeams, Person** allWorkers, const int numberOfWorkers)
{
	int selected = 0;
	Team* homeTeam = nullptr;
	Team* awayTeam = nullptr;
	int homeScore;
	int awayScore;
	int day, month, year;
	int numOfReferees = 0;

	//Set match teams
	cout << "Select 2 teams from the list below:" << endl;
	do {
		for (int i = 0; i < numOfTeams; i++) {
			cout << i + 1 << ") " << teams[i].getName() << endl;
		}
		selected = getIntWithPrompt("Please choose the home team:") - 1;
		if (selected >= 0 && selected < numOfTeams) {
			homeTeam = &teams[selected];
		}
		cout << endl;
	} while (homeTeam == nullptr);
	do {
		for (int i = 0; i < numOfTeams; i++) {
			cout << i + 1 << ") " << teams[i].getName() << endl;
		}
		selected = getIntWithPrompt("Please choose the away team:") - 1;
		if (selected >= 0 && selected < numOfTeams) {
			awayTeam = &teams[selected];
		}
		if (awayTeam == homeTeam) {
			cout << "The away team cannot be the same as the home team. Please choose a different team." << endl;
			awayTeam = nullptr;
		}
		cout << endl;
	} while (awayTeam == nullptr);

	//Set match score
	homeScore = getIntWithPrompt("Choose home team score:");
	awayScore = getIntWithPrompt("Choose away team score:");

	//Set match date
	cout << "Choose the date of the match:" << endl;
	day = getIntWithPrompt("Please enter day");
	month = getIntWithPrompt("Please enter month");
	year = getIntWithPrompt("Please enter year");
	Date date(day, month, year);

	// Collect all available referees
	for (int i = 0; i < numberOfWorkers; i++) {
		if (Refree* r = dynamic_cast<Refree*>(allWorkers[i])) {
			numOfReferees++;
		}
	}
	Refree** referees = new Refree * [numOfReferees];
	int refIndex = 0;
	for (int i = 0; i < numberOfWorkers; i++) {
		if (Refree* r = dynamic_cast<Refree*>(allWorkers[i])) {
			referees[refIndex++] = r;
		}
	}

	//Set referee
	cout << "Select a referee from the list below:" << endl;
	for (int i = 0; i < numOfReferees; i++) {
		cout << i + 1 << ") " << referees[i]->getName() << endl;
	}
	do {
		selected = getIntWithPrompt("Please enter the number corresponding to the referee:") - 1;
	} while (selected < 0 || selected >= numOfReferees);
	Refree* r = referees[selected];

	//Set court
	Court c = homeTeam->getCourt();

	//Set match
	Match* newMatch = new Match(*r, *homeTeam, *awayTeam, homeScore, awayScore, c, date);

	return newMatch;
}

void printTeams(const Team* teams)
{
	cout <<  "All teams : " << endl;
	for (int i = 0; i < District::NUMBER_OF_TEAMS; i++)
		cout << i+1 << ". " << teams[i] << endl;
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

		// Check if the input is an float
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

/*int getEnumSelection(const char* message, const char* const types[], const int numOfTypes)
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
}*/

char* getStrExactName(const char* msg)
{
	char* str;
	char temp[MAX_STR_LEN];
	printf("%s\t", msg);
	myGets(temp, MAX_STR_LEN, stdin);
	str = getDynStr(temp);
	return str;
}

char* getDynStr(char* str)
{
	char* theStr;
	theStr = new char((strlen(str) + 1));
	if (!theStr)
		return NULL;

	strcpy(theStr, str);
	return theStr;
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