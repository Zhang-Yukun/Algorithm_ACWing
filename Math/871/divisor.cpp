#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
int n, t;
long long res = 1, p, s;
unordered_map<int, int> primes;

void find_primes(int n);

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        find_primes(t);
    }
    for (pair<int, int> prime: primes) {
        p = prime.first, s = 1;
        for (int i = 0; i < prime.second; i++) s = (s * p + 1) % MOD;
        res = (res * s) % MOD;
    }
    printf("%lld", res);
    return 0;
}

void find_primes(int n) {
    for (int i = 2; i <= n / i; i++) {
        while (!(n % i)) primes[i]++, n /= i;
    }
    if (n > 1) primes[n]++;
}