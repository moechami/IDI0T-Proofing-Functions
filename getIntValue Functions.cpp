#include <iostream>
#include <string>
#include <limits>
#include <climits>

using namespace std;

int getIntValue(const string& message = "Please Enter an Integer: ");
int getIntValue(int minValue, int maxValue, const string& message = "Please Enter an Integer: ");
bool getIntValue(int& enteredValue, const string& message = "Please Enter an Integer: ", int attempts = 5);
bool getIntValue(int& enteredValue, int minValue, int maxValue, int attempts, const string& message = "Please Enter an Integer: ");

int main() {

    // Test simple input with message
    cout << "Testing simple input with message" << endl;
    int value1 = getIntValue("Enter any integer:");
    cout << "You entered: " << value1 << endl << endl;

    // Test input with validation range
    cout << "Testing input with validation range:" << endl;
    int value2 = getIntValue(10, 20, "Enter an integer between 10 and 20:");
    cout << "You entered: " << value2 << endl << endl;

    // Test function with retry limit
    cout << "Testing function with retry limit:" << endl;
    int value3;
    bool success3 = getIntValue(value3, "Enter any integer (you have 3 attempts):", 3);
    if (success3) {
        cout << "You successfully entered: " << value3 << endl;
    } else {
        cout << "Failed to enter a valid integer after 3 attempts." << endl;
    }
    cout << endl;

    // Test input with validation range and retry limit
    cout << "Testing input with validation range and retry limit:" << endl;
    int value4;
    bool success4 = getIntValue(value4, 30, 40, 3, "Enter an integer between 30 and 40 (you have 3 attempts):");
    if (success4) {
        cout << "You successfully entered: " << value4 << endl;
    } else {
        cout << "Failed to enter a valid integer in the range 30-40 after 3 attempts." << endl;
    }

    return 0;
}

// Simple input with message
int getIntValue(const string& message) {
    int inputValue;

    while (true) {

        cout << message << endl;
        cin >> inputValue;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return inputValue;

        } else {
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Input with validation range, uses default parameters to fit the overloaded pattern
int getIntValue(int minValue, int maxValue, const string& message) {
    int inputValue;

    do {
        cout << message << endl;
        cin >> inputValue;

        if (!cin.fail() && inputValue >= minValue && inputValue <= maxValue) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return inputValue;

        } else {

            cout << "Input must be between " << minValue << " and " << maxValue << ". Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);

}

// Function to try getting an integer from the user within optional retry limit
bool getIntValue(int& enteredValue, const string& message, int attempts) {

    while (attempts > 0) {
        cout << message << endl;
        cin >> enteredValue;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;

        } else {
            cout << "Invalid input. Attempts remaining: " << --attempts << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}

// Input with validation range and retry limit
bool getIntValue(int& enteredValue, int minValue, int maxValue, int attempts, const string& message) {

    while (attempts > 0) {

        cout << message << endl;
        cin >> enteredValue;

        if (!cin.fail() && enteredValue >= minValue && enteredValue <= maxValue) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;

        } else {
            cout << "Input must be between " << minValue << " and " << maxValue << ". Attempts remaining: " << --attempts << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return false;
}
