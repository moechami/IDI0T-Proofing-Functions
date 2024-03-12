#include <iostream>
#include <cctype>
#include <string>
#include <limits>

using namespace std;

unsigned int getUnsignedValue(const string& message = "Please enter an unsigned integer: ");
bool getUnsignedValue(unsigned int& value, int n = 5, const string& message = "Please enter an unsigned integer: ");
unsigned int getUnsignedValue(bool useMin, unsigned int limit, const string& message = "Please enter an unsigned integer: ");
bool getUnsignedValue(unsigned int& value, bool useMin, unsigned int limit, int n = 5, const string& message = "Please enter an unsigned integer: ");
unsigned int getUnsignedValue(unsigned int minValue, unsigned int maxValue, bool withinRange, const string& message = "Please enter an unsigned integer: ");
bool getUnsignedValue(unsigned int& value, unsigned int minValue, unsigned int maxValue, bool withinRange, int n = 5, const string& message = "Please enter an unsigned integer: ");

int main() {

    // Test for simple unsigned int input
    cout << "Test for simple unsigned int input:" << endl;
    unsigned int simpleValue = getUnsignedValue();
    cout << "Entered unsigned integer: " << simpleValue << endl << endl;

    // Test for unsigned int input with limited attempts
    unsigned int limitedValue;
    if (getUnsignedValue(limitedValue, 3)) {
        cout << "Entered unsigned integer within 3 attempts: " << limitedValue << endl;
    } else {
        cout << "Failed to enter a valid unsigned integer within 3 attempts." << endl;
    }
    cout << endl;

    // Test for unsigned int input with a minimum value constraint
    cout << "Test for unsigned int input with a minimum value constraint:" << endl;
    unsigned int minValue = getUnsignedValue(true, 1000);
    cout << "Entered unsigned integer (min 1000): " << minValue << endl << endl;

    // Test for unsigned int input with a maximum value constraint and limited attempts
    unsigned int maxValue;
    if (getUnsignedValue(maxValue, false, 20000, 3)) {
        cout << "Entered unsigned integer (max 20000) within attempts: " << maxValue << endl;
    } else {
        cout << "Failed to enter a valid unsigned integer within attempts." << endl;
    }
    cout << endl;

    // Test for unsigned int input within a specific range
    cout << "Test for unsigned int input within a specific range:" << endl;
    unsigned int withinRangeValue = getUnsignedValue(5000, 10000, true);
    cout << "Entered unsigned integer (between 5000 and 10000): " << withinRangeValue << endl << endl;

    // Test for unsigned int input outside a specific range with limited attempts
    unsigned int outsideRangeValue;
    if (getUnsignedValue(outsideRangeValue, 3000, 7000, false, 3)) {
        cout << "Entered unsigned integer (outside 3000 and 7000) within attempts: " << outsideRangeValue << endl;
    } else {
        cout << "Failed to enter a valid unsigned integer within attempts." << endl;
    }

    return 0;
}

unsigned int getUnsignedValue(const string& message) {

    unsigned int value;

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

bool getUnsignedValue(unsigned int& value, int n, const string& message) {

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

unsigned int getUnsignedValue(bool useMin, unsigned int limit, const string& message) {

    unsigned int value;

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

bool getUnsignedValue(unsigned int& value, bool useMin, unsigned int limit, int n, const string& message) {

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

unsigned int getUnsignedValue(unsigned int minValue, unsigned int maxValue, bool withinRange, const string& message) {

    unsigned int value;

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

bool getUnsignedValue(unsigned int& value, unsigned int minValue, unsigned int maxValue, bool withinRange, int n, const string& message) {

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
