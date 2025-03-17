#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    if (s.find('R') < s.find('M')) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
