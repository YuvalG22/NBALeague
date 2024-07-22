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
void showDistrictMenu(League& l, District& d);
void showNewWorkerMenu(League& l);
void printTeams(const Team* teams);

// Creators

void createPerson(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address);
void createEmployee(int* pid, char* name, Date* date, Person::eGenderType* gender, char* address, float* salary);
Owner* createOwner();
Player* createPlayer();
Refree* createRefree();
Team* createTeam(Person** allPlayers, const int numberOfPlayers, Owner** allOwners, const int numberOfOwners);
Match* createMatch(const Team* teams, int numOfTeams );



// General Read Functions
int getIntWithPrompt(const char* message);
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
	District* d = l.getDistricts();
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
			showDistrictMenu(l, d[District::EAST]);
			break;
		}

		case District::WEST + 1:
		{
			showDistrictMenu(l, d[District::WEST]);
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


void showDistrictMenu(League& l, District& d)
{
	int selection;
	cout << "*** NBA League Creator ***" << endl;
	cout << "*** each NBA League has 2 districts (East, West) ***" << endl;
	do
	{
		cout << "1) Create a new Team" << endl;
		cout << "2) Create a new Worker (Owner | Refree | Player)" << endl;
		cout << "3) Create a new Match" << endl;
		cout << "4) Print Team" << endl;
		cout << "5) Print Worker" << endl;
		cout << "6) Print Match" << endl;
		cout << "7) Go back to choose district" << endl;
		cout << "-1) Exit" << endl;
		cin >> selection;

		switch (selection)
		{
		case NEW_TEAM:
		{
			cout << "*** Team Creation ***" << endl;
			Team* t = createTeam(l.getAllWorkers(), l.getCurrentNumberOfWorkers(), l.getAllOwners(), l.getCurrentNumberOfWorkers());
			d + *t;
			break;
		}

		case NEW_WORKER:
		{
			showNewWorkerMenu(l);
			break;
		}

		case NEW_MATCH:
		{
			cout << "*** Match Creation ***" << endl;
			createMatch(d.getTeams(), d.NUMBER_OF_TEAMS);
			break;
		}

		case PRINT_TEAM:
		{
			printTeams(d.getTeams());
			break;
		}

		case PRINT_WORKER:
		{
			Person** workers = l.getAllWorkers();
			for (int i = 0; i < l.getCurrentNumberOfWorkers(); i++)
				cout << *(workers[i]) << endl;
			break;
		}

		case PRINT_MATCH:
		{
			const Match* matches = d.getMatches();
			for (int i = 0; i < District::NUMBER_OF_GAMES_SEASON; i++)
				cout << matches[i];
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
	*pid = getIntWithPrompt("Please enter person ID:");
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

Team* createTeam(Person** allPlayers, const int numberOfPlayers, Owner** allOwners, const int numberOfOwners)
{
	/* To do */
	int selected = 0, numOfSeats;
	char teamName[MAX_STR_LEN];
	cout << "Please enter team's name" << endl;
	cin.getline(teamName, MAX_STR_LEN);
	for (int i = 0; i < numberOfOwners; i++) // Iterate over owners and select owner
	{
		const Owner* owner = allOwners[i];
	}
	Owner o = *allOwners[selected];
	char courtName[MAX_STR_LEN];
	cout << "Please enter court's name" << endl;
	cin.getline(courtName, MAX_STR_LEN);
	numOfSeats = getIntWithPrompt("Please enter court's number of seats");
	// Need to add Players to team
	return new Team(teamName, o, Court(courtName, numOfSeats));
}

Match* createMatch(const Team* teams, int numOfTeams)
{
	//Refree* ref;
	//Date* date;
	Team* teamA, * teamB;
	int resultA, resultB, result, choise;
	printTeams(teams);
	for (int i = 0; i < 2; i++)
	{
		do
		{
			if (i == 0)
			{
				cout << "please choose home team: " << endl;
			}
			else
			{
				cout << "please choose away team: " << endl;
			}
			cin >> choise;
		} while (choise > 0 && choise < numOfTeams);
		if (i == 0)
			teamA = new Team(teams[choise]);//copy c'tor
		else
			teamB = new Team(teams[choise]);//copy c'tor

		do
		{
			cout << "please choose team result - must be positive number: " << endl;
			cin >> result;
		} while (result > 0);
		if (i == 0)
			resultA = result;
		else
			resultB = result;
	}
	//need to add refree
	//need to add date
	return nullptr; /*new Match(*ref, *teamA, *teamB, *date);*/
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
	cout << message << endl;
	cin >> num;
	getchar();
	return num;
}

float getFloatWithPrompt(const char* message)
{
	float num;
	cout << message << endl;
	cin >> num;
	return num;
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