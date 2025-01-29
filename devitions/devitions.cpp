#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// Функция для вычисления остатка до кратности числа
long long ToMakeDivisible(long long num, long long divisor) {
    return (divisor - num % divisor) % divisor;
}

// Основная функция для нахождения минимальных операций
long long MinOperations(vector<long long>& a, long long x, long long y, long long z) {
    // Сортируем делители по убыванию
    vector<tuple<long long, char>> divisors = {{x, 'x'}, {y, 'y'}, {z, 'z'}};
    sort(divisors.rbegin(), divisors.rend()); // Сортируем по убыванию

    x = get<0>(divisors[0]);
    y = get<0>(divisors[1]);
    z = get<0>(divisors[2]);

    // Храним минимальное количество операций
    long long min_operations = LLONG_MAX;

    // Пробуем все возможные комбинации
    for (size_t i = 0; i < a.size(); ++i) {
        // Покрытие первого делителя
        long long ops_x = ToMakeDivisible(a[i], x);

        for (size_t j = 0; j < a.size(); ++j) {
            long long ops_y = LLONG_MAX;
            if (j != i) {
                ops_y = ToMakeDivisible(a[j], y);
            }

            for (size_t k = 0; k < a.size(); ++k) {
                long long ops_z = LLONG_MAX;
                if (k != i && k != j) {
                    ops_z = ToMakeDivisible(a[k], z);
                }

                // Считаем общее число операций
                min_operations = min(min_operations, ops_x + ops_y + ops_z);
            }
        }
    }

    return min_operations;
}

int main() {
    long long n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << MinOperations(a, x, y, z) << endl;
    return 0;
}
