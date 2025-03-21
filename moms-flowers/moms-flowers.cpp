#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // для работы со временем

int main() {
    std::vector<long long> powersOfTwo;
    for (int i = 0; i < 60; ++i) {
        powersOfTwo.push_back(1LL << i);
    }

    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
// auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        long long budget = a[i];
        std::vector<long long> selected;
        
        for (int j = 59; j >= 0; --j) {
            if (powersOfTwo[j] <= budget) {
                budget -= powersOfTwo[j];
                selected.push_back(powersOfTwo[j]);
                if (selected.size() == 3) {
                    break;
                }
            }
        }

        if (selected.size() < 3) {
            std::cout << -1 << std::endl;
        } else {
            long long sum = selected[0] + selected[1] + selected[2];
            std::cout << sum << std::endl;
        }
    }
//  auto end = std::chrono::high_resolution_clock::now();

//     // Вычисляем разницу между начальным и конечным временем
//     auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

//     // Выводим время выполнения в микросекундах
//     std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;
    return 0;
}
