#include <iostream>
#include <string>
#include <limits>
#include <climits>

using namespace std;

float getFloatValue(const string& message = "Please enter a float number: ");
bool getFloatValue(float& value, int n = 5, const string& message = "Please enter a float number: ");
float getFloatValue(bool useMin, float limit, const string& message = "Please enter a float number: ");
bool getFloatValue(float& value, bool useMin, float limit, int n = 5, const string& message = "Please enter a float number: ");
float getFloatValue(float minValue, float maxValue, bool withinRange, const string& message = "Please enter a float number: ");
bool getFloatValue(float& value, float minValue, float maxValue, bool withinRange, int n = 5, const string& message = "Please enter a float number: ");

int main() {

    // Test for simple float input
    cout << "Test for simple float input:" << endl;
    float simpleFloat = getFloatValue();
    cout << "Entered value: " << simpleFloat << endl << endl;

    // Test for float input with limited attempts
    float limitedAttemptsFloat;
    if (getFloatValue(limitedAttemptsFloat, 3)) {
        cout << "Entered value within 3 attempts: " << limitedAttemptsFloat << endl;
    } else {
        cout << "Failed to enter a valid float number within 3 attempts." << endl;
    }
    cout << endl;

    // Test for float input with a minimum value constraint
    cout << "Test for float input with a minimum value constraint:" << endl;
    float minConstrainedFloat = getFloatValue(true, 100.5f);
    cout << "Entered value (min 100.5): " << minConstrainedFloat << endl << endl;

    // Test for float input with a maximum value constraint and limited attempts
    float maxConstrainedFloat;
    if (getFloatValue(maxConstrainedFloat, false, 1000.5f, 3)) {
        cout << "Entered value (max 1000.5) within attempts: " << maxConstrainedFloat << endl;
    } else {
        cout << "Failed to enter a valid float number within attempts." << endl;
    }
    cout << endl;

    // Test for float input within a specific range
    cout << "Test for float input within a specific range:" << endl;
    float rangeConstrainedFloat = getFloatValue(200.5f, 500.5f, true);
    cout << "Entered value (between 200.5 and 500.5): " << rangeConstrainedFloat << endl << endl;

    // Test for float input outside a specific range with limited attempts
    float outsideRangeFloat;
    if (getFloatValue(outsideRangeFloat, 150.5f, 250.5f, false, 3)) {
        cout << "Entered value (outside 150.5 and 250.5) within attempts: " << outsideRangeFloat << endl;
    } else {
        cout << "Failed to enter a valid float number within attempts." << endl;
    }

    return 0;
}

float getFloatValue(const string& message) {

    float value;

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

bool getFloatValue(float& value, int n, const string& message) {

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

float getFloatValue(bool useMin, float limit, const string& message) {

    float value;

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

bool getFloatValue(float& value, bool useMin, float limit, int n, const string& message) {

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

float getFloatValue(float minValue, float maxValue, bool withinRange, const string& message) {

    float value;

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

bool getFloatValue(float& value, float minValue, float maxValue, bool withinRange, int n, const string& message) {

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
