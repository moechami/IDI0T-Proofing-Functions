#include <iostream>
#include <string>
#include <climits>

using namespace std;

int getIntValue (const string& message = "Please Enter an Integer: ") {

    int inputValue;

    while (true) {

        cout << message << endl;
        cin >> inputValue;

        if (!cin.fail()) {

            break;
        } else {
            cin.clear();
            cin.ignore(10000);
        }
    }
 
    return inputValue;

}

bool getIntValue (int& enteredValue, const string& message = "Please Enter an Integer: ", int n = 5) {

    int attempts = 0;

    while (attempts <= n) {
        cout << message << endl;
        cin >> enteredValue;

        if (!cin.fail()) {
            
            return true;
        } else {
            cin.clear();
            cin.ignore(10000);
            attempts++;
        }
    }

    return false;
}

int getIntValue(const string& message = "Please Enter an Integer: ", int minVal = INT_MIN, int maxVal = INT_MAX);
bool getIntValue(int& enteredValue, const string& message = "Please Enter an Integer: ", int n = 5, int minVal = INT_MIN, int maxVal = INT_MAX);
