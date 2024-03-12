#include <iostream>
#include <limits>
#include <string>

using namespace std;

int getIntValue(const string& message = "Please enter an integer: ");
bool getIntValue(int& value, int n = 5, const string& message = "Please enter an integer: ");
int getIntValue(bool useMin, int limit, const string& message = "Please enter an integer: ");
bool getIntValue(int& value, bool useMin, int limit, int n = 5, const string& message = "Please enter an integer: ");
int getIntValue(int minValue, int maxValue, bool withinRange, const string& message = "Please enter an integer: ");
bool getIntValue(int& value, int minValue, int maxValue, bool withinRange, int n = 5, const string& message = "Please enter an integer: ");

int main() {

    cout << "Part 1 Test" << endl;
    int part1Value = getIntValue();
    cout << "You entered: " << part1Value << endl << endl;

    cout << "Part 2 Test:" << endl;
    int part2Value;

    if (getIntValue(part2Value, 3)) {
        cout << "You entered: " << part2Value << endl;

    } else {
        cout << "Failed to enter a valid integer in 3 attempts." << endl;
    }
    cout << endl;

    cout << "Part 3 Test for minimum value:" << endl;
    int part3MinValue = getIntValue(true, 10);
    cout << "You entered (min 10): " << part3MinValue << endl << endl;

    cout << "Part 3 Test for maximum value:" << endl;
    int part3MaxValue;

    if (getIntValue(part3MaxValue, false, 20, 3)) {
        cout << "You entered (max 20): " << part3MaxValue << endl;

    } else {
        cout << "Failed to enter a valid integer in 3 attempts." << endl;
    }
    cout << endl;

    cout << "Part 4 Test for within range:" << endl;
    int part4WithinRange = getIntValue(10, 20, true);

    cout << "You entered (between 10 and 20): " << part4WithinRange << endl << endl;

    cout << "Part 4 Test for outside range:" << endl;
    int part4OutsideRange;

    if (getIntValue(part4OutsideRange, 5, 15, false, 3)) {
        cout << "You entered (outside 5 and 15): " << part4OutsideRange << endl;

    } else {
        cout << "Failed to enter a valid integer in 3 attempts." << endl;
    }

    return 0;
}

int getIntValue(const string& message) {
    int value;

    while (true) {

        cout << message;
        cin >> value;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;

        } else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getIntValue(int& value, int n, const string& message) {
    while (n-- > 0) {

        cout << message;
        cin >> value;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;

        } else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}

int getIntValue(bool useMin, int limit, const string& message) {
    int value;

    while (true) {
        cout << message;
        cin >> value;

        if (!cin.fail() && ((useMin && value >= limit) || (!useMin && value <= limit))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;

        } else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getIntValue(int& value, bool useMin, int limit, int n, const string& message) {

    while (n-- > 0) {
        cout << message;
        cin >> value;
        if (!cin.fail() && ((useMin && value >= limit) || (!useMin && value <= limit))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        } else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}

int getIntValue(int minValue, int maxValue, bool withinRange, const string& message) {
    int value;

    while (true) {
        cout << message;
        cin >> value;

        if (!cin.fail() && ((withinRange && value >= minValue && value <= maxValue) || 
            (!withinRange && (value < minValue || value > maxValue)))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;

        } else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getIntValue(int& value, int minValue, int maxValue, bool withinRange, int n, const string& message) {

    while (n-- > 0) {
        cout << message;
        cin >> value;

        if (!cin.fail() && ((withinRange && value >= minValue && value <= maxValue) || 
            (!withinRange && (value < minValue || value > maxValue)))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;

        } else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}
