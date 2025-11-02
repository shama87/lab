#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>
using namespace std;
bool isNum(const string& input) {
    if (input.empty()) {
        return false;
    }
    for (char c : input) {

        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}
bool isComment(const string& input) {
    if (input.length() >= 2 && input.substr(0, 2) == "//") {
        return true;
    }
    if (input.length() >= 4 && input.substr(0, 2) == "/*" && input.substr(input.length() - 2) == "*/") {
        return true;
    }
    return false;
}
bool isIdentifier(const string& input) {
    if (input.empty()) {
        return false;
    }

    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
          input[0] == '_')) {
        return false;
    }

    for (size_t i = 1; i < input.length(); i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              input[i] == '_')) {
            return false;
        }
    }
    return true;
}
void findMinMax(const vector<int>& arr, int& minVal, int& maxVal) {
    int size = arr.size();
    if (size == 0) {
        minVal = 0;
        maxVal = 0;
        cerr << "Error: Array is empty." << endl;
        return;
    }

    minVal = numeric_limits<int>::max();
    maxVal = numeric_limits<int>::min();

    for (int val : arr) {
        if (val < minVal) {
            minVal = val;
        }
        if (val > maxVal) {
            maxVal = val;
        }
    }
}

    string createDisplayName(const string& partA, const string& partB) {
    string assembledName = partA + " " + partB;
    return assembledName;
}

void runTask1() {
    string input;
    cout << "\n--- Task 1: Check if string is a number (only digits) ---\n";
    cout << "Enter a string: ";
    cin >> input;
    cout << boolalpha << "Result: " << isNum(input) << endl;
}

void runTask2() {
    string input;
    cout << "\n--- Task 2: Find all operators in an expression ---\n";
    cout << "Enter an expression (no spaces, e.g., a+b*c=d/2): ";
    cin >> input;

    int count = 1;
    for (char ch : input) {
        if (isOperator(ch)) {
            cout << "operator" << count << ": " << ch << endl;
            count++;
        }
    }
    if (count == 1) {
        cout << "No operators found." << endl;
    }
}

void runTask3() {
    string input;
    cout << "\n--- Task 3: Check if line is a C++ comment (// or /**/) ---\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter a line: ";
    getline(cin, input);

    if (isComment(input)) {
        cout << "This is a comment line." << endl;
    } else {
        cout << "This is NOT a comment line." << endl;
    }
}

void runTask4() {
    string input;
    cout << "\n Task 4: Check if string is a valid C++ identifier ---\n";
    cout << "Enter a string: ";
    cin >> input;

    if (isIdentifier(input)) {
        cout << "This is a valid identifier." << endl;
    } else {
        cout << "This is NOT a valid identifier." << endl;
    }
}

void runTask5() {
    cout << "\n Task 5: Calculate Average of N elements ---\n";
    int n;
    cout << "Enter the number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of elements." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    vector<int> arr(n);
    long long sum = 0;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double average = (double)sum / n;
    cout << fixed << setprecision(2);
    cout << "Average value: " << average << endl;
}

void runTask6() {
    cout << "\n Task 6: Find Min and Max in an Array ---\n";
    vector<int> data = {40, 17, 86, -5, -97, 10, 51};

    int minimum, maximum;
    findMinMax(data, minimum, maximum);

    if (!data.empty()) {
        cout << "The array elements are: ";
        for (size_t i = 0; i < data.size(); ++i) {
            cout << data[i] << (i == data.size() - 1 ? "" : ", ");
        }
        cout << "\n" << endl;
        cout << "Minimum value found: " << minimum << endl;
        cout << "Maximum value found: " << maximum << endl;
    }
}

void runTask7() {
    cout << "\n Task 7: Create Full Name from two strings ---\n";
    const string userFirstName = "Shama";
    const string userLastName = "Zerin";

    cout << "First Name: " << userFirstName << endl;
    cout << "Last Name: " << userLastName << endl;

    string completedName = createDisplayName(userFirstName, userLastName);

    cout << "\nFinal Full Name: " << completedName << endl;
}
int main() {
    int choice;
    do {
        cout << "\n\n";
        cout << "          C++ Combined Tasks Menu       \n";
        cout << "\n";
        cout << "1. Check if string is a number (Task 1)\n";
        cout << "2. Find operators in an expression (Task 2)\n";
        cout << "3. Check if line is a C++ comment (Task 3)\n";
        cout << "4. Check if string is a valid identifier (Task 4)\n";
        cout << "5. Calculate Average of N elements (Task 5)\n";
        cout << "6. Find Min and Max in an array (Task 6)\n";
        cout << "7. Create Full Name (Task 7)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                runTask1();
                break;
            case 2:
                runTask2();
                break;
            case 3:
                runTask3();
                break;
            case 4:
                runTask4();
                break;
            case 5:
                runTask5();
                break;
            case 6:
                runTask6();
                break;
            case 7:
                runTask7();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 7.\n";
        }
    } while (choice != 0);

    return 0;
}
