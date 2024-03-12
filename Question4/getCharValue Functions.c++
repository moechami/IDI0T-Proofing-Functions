#include <iostream>
#include <cctype>
#include <string>
#include <limits>

using namespace std;

char getCharValue(const string& message = "Please enter a character: ");
bool getCharValue(char& value, int n = 5, const string& message = "Please enter a character: ");
char getCharValue(bool useLower, const string& message = "Please enter a character: ");
bool getCharValue(char& value, bool useLower, int n = 5, const string& message = "Please enter a character: ");
char getCharValue(char minValue, char maxValue, bool withinRange, const string& message = "Please enter a character: ");
bool getCharValue(char& value, char minValue, char maxValue, bool withinRange, int n = 5, const string& message = "Please enter a character: ");

int main() {

    cout << "Test for simple char input" << endl;
    char simpleChar = getCharValue();
    cout << "Entered character: " << simpleChar << endl << endl;

    cout << "Test for char input with limited attempts:" << endl;
    char limitedAttemptsChar;
    if (getCharValue(limitedAttemptsChar, 3)) {
        cout << "Entered character within 3 attempts: " << limitedAttemptsChar << endl;
    } else {
        cout << "Failed to enter a valid character within 3 attempts." << endl;
    }
    cout << endl;

    cout << "Test for lowercase char input:" << endl;
    char lowercaseChar = getCharValue(true);
    cout << "Entered lowercase character: " << lowercaseChar << endl << endl;

    cout << "Test for uppercase char input with limited attempts:" << endl;
    char uppercaseChar;
    if (getCharValue(uppercaseChar, false, 3)) {
        cout << "Entered uppercase character within attempts: " << uppercaseChar << endl;
    } else {
        cout << "Failed to enter a valid character within attempts." << endl;
    }
    cout << endl;

    cout << "Test for char input within a specific range:" << endl;
    char rangeChar = getCharValue('a', 'f', true);
    cout << "Entered character (between a and f): " << rangeChar << endl << endl;

    cout << "Test for char input outside a specific range with limited attempts:" << endl;
    char outsideRangeChar;
    if (getCharValue(outsideRangeChar, 'k', 'n', false, 3)) {
        cout << "Entered character (outside k and n) within attempts: " << outsideRangeChar << endl;
    } else {
        cout << "Failed to enter a valid character within attempts." << endl;
    }

    return 0;
}

char getCharValue(const string& message) {
    char value;
    while (true) {
        cout << message;
        cin >> value;
        if (!cin.fail() && isalpha(value)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter an alphabetic character." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getCharValue(char& value, int n, const string& message) {
    while (n-- > 0) {
        cout << message;
        cin >> value;
        if (!cin.fail() && isalpha(value)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        } else {
            cout << "Invalid input. Please enter an alphabetic character." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}

char getCharValue(bool useLower, const string& message) {
    char value;
    while (true) {
        cout << message;
        cin >> value;
        if (!cin.fail() && isalpha(value) && ((useLower && islower(value)) || (!useLower && isupper(value)))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter an alphabetic character." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getCharValue(char& value, bool useLower, int n, const string& message) {
    while (n-- > 0) {
        cout << message;
        cin >> value;
        if (!cin.fail() && isalpha(value) && ((useLower && islower(value)) || (!useLower && isupper(value)))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        } else {
            cout << "Invalid input. Please enter an alphabetic character." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}

char getCharValue(char minValue, char maxValue, bool withinRange, const string& message) {
    char value;
    while (true) {
        cout << message;
        cin >> value;
        if (!cin.fail() && isalpha(value) && ((withinRange && value >= minValue && value <= maxValue) ||
            (!withinRange && (value < minValue || value > maxValue)))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please enter an alphabetic character." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getCharValue(char& value, char minValue, char maxValue, bool withinRange, int n, const string& message) {
    while (n-- > 0) {
        cout << message;
        cin >> value;
        if (!cin.fail() && isalpha(value) && ((withinRange && value >= minValue && value <= maxValue) ||
            (!withinRange && (value < minValue || value > maxValue)))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        } else {
            cout << "Invalid input. Please enter an alphabetic character." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}
