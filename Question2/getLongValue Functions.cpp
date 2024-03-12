#include <iostream>
#include <string>
#include <limits>
#include <climits>

using namespace std;

long getLongValue(const string& message = "Please enter a long integer: ");
bool getLongValue(long& value, int n = 5, const string& message = "Please enter a long integer: ");
long getLongValue(bool useMin, long limit, const string& message = "Please enter a long integer: ");
bool getLongValue(long& value, bool useMin, long limit, int n = 5, const string& message = "Please enter a long integer: ");
long getLongValue(long minValue, long maxValue, bool withinRange, const string& message = "Please enter a long integer: ");
bool getLongValue(long& value, long minValue, long maxValue, bool withinRange, int n = 5, const string& message = "Please enter a long integer: ");

int main() {

    // Test for simple long input
    cout << "Test for simple long input:" << endl;
    long simpleLong = getLongValue();
    cout << "Entered value: " << simpleLong << endl << endl;

    // Test for long input with limited attempts
    long limitedAttemptsLong;
    if (getLongValue(limitedAttemptsLong, 3)) {
        cout << "Entered value within 3 attempts: " << limitedAttemptsLong << endl;
    } else {
        cout << "Failed to enter a valid long integer within 3 attempts." << endl;
    }
    cout << endl;

    // Test for long input with a minimum value constraint
    cout << "Test for long input with a minimum value constraint:" << endl;
    long minConstrainedLong = getLongValue(true, 1000L);
    cout << "Entered value (min 1000): " << minConstrainedLong << endl << endl;

    long maxConstrainedLong;
    if (getLongValue(maxConstrainedLong, false, 10000L, 3)) {
        cout << "Entered value (max 10000) within attempts: " << maxConstrainedLong << endl;
    } else {
        cout << "Failed to enter a valid long integer within attempts." << endl;
    }
    cout << endl;

    // Test for long input within a specific range
    cout << "Test for long input within a specific range:" << endl;
    long rangeConstrainedLong = getLongValue(2000L, 5000L, true);
    cout << "Entered value (between 2000 and 5000): " << rangeConstrainedLong << endl << endl;

    // Test for long input outside a specific range with limited attempts
    long outsideRangeLong;
    if (getLongValue(outsideRangeLong, 1500L, 2500L, false, 3)) {
        cout << "Entered value (outside 1500 and 2500) within attempts: " << outsideRangeLong << endl;
    } else {
        cout << "Failed to enter a valid long integer within attempts." << endl;
    }
    return 0;
}

long getLongValue(const string& message) {

    long value;

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

bool getLongValue(long& value, int n, const string& message) {

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

long getLongValue(bool useMin, long limit, const string& message) {
    long value;

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

bool getLongValue(long& value, bool useMin, long limit, int n, const string& message) {
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

long getLongValue(long minValue, long maxValue, bool withinRange, const string& message) {
    long value;

    while (true) {
        cout << message;
        cin >> value;

        if (!cin.fail() && ((withinRange && value >= minValue && value <= maxValue) || (!withinRange && (value < minValue || value > maxValue)))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getLongValue(long& value, long minValue, long maxValue, bool withinRange, int n, const string& message) {
    while (n-- > 0) {
        cout << message;
        cin >> value;
        if (!cin.fail() && ((withinRange && value >= minValue && value <= maxValue) || (!withinRange && (value < minValue || value > maxValue)))) {
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


