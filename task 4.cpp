#include <iostream>
#include <string>
using namespace std;

bool isIdentifier(string input) {

    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
          input[0] == '_')) {
        return false;
    }
    for (int i = 1; i < input.length(); i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              input[i] == '_')) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isIdentifier(input)) {
        cout << "This is a valid identifier." << endl;
    } else {
        cout << "This is NOT a valid identifier." << endl;
    }

    return 0;
}
