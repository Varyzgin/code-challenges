#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.find('R') < s.find('M')) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
