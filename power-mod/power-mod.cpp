#include <iostream>
#include <vector>
#include <cstdint>

const int MOD = 998244353;

int BinPow(int a, std::int64_t b, int c) {
    if (c == 1) {
        return 0;
    }
    int result = 1;
    a %= c;
    while (b > 0) {
        if (b & 1) {
            result = static_cast<int>((1LL * result * a) % c);
        }
        a = static_cast<int>((1LL * a * a) % c);
        b >>= 1;
    }
    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    // n = 200000;
    // k = 300;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        // a[i] = 100000000;
    }

    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        total_sum = (total_sum + a[i]) % MOD;
    }

    for (int p = 1; p <= k; ++p) {
        long long result = 0;
        long long power_sum = 0;

        for (int i = 0; i < n; ++i) {
            power_sum = (power_sum + a[i]) % MOD;
            long long pair_sum = (total_sum - a[i] + MOD) % MOD;
            result = (result + BinPow(pair_sum, p, MOD)) % MOD;
        }

        std::cout << result << std::endl;
    }

    return 0;
}
