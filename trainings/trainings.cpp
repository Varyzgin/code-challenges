#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    if (a[0] > a[1]) {
        return 1;
    }
    
    std::vector<int> adjustments;
    for (int i = 2; i < n; ++i) {
        if (a[i] < a[0]) {
            adjustments.push_back(a[0] - a[i]);
        } else if (a[i] > a[1]) {
            adjustments.push_back(a[i] - a[1]);
        } else {
            adjustments.push_back(0);
        }
    }

    sort(adjustments.begin(), adjustments.end());

    long long result = 0;
    for (int i = 0; i < m; ++i) {
        result += adjustments[i];
    }

    std::cout << result << std::endl;

    return 0;
}
