#include <iostream>
#include <string>
using namespace std;

bool isComment(string input) {

    if (input.substr(0, 2) == "//") {
        return true;
    }
    if (input.substr(0, 2) == "/*" && input.substr(input.length() - 2) == "*/") {
        return true;
    }

    return false;
}

int main() {
    string input;
    cout << "Enter a line: ";
    getline(cin, input);

    if (isComment(input)) {
        cout << "This is a comment line." << endl;
    } else {
        cout << "This is NOT a comment line." << endl;
    }

    return 0;
}
