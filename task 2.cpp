#include <iostream>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    int count = 1;
    for (int i = 0; i < input.length(); i++) {
        if (isOperator(input[i])) {
            cout << "operator" << count << ": " << input[i] << endl;
            count++;
        }
    }

    return 0;
}
