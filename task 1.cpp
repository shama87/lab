#include <iostream>
using namespace std;

bool isNum() {
    string c;
    cin >> c;

    for (int i = 0; i < c.length(); i++) {
        if (c[i] >= '48' && c[i] <= '59') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    cout << boolalpha << isNum();
    return 0;
}
