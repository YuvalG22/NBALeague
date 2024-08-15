#include <string>
#include <iostream>
#include <limits>
using namespace std;

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