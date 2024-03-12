#include <iostream>
#include <cctype>
#include <string>
#include <limits>

using namespace std;

double getDoubleValue(const string& message = "Please enter a double value: ");
bool getDoubleValue(double& value, int n = 5, const string& message = "Please enter a double value: ");
double getDoubleValue(bool useMin, double limit, const string& message = "Please enter a double value: ");
bool getDoubleValue(double& value, bool useMin, double limit, int n = 5, const string& message = "Please enter a double value: ");
double getDoubleValue(double minValue, double maxValue, bool withinRange, const string& message = "Please enter a double value: ");
bool getDoubleValue(double& value, double minValue, double maxValue, bool withinRange, int n = 5, const string& message = "Please enter a double value: ");

int main() {

    // Test for simple double input
    cout << "Test for simple double input" << endl;
    double simpleDouble = getDoubleValue();
    cout << "Entered value: " << simpleDouble << endl << endl;

    // Test for double input with limited attempts
    double limitedAttemptsDouble;
    if (getDoubleValue(limitedAttemptsDouble, 3)) {
        cout << "Entered value within 3 attempts: " << limitedAttemptsDouble << endl;
    } else {
        cout << "Failed to enter a valid double within 3 attempts." << endl;
    }
    cout << endl;

    // Test for double input with a minimum value constraint
    cout << "Test for double input with a minimum value constraint:" << endl;
    double minConstrainedDouble = getDoubleValue(true, 100.5);
    cout << "Entered value (min 100.5): " << minConstrainedDouble << endl << endl;

    // Test for double input with a maximum value constraint and limited attempts
    double maxConstrainedDouble;
    if (getDoubleValue(maxConstrainedDouble, false, 2000.75, 3)) {
        cout << "Entered value (max 2000.75) within attempts: " << maxConstrainedDouble << endl;
    } else {
        cout << "Failed to enter a valid double within attempts." << endl;
    }
    cout << endl;

    // Test for double input within a specific range
    cout << "Test for double input within a specific range:" << endl;
    double rangeConstrainedDouble = getDoubleValue(150.25, 250.75, true);
    cout << "Entered value (between 150.25 and 250.75): " << rangeConstrainedDouble << endl << endl;

    // Test for double input outside a specific range with limited attempts
    double outsideRangeDouble;
    if (getDoubleValue(outsideRangeDouble, 150.25, 250.75, false, 3)) {
        cout << "Entered value (outside 150.25 and 250.75) within attempts: " << outsideRangeDouble << endl;
    } else {
        cout << "Failed to enter a valid double within attempts." << endl;
    }

    return 0;
}

double getDoubleValue(const string& message) {
    double value;
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

bool getDoubleValue(double& value, int n, const string& message) {
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

double getDoubleValue(bool useMin, double limit, const string& message) {
    double value;
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

bool getDoubleValue(double& value, bool useMin, double limit, int n, const string& message) {
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

double getDoubleValue(double minValue, double maxValue, bool withinRange, const string& message) {
    double value;
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

bool getDoubleValue(double& value, double minValue, double maxValue, bool withinRange, int n, const string& message) {
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
