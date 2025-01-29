#include <iostream>
#include <vector>

int main() {
    size_t n;
    long long s;
    std::cin >> n >> s;
    // n = 7;
    // s = 5;

    std::vector<long long> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    // a = {5, 2, 1, 5, 1, 2, 2, 4};
    // a = {5, 1, 5, 1, 5, 1, 5};
    // a = {5, 1, 5, 1, 2, 2, 4};

    long long prev = 0;
    long long current_sum = a[0];
    long long total = 1;
    long long total_pre = 0;

    for (int i = 1; i < n; ++i) {
        current_sum += a[i];

        prev = total - total_pre;
        total_pre = total;
        total += prev;
        if (current_sum > s) {
            total += (i + 1);
            current_sum = a[i];
        } else {
            total += 1;
        }
        // std::cout << "Total: " << total << std::endl;
    }
    std::cout << total << std::endl;
}
