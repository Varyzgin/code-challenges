#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <tuple>

std::pair<double, double> calculateHoughParameters(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double theta = atan2(dy, dx);
    double r = x1 * cos(theta) + y1 * sin(theta);
    return {r, theta};
}

int main() {
    int n;
    std::cin >> n;
    // n = 7;

    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    std::map<std::pair<double, double>, std::set<int>> lines;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [r, theta] = calculateHoughParameters(points[i].first, points[i].second,
                                                       points[j].first, points[j].second);
            r = round(r * 1e9) / 1e9;
            theta = round(theta * 1e9) / 1e9;
            lines[{r, theta}].insert(i);
            lines[{r, theta}].insert(j);
        }
    }

    int maxCollinear = 0;
    for (const auto& [line, indices] : lines) {
        maxCollinear = std::max(maxCollinear, (int)indices.size());
    }

    if (maxCollinear > 2 * n / 3) {
        int freePoints = n - maxCollinear;
        std::cout << freePoints << std::endl; 
    } else {
        int count = n / 3;
        std::cout << count << std::endl; 
    }

    return 0;
}
