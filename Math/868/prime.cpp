#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, cnt, primes[N];
bool st[N];

int find_primes(int n);

int main() {
    scanf("%d", &n);
    printf("%d", find_primes(n));
    return 0;
}

int find_primes(int n) {
    cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (!(i % primes[j])) break;
        }
    }
    return cnt;
}